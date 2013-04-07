#ifndef _G_RADIO_BUTTON_H_
#define _G_RADIO_BUTTON_H_
#include "gwidget.h"

#define GRADIOBUTTON(p) ((GRadioButton *)(p))
#define GRADIOBUTTONCLASS(p) ((GRadioButtonClass *)(p))
typedef struct _GRadioButton GRadioButton;
typedef struct _GRadioButtonClass GRadioButtonClass;

struct _GRadioButton
{
	GWidget base;
	gboolean checked;
};
struct _GRadioButtonClass
{
	GWidgetClass base;
};

gpointer g_get_class_GRadioButton(void);

void g_radio_button_init(gpointer self);
void g_radio_button_finalize(gpointer self);
void g_radio_button_class_init(gpointer clazz);

#endif