#ifndef _G_GRAPHICS_H_
#define _G_GRAPHICS_H_
#include "glib.h"
#include "gui.h"
#include "gimage.h"
#include "gbitmapfont.h"
typedef struct _GGraphics GGraphics;

typedef enum {
	LAYER,
	BUFFER
} GraphicsSource;

typedef enum  
{
	TILE_TYPE_X,
	TILE_TYPE_Y,
	TILE_TYPE_XY
} GTileType;

struct _GGraphics
{
	GraphicsSource source;
	ghandle handle;
	//gpointer buffer;
	GArray * clips;
};

GGraphics * g_graphics_new_with_layer(ghandle handle);
GGraphics * g_graphics_new_from_image(GImage* image);
void g_graphics_from_layer(GGraphics * g, ghandle handle);
void g_graphics_destroy(GGraphics * g);
void g_graphics_fill_round_rectangle(GGraphics * g, gcolor c, gint x, gint y, gint w, gint h, gint r);
void g_graphics_fill_polygon(GGraphics * g, gcolor c, gpoint* points, gint count);
void g_graphics_draw_polygon(GGraphics * g, gcolor c, gpoint* points, gint count);
void g_graphics_fill_rectangle(GGraphics * g, gcolor c, gint x, gint y, gint w, gint h);
void g_graphics_draw_rectangle(GGraphics * g, gcolor c, gint x, gint y, gint w, gint h);
void g_graphics_draw_string(GGraphics * g, gwstring str, gfont f, gcolor c, gint x, gint y);
void g_graphics_draw_string_ex(GGraphics * g, gwstring str, gfont f, gcolor c, gint x, gint y, gint maxwidth, gint padding);
void g_graphics_draw_string_with_length(GGraphics * g, gwstring str, gint len, gfont f, gcolor c, gint x, gint y);
void g_graphics_draw_string_with_length_ex(GGraphics * g, gwstring str, gint len, gfont f, gcolor c, gint x, gint y, gint maxwidth, gint padding);
void g_graphics_draw_line(GGraphics * g, gcolor c, gint x1, gint y1, gint x2, gint y2);
void g_graphics_draw_image(GGraphics * g, GImage * image, gint x, gint y);
//void g_graphics_draw_transparent_image(GGraphics * g, GImage * image, gint x, gint y);
void g_graphics_draw_image_with_trans(GGraphics * g, GImage * image, gint x, gint y, GImageTransform trans);
void g_graphics_draw_image_region(GGraphics * g, GImage * image, gint x, gint y, gint sx, gint sy, gint sw, gint sh);
void g_graphics_draw_image_with_alpha(GGraphics * g, GImage * image, gint x, gint y, gint alpha);
void g_graphics_draw_image_region_with_alpha(GGraphics * g, GImage * image, gint x, gint y, gint sx, gint sy, gint sw, gint sh, gint alpha);
void g_graphics_begin_clip(GGraphics * g, gint x, gint y, gint w, gint h);
void g_graphics_end_clip(GGraphics * g);
gboolean g_graphics_in_clip(GGraphics * g, gint x, gint y, gint w, gint h);
grect g_graphics_get_clip(GGraphics * g);
void g_graphics_draw_tiled_image(GGraphics * g, GImage * image, gint x, gint y, gint w, gint h, GTileType tt);
void g_graphics_draw_tiled_image_region(GGraphics * g, GImage * image, gint x, gint y, gint w, gint h, gint sx, gint sy, gint sw, gint sh, GTileType tt);
void g_graphics_draw_image_skin(GGraphics * g, GImage * image, gint x, gint y, gint w, gint h, gint left, gint right, gint top, gint bottom);

gcolor g_graphics_get_pixel(GGraphics * g, gint x, gint y);
void g_graphics_set_pixel(GGraphics * g, gcolor c, gint x, gint y);
void g_graphics_draw_string_with_bitmap_font(GGraphics * g, gwstring str, GBitmapFont * font, gcolor c, gint x, gint y);
void g_graphics_draw_string_with_font_name(GGraphics * g, gwstring str, gstring fontname, gcolor c, gint x, gint y);
gboolean g_graphics_is_current_clip_empty(GGraphics * g);

#endif