#ifndef _G_CHECK_BOX_H_
#define _G_CHECK_BOX_H_
#include "gwidget.h"

#define GCHECKBOX(p) ((GCheckBox *)(p))
#define GCHECKBOXCLASS(p) ((GCheckBoxClass *)(p))
typedef struct _GCheckBox GCheckBox;
typedef struct _GCheckBoxClass GCheckBoxClass;

struct _GCheckBox
{
	GWidget base;
	gboolean checked;
};
struct _GCheckBoxClass
{
	GWidgetClass base;
};

gpointer g_get_class_GCheckBox(void);

void g_check_box_init(gpointer self);
void g_check_box_finalize(gpointer self);
void g_check_box_class_init(gpointer clazz);

#endif