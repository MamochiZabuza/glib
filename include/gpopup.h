#ifndef _G_POPUP_H_
#define _G_POPUP_H_
#include "gwidget.h"

#define GPOPUP(p) ((GPopup *)(p))
#define GPOPUPCLASS(p) ((GPopupClass *)(p))
typedef struct _GPopup GPopup;
typedef struct _GPopupClass GPopupClass;

struct _GPopup
{
	GWidget base;
};
struct _GPopupClass
{
	GWidgetClass base;
};

gpointer g_get_class_GPopup(void);

void g_popup_init(gpointer self);
void g_popup_finalize(gpointer self);
void g_popup_class_init(gpointer clazz);

#endif