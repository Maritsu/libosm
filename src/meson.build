libosm_sources = [
  'sources.cpp',
  'filter.cpp',
  'listing.cpp',
  'libosm.cpp',
]

libosm_private_deps = [
  utfcpp_dep,
  cpr_dep,
]

libosm_public_deps = []

libosm = shared_library(
  meson.project_name().substring(3),
  libosm_sources,
  include_directories : global_include_dirs,
  dependencies : [
    libosm_private_deps,
    libosm_public_deps,
  ],
  soversion : meson.project_version().replace('.',''),
  version : meson.project_version(),
)
