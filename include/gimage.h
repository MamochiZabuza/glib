#ifndef _G_IMAGE_H_
#define _G_IMAGE_H_

#include "glib.h"
#include "gui.h"
#include "gevent.h"
typedef struct _GImage GImage;

//#define IN_MEM_IMAGE_DECODE

struct _GImage
{
	gint dummy;
};
typedef enum
{
	IMAGE_TRANS_ROT90,
	IMAGE_TRANS_ROT180,
	IMAGE_TRANS_ROT270,
	IMAGE_TRANS_MIRROR_X,
	IMAGE_TRANS_MIRROR_Y
}GImageTransform;

//GImage * g_image_new_with_resource(gstring name);
//GImage * g_image_new_with_resource_resized(gstring name, gint w, gint h);

GImage * g_image_new_with_buffer(gpointer buf, gint len);
GImage * g_image_new_with_buffer_resized(gpointer buf, gint len, gint w, gint h);

GImage * g_image_lite_new_with_buffer(gpointer buf, gint len);
GImage * g_image_lite_new_with_buffer_resized(gpointer buf, gint len, gint w, gint h);

//GImage * g_image_clone(GImage * self);
//GImage * g_image_crop(GImage * self, gint x, gint y, gint w, gint h);
//void g_image_transform(GImage * self, GImageTransform trans);

void g_image_destroy(GImage * self);
gint g_image_get_width(GImage * self);
gint g_image_get_height(GImage * self);

void g_image_set_trans_color(GImage * self, gcolor c);
void g_image_set_alpha(GImage * self, gint alpha);
gcolor g_image_get_pixel(GImage * self, gint x, gint y);
void g_image_set_pixel(GImage * self, gint x, gint y, gcolor c);

gint g_image_get_original_width(GImage * self);
gint g_image_get_original_height(GImage * self);
gboolean g_image_is_lite_mode(GImage * self);
ghandle g_image_get_handle(GImage * self);

gboolean g_image_is_valid(GImage * self);

gint g_image_get_frame_count(GImage * self);
gint g_image_get_current_frame(GImage * self);
void g_image_set_current_frame(GImage * self, gint frame);

#endif 