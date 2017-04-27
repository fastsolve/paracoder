function [b, info] = allreduce(b, sz_in, op, varargin) %#codegen
%ALLREDUCE Perform an in-pace MPI_Allreduce (summation) with piggy-back.
%   [b, info] = allreduce(b, sz, op, comm)
% Reduce to all processes for sz elements in b. If sz is empty, 
% it will be set to numel(b). 
%
%   [b, info] = allreduce(b, sz, op, comm [, pgmsg [, pgmsg_size]])
% It allows piggy-back the message during reduction.
%
%See also reduce, bcast

if isempty(varargin); info=int32(0); return; end

if ~isempty(varargin) && isstruct(varargin{1})
    coder.inline('never');
end

if isempty(sz_in); sz=int32(numel(b));
else sz = int32(sz_in); assert(sz>=0 || sz<=numel(b)); end

if isempty(op); op = MPI_SUM; end

if length(varargin)>1
    % Insert piggy-back message
    if length(varargin)>2
        s1 = sz + max(min(int32(varargin{3}),int32(numel(varargin{2}))),0);
    else
        s1 = sz + int32(numel(varargin{2}));
    end
    if s1>numel(b)
        m2c_error('allreduce:bufferOverflow', ...
            'The given buffer is too small for the piggy-back message.');
    else
        % Copy the message into the buffer
        for i=sz+1:s1; b(i) = varargin{2}(i-sz); end
    end
else
    s1 = int32(sz);
end

if ~isempty(varargin{1}) && mpi_Comm_size(varargin{1})>1
    b = m2c_unalias(b);
    info = mpi_Allreduce(MPI_IN_PLACE, m2c_opaque_ptr(b), ...
        s1, MPI_Datatype(b), op, MPI_Comm(varargin{1}));
else
    info = int32(0);
end

function test  %#ok<DEFNU>
%!test
%! comm = MPI_COMM_WORLD;
%! svar = rand(10,10);

%! rvar = svar;
%! [rvar, info] = allreduce(rvar, [], comm);
%! assert(info==0);
%! assert(isequal(svar, rvar));
