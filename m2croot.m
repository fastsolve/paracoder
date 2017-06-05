function root = m2croot
% M2CROOT  Determine root directory of ParaCoder

persistent root__;

if isempty(root__)
    root__ = fileparts(which('load_m2c.m'));
end

root = root__;
