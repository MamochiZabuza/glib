#ifndef _G_LABEL_H_
#define _G_LABEL_H_
#include "gwidget.h"

#define GLABEL(p) ((GLabel *)(p))
#define GLABELCLASS(p) ((GLabelClass *)(p))
typedef struct _GLabel GLabel;
typedef struct _GLabelClass GLabelClass;

struct _GLabel
{
	GWidget base;
};
struct _GLabelClass
{
	GWidgetClass base;
};

gpointer g_get_class_GLabel(void);

void g_label_init(gpointer self);
void g_label_finalize(gpointer self);
void g_label_class_init(gpointer clazz);

#endif