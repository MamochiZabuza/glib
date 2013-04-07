#ifndef __G_DB_H__
#define __G_DB_H__
#include "glib.h"

int 	g_db_init(char* db_name);
void	*g_db_get(const char *key);
void	*g_db_get_no_cache(const char *key);	
int		g_db_exists(const char *key);
int 	g_db_add(const char *key,const char *value);
void	g_db_remove(const char *key);
void 	g_db_destroy(void);
void	g_db_shrink(void);
gint	g_db_get_size(void);

#endif