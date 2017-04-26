function m2c_begin_master %#codegen
%Marks the beginning of a master block.
%
% It specifies a region that is to be executed only by the master thread of
% the team/block. All other threads on the team/block skip this section.
%
% It must be paired with m2c_end_master.
