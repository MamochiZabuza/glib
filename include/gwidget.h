#ifndef _G_WIDGET_H_
#define _G_WIDGET_H_

#include "gobject.h"
#include "gui.h"
#include "ggraphics.h"
#include "gevent.h"
#include "gvalue.h"

#define GWIDGET(p) ((GWidget *)(p))
#define GWIDGETCLASS(p) ((GWidgetClass *)(p))
typedef struct _GWidget GWidget;
typedef struct _GWidgetClass GWidgetClass;

typedef enum 
{
	KEY_ENTER_TRIGGER_NONE,
	KEY_ENTER_TRIGGER_OK,
	KEY_ENTER_TRIGGER_ANY
} KeyEnterTriggers;

struct _GWidget
{
	GObject base;	
	GWidget * parent_widget;
	GWidget * focused_widget;
	GList * child_widgets;
	GList * ordered_child_widgets;
	gboolean focusable;
	grect bounds; //x, y, width, height relative to its parent
	gboolean scrollable;
	gint scrollbar_offset_x;
	gint scrollbar_offset_y;
	gboolean auto_focus;

	gint zorder;
	gcolor backcolor, forecolor, highlight_color;
	gcolor border_color;
	gcolor focused_border_color;
	gstring text;
	gfont font;
	gboolean visible;
	gboolean pass_pen_event_to_parent;
	GDockStyle dock;
	GAnchorType anchor;
	gbounds margins, paddings;
	gint anchor_x, anchor_y, anchor_width, anchor_height;

	KeyEnterTriggers key_enter_trigger;
	gboolean key_entered;

	gpointer data;
	gstring name;

	GEvent* event_key_up;
	GEvent* event_key_down;
	GEvent* event_key_repeat;
	GEvent* event_key_long_press;

	GEvent* event_pen_up;
	GEvent* event_pen_down;
	GEvent* event_pen_move;
	GEvent* event_pen_click;	

	GEvent* event_got_focus;
	GEvent* event_lost_focus;	

	GEvent * event_text_changed;

	void (*delegate_on_paint_background)(gpointer self, GGraphics * graphics); 
	void (*delegate_on_paint)(gpointer self, GGraphics * graphics); 
	void (*delegate_on_paint_foreground)(gpointer self, GGraphics * graphics); 
	void (*delegate_on_messure_size)(gpointer self, gint * width, gint * height);
	void (*delegate_do_layout)(gpointer self);
	void (*delegate_read_config)(gpointer self, GValue* config);
};

struct _GWidgetClass
{
	GObjectClass base;

	gboolean (*is_transparent)(gpointer self);
	gboolean (*is_focusable)(gpointer self);

	void (*on_paint_background)(gpointer self, GGraphics * graphics);
	void (*on_paint)(gpointer self, GGraphics * graphics);
	void (*on_paint_foreground)(gpointer self, GGraphics * graphics);

	void (*on_key_up)(gpointer self, gint keycode);
	void (*on_key_down)(gpointer self, gint keycode);
	void (*on_key_repeat)(gpointer self, gint keycode);
	void (*on_key_long_press)(gpointer self, gint keycode);

	void (*on_pen_up)(gpointer self, gint x, gint y);
	void (*on_pen_down)(gpointer self, gint x, gint y);
	void (*on_pen_move)(gpointer self, gint x, gint y);
	void (*on_pen_click)(gpointer self, gint x, gint y);

	void (*on_messure_size)(gpointer self, gint * width, gint * height);
	void (*do_layout)(gpointer self);

	void (*read_config)(gpointer self, GValue* config);
};

gpointer g_get_class_GWidget(void);

#define g_widget_virtual_read_config(self, config) \
	if (GWIDGET(self)->delegate_read_config)\
		GWIDGET(self)->delegate_read_config(self, config);\
	else\
		GWIDGETCLASS(GOBJECT(self)->g_class)->read_config(self, config)
#define g_widget_virtual_is_transparent(self) GWIDGETCLASS(GOBJECT(self)->g_class)->is_transparent(self)
#define g_widget_virtual_is_focusable(self) GWIDGETCLASS(GOBJECT(self)->g_class)->is_focusable(self)
#define g_widget_virtual_on_paint(self, graphics) \
	if (GWIDGET(self)->delegate_on_paint)\
		GWIDGET(self)->delegate_on_paint(self, graphics);\
	else\
		GWIDGETCLASS(GOBJECT(self)->g_class)->on_paint(self, graphics)
