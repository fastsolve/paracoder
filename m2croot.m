function root = m2croot
% M2CROOT  Determine root directory of ParaCoder

persistent root__;

if isempty(root__)
    root__ = fileparts(which('load_m2c.m'));
    if contains(root__, ' ')
        root__ = ['''' root__ ''''];
    end
end

root = root__;
