#ifndef _G_GRID_VIEW_H_
#define _G_GRID_VIEW_H_
#include "grepeater.h"

#define GGRIDVIEW(p) ((GGridView *)(p))
#define GGRIDVIEWCLASS(p) ((GGridViewClass *)(p))
typedef struct _GGridView GGridView;
typedef struct _GGridViewClass GGridViewClass;

struct _GGridView
{
	GRepeater base;
	gint columns;
	gint row_height;	
};
struct _GGridViewClass
{
	GRepeaterClass base;
};

gpointer g_get_class_GGridView(void);

void g_grid_view_on_key_down(gpointer self, gint keycode);
void g_grid_view_paint(gpointer self, GGraphics * graphics);

void g_grid_view_read_config(gpointer self, GValue* config);

void g_grid_view_init(gpointer self);
void g_grid_view_finalize(gpointer self);
void g_grid_view_class_init(gpointer clazz);

#endif