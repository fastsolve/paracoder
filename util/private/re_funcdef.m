function expr = re_funcdef(funcname)
expr = ['\w+\s+' funcname '\s*(\([^{}\)]+\))\s*{(?:([^}\n][^\n]*)?\n)*}'];
end
