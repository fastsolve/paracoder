function [matched, args, list] = match_option(args, opt)

opt = strrep(opt, '+', '\+');
matched = ~isempty(regexp(args, ['(\s|^)' opt '(\s|$)'], 'once'));

switch opt
    case {'-time', '-api'}
        % Process the list of functions
        if matched
            % Find list of string
            pair = regexp(args, ['(\s|^)' opt '(\s*{[^}]*})(\s|$)'], 'match');
            args = regexprep(args, ['(\s|^)' opt '(\s*{[^}]*})?(\s|$)'], '$3');

            list = {};
            for i=1:length(pair)
                list = [list, eval(regexprep(pair{i}, ['(\s|^)' opt '(\s|$)'], '$2'))];
            end
        else
            list = {};
        end
    otherwise
        if matched
            args = regexprep(args, ['(\s|^)' opt '(\s|$)'], '$2');
        end
end
