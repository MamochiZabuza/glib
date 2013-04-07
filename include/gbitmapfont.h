#ifndef _G_BITMAP_FONT_H_
#define _G_BITMAP_FONT_H_
#include "glib.h"

typedef struct
{
	gint dummy;
} GBitmapFont;

GBitmapFont * g_bitmap_font_new(guint8 * buffer, gint buflen);
void g_bitmap_font_free(GBitmapFont * font);
gint g_bitmap_font_get_height(GBitmapFont * font);
gint g_bitmap_font_get_string_width(GBitmapFont * font, gwstring text);
gboolean g_bitmap_font_get_char(GBitmapFont * font, gwchar ch, gint * w, guint8 ** data);
GBitmapFont * g_bitmap_font_get(gstring fontname);
void g_bitmap_font_register(gstring fontname, gstring uri);
#endif