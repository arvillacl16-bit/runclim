project('Runclim', 'cpp', version : '1.0.0', default_options : ['cpp_std=c++20'])

wx_dep = dependency('wxwidgets', modules : ['core', 'base', 'net'])

executable('runclim', 'src/main.cpp', dependencies : wx_dep, win_subsystem : 'windows')
