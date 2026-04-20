project('Runclim', 'cpp', version : '1.0.0', default_options : ['cpp_std=c++20'])

wx_dep = dependency('wxwidgets', modules : ['core', 'base', 'net'])
magick_dep = dependency('magick++')
eigen_dep = dependency('Eigen3')

inc = include_directories('include')
sources = files('src/app.cpp', 'src/my_frame.cpp')

executable('runclim', sources, include_directories : inc, dependencies : wx_dep, win_subsystem : 'windows')
