project('libreimu', 'c')

libfdt   = meson.get_compiler('c').find_library('fdt', required: false, has_headers: 'libfdt.h')
libdbus  = dependency('dbus-1', required: false)
libgpiod = dependency('libgpiod', required: false)

pkgconfig = import('pkgconfig')

reimu = both_libraries('reimu', 'reimu.c', install: true)
pkgconfig.generate(reimu)

libreimu = declare_dependency(link_with: reimu)

if libgpiod.found()
    reimu_gpio = both_libraries('reimu_gpio', 'reimu_gpio.c', install: true, dependencies: [libgpiod, libreimu])
    pkgconfig.generate(reimu_gpio)
endif

if libdbus.found()
    reimu_dbus = both_libraries('reimu_dbus', 'reimu_dbus.c', install: true, dependencies: [libdbus, libreimu])
    pkgconfig.generate(reimu_dbus)
endif

if libfdt.found()
    reimu_fdt = both_libraries('reimu_fdt', 'reimu_fdt.c', install: true, dependencies: [libfdt, libreimu])
    pkgconfig.generate(reimu_fdt)
endif
