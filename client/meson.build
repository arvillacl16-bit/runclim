project('Runclim', 'cpp', 'c', version : '1.0.0', default_options : ['cpp_std=c++20'])

wx_dep = dependency('wxWidgets', modules : ['core', 'base', 'net'])
eigen_dep = dependency('eigen3')
libnetcdf_dep = dependency('netcdf')

inc = include_directories('include', 'third-party')
sources = files('src/app.cpp', 'src/my_frame.cpp')

executable('runclim', sources, include_directories : inc, dependencies : [wx_dep, libnetcdf_dep])
