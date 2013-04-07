#ifndef _G_TEXT_BOX_H_
#define _G_TEXT_BOX_H_
#include "gwidget.h"
#include "gevent.h"

typedef enum
{
	INPUT_METHOD_TEXT,
	INPUT_METHOD_PASSWORD,
	INPUT_METHOD_ALPHABETIC,
	INPUT_METHOD_NUMERIC
} GTextInputMethods;

#define GTEXTBOX(p) ((GTextBox *)(p))
#define GTEXTBOXCLASS(p) ((GTextBoxClass *)(p))

typedef struct _GTextBox GTextBox;
typedef struct _GTextBoxClass GTextBoxClass;

struct _GTextBox
{
	GWidget base;
	gint max_length;
	gint multi_lines;
	GTextInputMethods input_method;
};
struct _GTextBoxClass
{
	GWidgetClass base;
};

void g_text_box_on_paint(gpointer self, GGraphics * g);
void g_text_box_on_pen_click(gpointer self, gint x, gint y);
void g_text_box_on_key_down(gpointer self, gint keycode);
void g_text_box_read_config(gpointer self, GValue* config);

gpointer g_get_class_GTextBox(void);

void g_text_box_init(gpointer self);
void g_text_box_finalize(gpointer self);
void g_text_box_class_init(gpointer clazz);

#endif