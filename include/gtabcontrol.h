#ifndef _G_TAB_CONTROL_H_
#define _G_TAB_CONTROL_H_
#include "gwidget.h"

typedef struct
{
	gstring image_uri;
	gstring text;
	gpointer data;
	GWidget* widget;
} GTabItem;

#define GTABCONTROL(p) ((GTabControl *)(p))
#define GTABCONTROLCLASS(p) ((GTabControlClass *)(p))
typedef struct _GTabControl GTabControl;
typedef struct _GTabControlClass GTabControlClass;

struct _GTabControl
{
	GWidget base;
};
struct _GTabControlClass
{
	GWidgetClass base;
};

gpointer g_get_class_GTabControl(void);

void g_tab_control_init(gpointer self);
void g_tab_control_finalize(gpointer self);
void g_tab_control_class_init(gpointer clazz);

#endif