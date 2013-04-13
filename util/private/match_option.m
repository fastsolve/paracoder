function [matched, args] = match_option( args, opt)

opt = strrep( opt, '+', '\+');
matched = ~isempty( regexp( args, ['(\s|^)' opt '(\s|$)'], 'once'));

if matched;
    args = regexprep(args, ['(\s|^)' opt '(\s|$)'], '$2');
end
