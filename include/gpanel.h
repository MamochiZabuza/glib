#ifndef _G_PANEL_H_
#define _G_PANEL_H_
#include "gwidget.h"

#define GPANEL(p) ((GPanel *)(p))
#define GPANELCLASS(p) ((GPanelClass *)(p))
typedef struct _GPanel GPanel;
typedef struct _GPanelClass GPanelClass;

struct _GPanel
{
	GWidget base;

	gpoint pen_down_position;
	gint pen_down_scrollbar_offset;
	gint pen_move_max_scrollbar_offset_change;
	GTouchState touch_state;

	void (*delegate_on_draw_scrollbar)(gpointer self, GGraphics * g);
};
struct _GPanelClass
{
	GWidgetClass base;
};

gpointer g_get_class_GPanel(void);

void g_panel_on_paint_foreground(gpointer self, GGraphics * g);
void g_panel_on_pen_down(gpointer self, gint x, gint y);
void g_panel_on_pen_up(gpointer self, gint x, gint y);
void g_panel_on_pen_move(gpointer self, gint x, gint y);

void g_panel_init(gpointer self);
void g_panel_finalize(gpointer self);
void g_panel_class_init(gpointer clazz);

#endif