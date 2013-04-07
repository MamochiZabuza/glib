#ifndef _G_AUTO_SCROLL_H_
#define _G_AUTO_SCROLL_H_
#include "glib.h"

typedef struct
{
	gint dummy;
} GAutoScroll;

typedef gboolean (*AUTO_SCROLL_FUNC)(gpointer data, gint dx, gint dy);

GAutoScroll * g_auto_scroll_new(AUTO_SCROLL_FUNC callback, gpointer data);
void g_auto_scroll_reset(GAutoScroll * self);
void g_auto_scroll_free(GAutoScroll * self);
void g_auto_scroll_stop(GAutoScroll * self);
void g_auto_scroll_add_point(GAutoScroll * self, gint x, gint y);
void g_auto_scroll_add_point_with_time(GAutoScroll * self, gint x, gint y, gint t);
void g_auto_scroll_run(GAutoScroll * self);

#endif