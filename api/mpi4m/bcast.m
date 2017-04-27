function [b, info] = bcast(b, sz_in, varargin) %#codegen
%BCAST Perform an MPI_Bcast from the root process with piggy-back.
%   [b, info] = bcast(b, sz, comm [, pgmsg [, pgmsg_size]])
% The last two modes supports piggy-back of small messages.
% If sz is empty or is 0, it is set to numel(b).
%
%See also allreduce, reduce

if isempty(varargin); info=int32(0); return; end

if ~isempty(varargin) && isstruct(varargin{1})
    coder.inline('never');
end

if isempty(sz_in); sz=int32(numel(b)); 
else sz = int32(sz_in); assert(sz<=numel(b)); end

if length(varargin)>1
    % Insert piggy-back message
    if length(varargin)>2
        s1 = sz + max(min(int32(varargin{3}),int32(numel(varargin{2}))),0);
    else
        s1 = sz + int32(numel(varargin{2}));
    end
    
    if ~isempty(varargin{1}) && mpi_Comm_rank(varargin{1})==0
        if s1>numel(b)
            m2c_error('bcast:bufferOverflow', ...
                'The given buffer is too small for the piggy-back message.');
        else
            % Copy the message into the buffer
            for i=sz+1:s1; b(i) = varargin{2}(i-sz); end
        end
    end
else
    s1 = int32(sz);
end

if ~isempty(varargin{1}) && mpi_Comm_size(varargin{1})>1
    b = m2c_unalias(b);
    info = mpi_Bcast(m2c_opaque_ptr_const(b), s1, MPI_Datatype(b), ...
        int32(0), MPI_Comm(varargin{1}));
else
    info = int32(0);
end

function test  %#ok<DEFNU>
%!test
%! comm = MPI_COMM_WORLD;
%! svar = rand(10,10);

%! rvar = svar;
%! [rvar, info] = bcast(rvar, numel(svar), comm);
%! assert(info==0);
%! assert(isequal(svar, rvar));

%!test
%! comm = MPI_COMM_WORLD;
%! svar = rand(100,1);
%!
%! rvar = [svar; 0];
%! [rvar, info] = bcast(rvar, 100, comm, realmax);
%! assert(info==0);
%! assert(isequal(svar, rvar(1:100)) && rvar(end)==realmax);