#define g_widget_virtual_on_paint_background(self, graphics) \
	if (GWIDGET(self)->delegate_on_paint_background)\
		GWIDGET(self)->delegate_on_paint_background(self, graphics);\
	else if (GWIDGETCLASS(GOBJECT(self)->g_class)->on_paint_background)\
		GWIDGETCLASS(GOBJECT(self)->g_class)->on_paint_background(self, graphics)
#define g_widget_virtual_on_paint_foreground(self, graphics) \
	if (GWIDGET(self)->delegate_on_paint_foreground)\
		GWIDGET(self)->delegate_on_paint_foreground(self, graphics);\
	else if (GWIDGETCLASS(GOBJECT(self)->g_class)->on_paint_foreground)\
		GWIDGETCLASS(GOBJECT(self)->g_class)->on_paint_foreground(self, graphics)
#define g_widget_virtual_on_key_up(self, kc) \
	G_STMT_START{\
		GKeyEventArgs args;\
		args.consumed = FALSE;\
		args.keycode = kc;\
		g_event_fire(GWIDGET(self)->event_key_up, &args);\
		if (!args.consumed)\
			GWIDGETCLASS(GOBJECT(self)->g_class)->on_key_up(self, kc);\
	}G_STMT_END
#define g_widget_virtual_on_key_down(self, kc) \
	G_STMT_START{\
		GKeyEventArgs args;\
		args.consumed = FALSE;\
		args.keycode = kc;\
		g_event_fire(GWIDGET(self)->event_key_down, &args);\
		if (!args.consumed)\
			GWIDGETCLASS(GOBJECT(self)->g_class)->on_key_down(self, kc); \
	}G_STMT_END
#define g_widget_virtual_on_key_repeat(self, kc) \
	G_STMT_START{\
		GKeyEventArgs args;\
		args.consumed = FALSE;\
		args.keycode = kc;\
		g_event_fire(GWIDGET(self)->event_key_repeat, &args);\
		if (!args.consumed)\
			GWIDGETCLASS(GOBJECT(self)->g_class)->on_key_repeat(self, kc);\
	}G_STMT_END

#define g_widget_virtual_on_key_long_press(self, kc) \
	G_STMT_START{\
	GKeyEventArgs args;\
	args.consumed = FALSE;\
	args.keycode = kc;\
	g_event_fire(GWIDGET(self)->event_key_long_press, &args);\
	if (!args.consumed)\
	GWIDGETCLASS(GOBJECT(self)->g_class)->on_key_long_press(self, kc);\
}G_STMT_END

#define g_widget_virtual_on_pen_up(self, cx, cy) \
	G_STMT_START{\
		GPenEventArgs args; \
		args.consumed = FALSE;\
		args.x = cx; \
		args.y = cy; \
		g_event_fire(GWIDGET(self)->event_pen_up, &args);\
		if (!args.consumed)\
			GWIDGETCLASS(GOBJECT(self)->g_class)->on_pen_up(self, cx, cy);\
	}G_STMT_END
#define g_widget_virtual_on_pen_down(self, cx, cy) \
	G_STMT_START{\
		GPenEventArgs args; \
		args.consumed = FALSE;\
		args.x = cx; \
		args.y = cy; \
		g_event_fire(GWIDGET(self)->event_pen_down, &args);\
		if (!args.consumed)\
			GWIDGETCLASS(GOBJECT(self)->g_class)->on_pen_down(self, cx, cy);\
	}G_STMT_END
#define g_widget_virtual_on_pen_move(self, cx, cy) \
	G_STMT_START{\
		GPenEventArgs args; \
		args.consumed = FALSE;\
		args.x = cx; \
		args.y = cy; \
		g_event_fire(GWIDGET(self)->event_pen_move, &args);\
		if (!args.consumed)\
			GWIDGETCLASS(GOBJECT(self)->g_class)->on_pen_move(self, cx, cy);\
	}G_STMT_END
