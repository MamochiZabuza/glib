#ifndef _G_LIST_BOX_H_
#define _G_LIST_BOX_H_
#include "grepeater.h"

#define GLISTBOX(p) ((GListBox *)(p))
#define GLISTBOXCLASS(p) ((GListBoxClass *)(p))
typedef struct _GListBox GListBox;
typedef struct _GListBoxClass GListBoxClass;

struct _GListBox
{
	GRepeater base;
	gboolean support_page;
	gint item_height;
	gboolean wrap_selection;
};
struct _GListBoxClass
{
	GRepeaterClass base;
};

gpointer g_get_class_GListBox(void);

void g_list_box_on_paint(gpointer self, GGraphics * g);
void g_list_box_on_key_down(gpointer self, gint keycode);

void g_list_box_init(gpointer self);
void g_list_box_finalize(gpointer self);
void g_list_box_class_init(gpointer clazz);

#endif