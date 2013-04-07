#ifndef _G_IMAGE_BOX_H_
#define _G_IMAGE_BOX_H_
#include "gwidget.h"

#define GIMAGEBOX(p) ((GImageBox *)(p))
#define GIMAGEBOXCLASS(p) ((GImageBoxClass *)(p))
typedef struct _GImageBox GImageBox;
typedef struct _GImageBoxClass GImageBoxClass;

struct _GImageBox
{
	GWidget base;
	gstring image_uri;
	grect image_region;
	gstring focused_image_uri;
	grect focused_image_region;
};
struct _GImageBoxClass
{
	GWidgetClass base;
};

gpointer g_get_class_GImageBox(void);
void g_image_box_set_image(gpointer self, gstring image_uri, gstring fimage_uri);
void g_image_box_set_image_ex(gpointer self, gstring image_uri, gint x, gint y, gint w, gint h, gstring fimage_uri, gint fx, gint fy, gint fw, gint fh);
void g_image_box_init(gpointer self);
void g_image_box_finalize(gpointer self);
void g_image_box_class_init(gpointer clazz);

#endif