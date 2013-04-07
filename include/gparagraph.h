#ifndef _G_PARAGRAPH_H_
#define _G_PARAGRAPH_H_

#include "ggraphics.h"

gstring g_graphics_messure_line(gfont font, gstring text, gint width, gwstring* result, gboolean erase_leading_space, gboolean erase_duplicated_space, gboolean cannot_empty);
void g_graphics_messure_paragraph(gfont font, gstring text, gint width, gint linespace, gint* height, GPtrArray* paragraph);
void g_graphics_messure_paragraph2(gfont font, gstring text, gint width, gint linespace, gint* height, GPtrArray* paragraph, gboolean erase_leading_space, gboolean erase_duplicated_space, gboolean cannot_empty);
void g_graphics_draw_paragraph(GGraphics * g, gfont font, gstring text, gcolor c, gint x, gint y, gint width, gint height);
void g_graphics_draw_paragraph2(GGraphics * g, gfont font, gstring text, gcolor c, gint x, gint y, gint width, gint height, gint linespace, GTextAlignment align);
void g_graphics_draw_paragraph3(GGraphics * g, gfont font, GPtrArray* lines, gcolor c, gint x, gint y, gint width, gint height, gint linespace, GTextAlignment align);

#endif