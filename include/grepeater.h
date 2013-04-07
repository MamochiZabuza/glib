#ifndef _G_REPEATER_H_
#define _G_REPEATER_H_

#include "gwidget.h"
#include "gautoscroll.h"

#define GREPEATER(p) ((GRepeater *)(p))
#define GREPEATERCLASS(p) ((GRepeaterClass *)(p))
typedef struct _GRepeater GRepeater;
typedef struct _GRepeaterClass GRepeaterClass;
typedef void (*REPEATER_FOREACH_FUNC)(gpointer self, gpointer data, gint index, gint x, gint y, gint w, gint h, gboolean * stop);
struct _GRepeater
{
	GWidget base;

	GPtrArray* items;

	gint selected_index;
	gint scrollbar_offset;
	gboolean drag_enabled;

	gpoint pen_down_position;
	gint pen_down_scrollbar_offset;
	gint pen_move_max_scrollbar_offset_change;
	GTouchState touch_state;

	GEvent* event_selected_index_changed;
	GEvent* event_item_clicked;

	void (*delegate_on_item_messure_size)(gpointer self, gint index, gint* x, gint* y, gint* width, gint* height);
	void (*delegate_on_item_foreach)(gpointer self, REPEATER_FOREACH_FUNC func, gpointer funcdata);
	void (*delegate_on_item_paint)(gpointer self, gint index, GGraphics * g, gint x, gint y, gint w, gint h);	
	void (*delegate_on_item_destroy)(gpointer item);

	void (*delegate_on_draw_scrollbar)(gpointer self, GGraphics * g);
};
struct _GRepeaterClass
{
	GWidgetClass base;

	void (*on_item_messure_size)(gpointer self, gint index, gint* x, gint* y, gint* width, gint* height);
	void (*on_item_foreach)(gpointer self, REPEATER_FOREACH_FUNC func, gpointer funcdata);
	void (*on_item_paint)(gpointer self, gint index, GGraphics * g, gint x, gint y, gint w, gint h);
	void (*on_item_get_bounds)(gpointer self, gint index, grect * bounds);

	void (*on_get_items_bounds)(gpointer self, grect * bounds);

	void (*on_update_scrollbar)(gpointer self);

	int (*hit_test)(gpointer self, gint x, gint y);
};

#define g_repeater_virtual_on_item_messure_size(self, index, x, y, w, h) GREPEATERCLASS(GOBJECT(self)->g_class)->on_item_messure_size(self, index, x, y, w, h)
#define g_repeater_virtual_on_item_foreach(self, func, funcdata) GREPEATERCLASS(GOBJECT(self)->g_class)->on_item_foreach(self, func, funcdata)
#define g_repeater_virtual_on_item_paint(self, index, g, x, y, w, h) GREPEATERCLASS(GOBJECT(self)->g_class)->on_item_paint(self, index, g, x, y, w, h)
#define g_repeater_virtual_on_update_scrollbar(self) GREPEATERCLASS(GOBJECT(self)->g_class)->on_update_scrollbar(self)

#define g_repeater_virtual_on_item_get_bounds(self, index, bounds) GREPEATERCLASS(GOBJECT(self)->g_class)->on_item_get_bounds(self, index, bounds)
#define g_repeater_virtual_on_get_items_bounds(self, bounds) GREPEATERCLASS(GOBJECT(self)->g_class)->on_get_items_bounds(self, bounds)

#define g_repeater_virtual_hit_test(self, x, y) GREPEATERCLASS(GOBJECT(self)->g_class)->hit_test(self, x, y)

gpointer g_get_class_GRepeater(void);

gint g_repeater_hit_test(gpointer self, gint x, gint y);
void g_repeater_set_selected_index(gpointer self, gint index);
void g_repeater_on_key_down(gpointer self, gint keycode);
void g_repeater_on_pen_down(gpointer self, gint x, gint y);
void g_repeater_on_pen_up(gpointer self, gint x, gint y);
void g_repeater_on_pen_move(gpointer self, gint x, gint y);
void g_repeater_on_pen_click(gpointer self, gint x, gint y);

void g_repeater_set_items(gpointer self, GPtrArray * items);

gint g_repeater_item_get_count(gpointer self);
void g_repeater_item_add(gpointer self, gpointer data);
void g_repeater_item_remove(gpointer self, gpointer data);
void g_repeater_item_remove_index(gpointer self, gint index);
void g_repeater_item_insert(gpointer self, gint index, gpointer data);
void g_repeater_item_get_data(gpointer self, gint index, gpointer * data);
void g_repeater_item_get_all_bounds(gpointer self, GArray * all_bounds);
void g_repeater_item_get_bounds(gpointer self, gint index, grect * bounds);
void g_repeater_get_items_bounds(gpointer self, grect * bounds);

void g_repeater_read_config(gpointer self, GValue* config);

void g_repeater_init(gpointer self);
void g_repeater_finalize(gpointer self);
void g_repeater_class_init(gpointer clazz);

#endif