#define g_widget_virtual_on_pen_click(self, cx, cy) \
	G_STMT_START{\
		GPenEventArgs args; \
		args.consumed = FALSE;\
		args.x = cx; \
		args.y = cy; \
		g_event_fire(GWIDGET(self)->event_pen_click, &args);\
		if (!args.consumed)\
			GWIDGETCLASS(GOBJECT(self)->g_class)->on_pen_click(self, cx, cy);\
	}G_STMT_END
#define g_widget_virtual_on_messure_size(self, width, height)  \
	if (GWIDGET(self)->delegate_on_messure_size)\
		GWIDGET(self)->delegate_on_messure_size(self, width, height);\
	else\
		GWIDGETCLASS(GOBJECT(self)->g_class)->on_messure_size(self, width, height)
#define g_widget_virtual_do_layout(self)  \
	if (GWIDGET(self)->delegate_do_layout)\
		GWIDGET(self)->delegate_do_layout(self);\
	else\
		GWIDGETCLASS(GOBJECT(self)->g_class)->do_layout(self)

void g_widget_get_location_in_screen(gpointer self, gint* x, gint* y);
void g_widget_get_bounds_in_screen(gpointer self, gint* x, gint* y, gint* w, gint* h);

gboolean g_widget_is_transparent(gpointer self);
gboolean g_widget_is_focusable(gpointer self);

gboolean g_widget_is_captured(gpointer self);
void g_widget_set_captured(gpointer self, gboolean captured);

gboolean g_widget_is_focused(gpointer self);
void g_widget_set_focused(gpointer self);
GWidget* g_widget_get_top_focused_widget(gpointer self);
void g_widget_set_bounds(gpointer self, gint x, gint y, gint w, gint h);
void g_widget_set_text(gpointer self, gstring text);
gpointer g_widget_get_parent_form(gpointer self);
gpointer g_widget_get_child_by_name(gpointer self, gstring name);

void g_widget_on_paint(gpointer self, GGraphics * graphics);
void g_widget_on_key_up(gpointer self, gint keycode);
void g_widget_on_key_down(gpointer self, gint keycode);
void g_widget_on_key_repeat(gpointer self, gint keycode);
void g_widget_on_pen_up(gpointer self, gint x, gint y);
void g_widget_on_pen_down(gpointer self, gint x, gint y);
void g_widget_on_pen_move(gpointer self, gint x, gint y);
void g_widget_on_pen_click(gpointer self, gint x, gint y);

void g_widget_on_messure_size(gpointer self, gint * width, gint * height);
void g_widget_do_layout(gpointer self);
void g_widget_layout_widgets_in(gpointer self, GList * child_widgets, gint x, gint y, gint w, gint h);

void g_widget_draw_solid_background(gpointer self, GGraphics * graphics, gcolor c);
void g_widget_draw_simple_vscrollbar(gpointer self, GGraphics * graphics, gcolor backcolor, gcolor thumbcolor, gint fullheight, gint offset, gint thumbwidth);
void g_widget_paint_child_widgets(gpointer self, GGraphics * graphics);

void g_widget_add_child_widget(gpointer self, gpointer widget);
void g_widget_remove_child_widget(gpointer self, gpointer widget);
grect g_widget_get_child_widgets_bounds(gpointer self);

GWidget * g_widget_hit_test(gpointer self, gint x, gint y);
GWidget * g_widget_hit_test_top_widget(gpointer self, gint x, gint y);

void g_widget_invalidate(gpointer self);
void g_widget_invalidate_region(gpointer self, gint x, gint y, gint w, gint h);
void g_widget_refresh(gpointer self);

void g_widget_resize_to_anchor(gpointer self);

void g_widget_read_config(gpointer self, GValue* config);

void g_widget_init(gpointer self);
void g_widget_finalize(gpointer self);
void g_widget_class_init(gpointer clazz);

void g_widget_list_destroy(GList* widgets);
void g_widget_list_paint(GList* widgets, GGraphics * graphics);

gcolor g_widget_parse_color(gstring color);

GWidget* g_widget_get_first_focused_widget(GWidget* widget);
void g_widget_draw_border(gpointer self, GGraphics * g);

#endif