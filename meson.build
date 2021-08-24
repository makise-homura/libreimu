project('libreimu', 'c', version: '0.1')

libfdt   = meson.get_compiler('c').find_library('fdt', required: false, has_headers: 'libfdt.h')
libdbus  = dependency('dbus-1', required: false)
libgpiod = dependency('libgpiod', required: false)

pkgconfig = import('pkgconfig')

reimu = library('reimu', 'reimu.c', version: meson.project_version(), install: true)
pkgconfig.generate(reimu)
libreimu = declare_dependency(include_directories: '.', link_with: reimu)

if libgpiod.found()
    reimu_gpio = library('reimu_gpio', 'reimu_gpio.c', version: meson.project_version(), install: true, dependencies: [libgpiod, libreimu])
    pkgconfig.generate(reimu_gpio)
    libreimu_gpio = declare_dependency(include_directories: '.', link_with: reimu_gpio)
endif

if libdbus.found()
    reimu_dbus = library('reimu_dbus', 'reimu_dbus.c', version: meson.project_version(), install: true, dependencies: [libdbus, libreimu])
    pkgconfig.generate(reimu_dbus)
    libreimu_dbus = declare_dependency(include_directories: '.', link_with: reimu_dbus)
endif

if libfdt.found()
    reimu_fdt = library('reimu_fdt', 'reimu_fdt.c', version: meson.project_version(), install: true, dependencies: [libfdt, libreimu])
    pkgconfig.generate(reimu_fdt)
    libreimu_fdt = declare_dependency(include_directories: '.', link_with: reimu_fdt)
endif

install_headers('reimu.h')