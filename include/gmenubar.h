#ifndef _G_MENU_BAR_H_
#define _G_MENU_BAR_H_
#include "gwidget.h"
#include "gform.h"

#define GMENUBAR(p) ((GMenuBar *)(p))
#define GMENUBARCLASS(p) ((GMenuBarClass *)(p))
typedef struct _GMenuBar GMenuBar;
typedef struct _GMenuBarClass GMenuBarClass;

typedef void (*MENU_BAR_COMMAND_FUNC)(gpointer menubar);

struct _GMenuBar
{
	GWidget base;
	GList * attached_items;
	grect left_click_area, right_click_area;
};
struct _GMenuBarClass
{
	GWidgetClass base;
};

typedef struct 
{
	GMenuBar * menubar;
	GWidget * widget;
	gstring left_text;
	gstring right_text;
	MENU_BAR_COMMAND_FUNC on_left_clicked;
	MENU_BAR_COMMAND_FUNC on_right_clicked;
} GMenuBarAttachedItem;

GMenuBarAttachedItem * g_menu_bar_get_top_attched_item(gpointer self);
void g_menu_bar_push_attached_widget(gpointer self, gpointer widget, gstring left_text, MENU_BAR_COMMAND_FUNC left_cmd, gstring right_text, MENU_BAR_COMMAND_FUNC right_cmd);
void g_menu_bar_pop_attached_widget(gpointer self);
void g_menu_bar_on_paint(gpointer self, GGraphics * graphics);
void g_menu_bar_on_pen_down(gpointer self, gint x, gint y);

gpointer g_get_class_GMenuBar(void);

void g_menu_bar_init(gpointer self);
void g_menu_bar_finalize(gpointer self);
void g_menu_bar_class_init(gpointer clazz);

#endif