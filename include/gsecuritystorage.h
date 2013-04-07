#ifndef _G_SECURITY_STORAGE_H_
#define _G_SECURITY_STORAGE_H_
#include "glib.h"
#include "gstream.h"

typedef void (*SECURITY_STORAGE_LOAD_FUNC)(GStream * stream, gpointer data);
typedef void (*SECURITY_STORAGE_SAVE_FUNC)(GStream * stream, gpointer data);

void g_security_storage_register(gstring name, SECURITY_STORAGE_LOAD_FUNC load, SECURITY_STORAGE_SAVE_FUNC save, gpointer data);
void g_security_storage_load(gstring name);
void g_security_storage_save(gstring name);

#endif