#ifndef _G_MENU_H_
#define _G_MENU_H_
#include "glistbox.h"

#define GMENU(p) ((GMenu *)(p))
#define GMENUCLASS(p) ((GMenuClass *)(p))
typedef struct _GMenu GMenu;
typedef struct _GMenuClass GMenuClass;
typedef struct _GMenuItem GMenuItem;

typedef void (*MENU_ITEM_CLICKED_FUNC)(GMenu * menu, GMenuItem * mi);

struct _GMenuItem
{
	gstring text;
	gstring command;
	gboolean visible;
	gboolean enabled;
	gpointer submenu;
	gpointer data;
	MENU_ITEM_CLICKED_FUNC clicked;
};

#define MENU_ITEM_SEPERATOR "--------"

struct _GMenu
{
	GListBox base;
};
struct _GMenuClass
{
	GListBoxClass base;
};

gpointer g_get_class_GMenu(void);

void g_menu_on_messure_size(gpointer self, gint * w, gint * h);
void g_menu_init(gpointer self);
void g_menu_finalize(gpointer self);
void g_menu_class_init(gpointer clazz);

void g_menu_on_pen_down(gpointer self, gint x, gint y);
void g_menu_on_key_down(gpointer self, gint keycode);
void g_menu_on_messure_size(gpointer self, gint * w, gint * h);
void g_menu_on_item_paint(gpointer self, gint index, GGraphics * g, gint x, gint y, gint w, gint h);

void g_menu_add_menu_item(gpointer self, GMenuItem * mi);
void g_menu_remove_menu_item(gpointer self, GMenuItem * mi);
GMenuItem * g_menu_get_menu_item_by_command(gpointer self, gstring cmd);

GMenuItem * g_menu_item_new(gstring text, gstring cmd, MENU_ITEM_CLICKED_FUNC clicked);
gboolean g_menu_item_is_seperator(gpointer self);
void g_menu_item_destroy(gpointer self);

#endif