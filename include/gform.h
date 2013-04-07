#ifndef _G_FORM_H_
#define _G_FORM_H_
#include "gwidget.h"

#define GFORM(p) ((GForm *)(p))
#define GFORMCLASS(p) ((GFormClass *)(p))
typedef struct _GForm GForm;
typedef struct _GFormClass GFormClass;

struct _GForm
{
	GWidget base;
	GList * overlay_items;
	GWidget * captured_widget;
};
struct _GFormClass
{
	GWidgetClass base;
	void (*on_push)(gpointer self);
	void (*on_pop)(gpointer self);
	void (*on_show)(gpointer self);
	void (*on_hide)(gpointer self);
	void (*on_task)(gpointer self);
};

#define g_form_virtual_on_push(self) GFORMCLASS(GOBJECT(self)->g_class)->on_push(self)
#define g_form_virtual_on_pop(self) GFORMCLASS(GOBJECT(self)->g_class)->on_pop(self)
#define g_form_virtual_on_show(self) GFORMCLASS(GOBJECT(self)->g_class)->on_show(self)
#define g_form_virtual_on_hide(self) GFORMCLASS(GOBJECT(self)->g_class)->on_hide(self)
#define g_form_virtual_on_task(self) GFORMCLASS(GOBJECT(self)->g_class)->on_task(self)

void g_form_on_push(gpointer self);
void g_form_on_pop(gpointer self);
void g_form_on_show(gpointer self);
void g_form_on_hide(gpointer self);
void g_form_on_task(gpointer self);

gpointer g_get_class_GForm(void);

void g_form_push_overlay_widget(gpointer self, gpointer widget);
GWidget * g_form_pop_overlay_widget(gpointer self);
GWidget * g_form_get_top_overlay_widget(gpointer self);
gboolean g_form_has_overlay_widgets(gpointer self);
void g_form_paint_overlay_widgets(gpointer self, GGraphics * graphics);
void g_form_paint_command_bar(gpointer self, GGraphics * graphics);
void g_form_on_paint(gpointer self, GGraphics * graphics);
void g_form_init(gpointer self);
void g_form_finalize(gpointer self);
void g_form_class_init(gpointer clazz);

#endif