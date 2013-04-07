#ifndef _G_BUTTON_H_
#define _G_BUTTON_H_
#include "gwidget.h"

#define GBUTTON(p) ((GButton *)(p))
#define GBUTTONCLASS(p) ((GButtonClass *)(p))
typedef struct _GButton GButton;
typedef struct _GButtonClass GButtonClass;

struct _GButton
{
	GWidget base;
	GEvent* event_click;
};
struct _GButtonClass
{
	GWidgetClass base;
};

gpointer g_get_class_GButton(void);

void g_button_on_key_down(gpointer self, gint keycode);
void g_button_on_pen_click(gpointer self, gint x, gint y);
void g_button_on_paint(gpointer self, GGraphics * graphics);
void g_button_read_config(gpointer self, GValue* config);

void g_button_init(gpointer self);
void g_button_finalize(gpointer self);
void g_button_class_init(gpointer clazz);

#endif