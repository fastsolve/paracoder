function expr = re_parregion
% The code fragment between begin_parallel/section/sections and 
% end_parallel/section/sections
expr = '((\n|#pragma [^{}][^\n]+\n|\s*[^#][^\n]+\n)+)';
end
