function args = extract_codegen_args(nm)
fid = fopen (nm, 'rt');
args = '';
if (fid >= 0)
    began = false;
    while (~ feof (fid))
        tline = fgetl(fid); if ~ischar(tline), break, end
        ln = strtrim( tline);
        if length(ln)>5 && isequal( ln(1:2), '%#') && isequal( ln(end-2:end), '...')
            ln=ln(1:end-3);
        end
        if ~began
            if (length (ln) >= 9 && strcmp (ln(1:9), '%#codegen'))
                began = true;
                args = strtrim(ln(10:end));
            end
        elseif (length (ln) >= 9 && strcmp (ln(1:9), '%#codegen'))
            args = sprintf('%s %s', char(args), strtrim(ln(10:end)));
        elseif (length (ln) >= 2 && strcmp (ln(1:2), '%#'))
            args = sprintf('%s %s', char(args), strtrim(ln(3:end)));
        else
            break;
        end
    end
    fclose (fid);
end
end
