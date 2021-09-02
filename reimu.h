#ifndef REIMU_H
#define REIMU_H

/* reimu_string */

int reimu_is_in_dict(const char *dict[], const char *name);
int reimu_get_conf_bool(const char *confbuf, int conflen, const char *needle);
long reimu_get_conf_long(const char *confbuf, int conflen, const char *needle);

/* reimu_control */

#include <stdio.h>
enum cancel_type_t { JUST_PRINT_ERROR = 0, CANCEL_ON_ERROR = 1, BE_SILENT = 2 };
void __attribute__((format(printf, 2, 3))) reimu_cancel(int num, const char *fmt, ...);
int __attribute__((format(printf, 3, 4))) reimu_cond_cancel(enum cancel_type_t cancel, int num, const char *fmt, ...);
void __attribute__((format(printf, 2, 3))) reimu_message(FILE *stream, const char *fmt, ...);
void reimu_set_atexit(int *already_done, void (*func)(void));

/* reimu_time */

char *reimu_gettime(void);
void reimu_msleep(long value, volatile int *exit_request);

/* reimu_dir */

int reimu_chkfile(const char *name);
int reimu_chkdir(const char *path);
int reimu_find_filename(int order, char *path, char **name);
int reimu_recurse_mkdir(char *path);

/* reimu_file */

int reimu_readfile(const char *name, char **p_buf, size_t *p_size);
int reimu_appendfile(const char *name, char **p_buf, size_t *p_size);
int reimu_writefile(const char *name, const void *buf, size_t size);
int reimu_find_in_file(const char *name, const char *needle);
int reimu_compare_file(const char *name, const char *needle);

/* reimu_textfile */

int reimu_textfile_create(const char *name);
int __attribute__((format(printf, 2, 3))) reimu_textfile_write(enum cancel_type_t cancel_on_error, const char *fmt, ...);
void reimu_textfile_close(void);

/* reimu_textfile_buf */

int reimu_textfile_buf_alloc(void);
int __attribute__((format(printf, 1, 2))) reimu_textfile_buf_append(const char *fmt, ...);
int reimu_textfile_buf_commit(const char *name);

/* reimu_gpio (requires libgpiod) */

int reimu_get_gpio_by_name(const char *name);
int reimu_set_gpio_by_name(const char *name, int val, int delay);

/* reimu_fdt (requires libfdt) */

typedef int (*traverse_callback_t)(enum cancel_type_t, const char *, int, int, int, const char *, const void *);
const void* __attribute__((format(printf, 6, 7))) reimu_getprop(enum cancel_type_t cancel_on_error, int node, const char *name, int mandatory, int failval, const char *fmt, ...);
int reimu_is_prop_empty(const char *prop);
int reimu_for_each_subnode(enum cancel_type_t cancel_on_error, int parent, traverse_callback_t callback, const void *data, int bus, int (*function)(enum cancel_type_t cancel_on_error, int node, const char *nodename, traverse_callback_t callback, const void *data, int bus));
int reimu_traverse_all_i2c(const void *data, traverse_callback_t function, enum cancel_type_t cancel_on_error);

/* reimu_dbus (requires libdbus-1) */

void reimu_dbus_manage_service(const char *service, const char *command);
int reimu_dbus_set_property_str(const char *service, const char *object, const char *interface, const char *property, const char *value);
int reimu_dbus_set_property_bool(const char *service, const char *object, const char *interface, const char *property, int value);
int reimu_dbus_get_property_bool(const char *service, const char *object, const char *interface, const char *property);
int reimu_dbus_call_method(const char *destination, const char *path, const char *iface, const char *method);

#endif