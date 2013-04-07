#ifndef _G_COMBO_BOX_H_
#define _G_COMBO_BOX_H_
#include "gwidget.h"
#include "glistbox.h"

#define GCOMBOBOX(p) ((GComboBox *)(p))
#define GCOMBOBOXCLASS(p) ((GComboBoxClass *)(p))
typedef struct _GComboBox GComboBox;
typedef struct _GComboBoxClass GComboBoxClass;

struct _GComboBox
{
	GWidget base;
	GListBox * dropdown;
};
struct _GComboBoxClass
{
	GWidgetClass base;
};

gpointer g_get_class_GComboBox(void);

void g_combo_box_init(gpointer self);
void g_combo_box_finalize(gpointer self);
void g_combo_box_class_init(gpointer clazz);

#endif