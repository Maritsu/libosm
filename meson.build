project(
  'libosm', 'cpp',
  version : '0.0.0',
  meson_version : '>=0.60.0',
  default_options : [
    'cpp_std=c++20',
    'warning_level=3',
    'default_library=shared',
  ],
  subproject_dir : 'submodules',
  license : 'GPL-3.0-or-later',
)

global_include_dirs = include_directories(
  'src',
)

# Project config
config_data = configuration_data()
config_data.set('VERSION', meson.project_version())

# UTFC++ subproject
# Abridged from a previous project:warning_level
cmake = import('cmake')
utfcpp_opts = cmake.subproject_options()
utfcpp_opts.add_cmake_defines({'UTF8_TESTS' : 'OFF'})
utfcpp_proj = cmake.subproject('utfcpp', options : utfcpp_opts)
utfcpp_dep = utfcpp_proj.dependency('utf8cpp')

# CPR subproject and curl dependency
curl_dep = dependency(
  'libcurl',
  disabler : true,
  not_found_message : 'libcurl not found. fetching along with cpr..',
)

cpr_opts = cmake.subproject_options()
if curl_dep.found()
  cpr_opts.add_cmake_defines({'CPR_USE_SYSTEM_CURL' : 'ON'})
endif
cpr_proj = cmake.subproject('cpr', options : cpr_opts)
cpr_dep = cpr_proj.dependency('cpr')

# Source directory
subdir('src')
