#ifndef __G_RICH_TEXT_H__
#define __G_RICH_TEXT_H__
#include "glib.h"
#include "gui.h"
#include "ggraphics.h"
#define RICH_TEXT_CONTEXT_CODE_MIN 0xE000
#define RICH_TEXT_CONTEXT_CODE_MAX 0xF8FF

#define g_is_control_unicode(c) ((c) >= RICH_TEXT_CONTEXT_CODE_MIN && (c) <= RICH_TEXT_CONTEXT_CODE_MAX)

typedef enum{
	RICH_TEXT_CONTEXT_ITEM_IMAGE,
	RICH_TEXT_CONTEXT_ITEM_STYLE,
	RICH_TEXT_CONTEXT_ITEM_REGION
} GRichTextContextItemType;
typedef struct
{
	GRichTextContextItemType type;
	union{
		struct  
		{
			gwchar code;
			gstring tag;
			gstring uri;
			gint x;
			gint y;
			gint width;
			gint height;
		} image;
		struct  
		{
			gwchar code;
			gstring tag;
			gcolor color;
			gfont font;
		} style;
	} data;
} GRichTextContextItem;

typedef struct
{
	gwchar next_code;
	gcolor default_color;
	gfont default_font;
	GPtrArray* items;
} GRichTextContext;

typedef struct
{
	GRichTextContext* context;
	gcolor color;
	gfont font;
} GRichTextLineContext;

typedef struct
{
	GRichTextLineContext* context;
	gwstring text;
	gint x, y;
	gint height;
	gint width;
	gint baseline;
} GRichTextLine;

GRichTextContext * g_rich_text_context_new(gcolor default_color, gfont default_font);
void g_rich_text_context_free(GRichTextContext * self);

GRichTextContextItem* g_rich_text_context_add_image(GRichTextContext * self, gstring tag, gstring uri);
GRichTextContextItem* g_rich_text_context_add_image_region(GRichTextContext * self, gstring tag, gstring uri, gint x, gint y, gint width, gint height);
GRichTextContextItem* g_rich_text_context_add_image_resized(GRichTextContext * self, gstring tag, gstring uri, gint width, gint height);
GRichTextContextItem* g_rich_text_context_add_style(GRichTextContext * self, gstring tag, gcolor color, gfont font);
GRichTextContextItem* g_rich_text_context_get_item(GRichTextContext * self, gwchar code);
void g_rich_text_context_item_free(GRichTextContextItem* self);

void g_rich_text_context_encode(GRichTextContext * self, gstring text, gwstring* rich_text);
void g_rich_text_context_decode(GRichTextContext * self, gwstring rich_text, gstring* text);

GRichTextLineContext* g_rich_text_line_context_new(GRichTextContext* context);
GRichTextLineContext* g_rich_text_line_context_clone(GRichTextLineContext* context);
void g_rich_text_line_context_free(GRichTextLineContext* self);

GRichTextLine* g_rich_text_line_new(void);
void g_rich_text_line_free(GRichTextLine* self);

void g_rich_text_context_get_line_size(GRichTextContext * self, GRichTextLine* line);
gwstring g_rich_text_context_messure_line(GRichTextContext * self, GRichTextLineContext* context, gwstring text, gint width, GRichTextLine* line);
void g_rich_text_context_messure_paragraph(GRichTextContext * self, gwstring text, gint width, gint linespace, gint* height, GPtrArray* paragraph);

void g_graphics_draw_rich_text(GGraphics * g, GRichTextContext * context, gstring text, gint x, gint y);
void g_graphics_draw_rich_encoded_text(GGraphics * g, GRichTextContext * context, gwstring text, gint x, gint y);
void g_graphics_draw_rich_line(GGraphics * g, GRichTextContext * context, GRichTextLine* line, gint x, gint y);
void g_graphics_draw_rich_line_ex(GGraphics * g, GRichTextContext * context, GRichTextLine* line, gint x, gint y, gint maxwidth);
void g_graphics_draw_rich_paragraph(GGraphics * g, GRichTextContext * context, GPtrArray* lines, gint x, gint y, gint width, gint height);
void g_graphics_draw_rich_paragraph2(GGraphics * g, GRichTextContext * context, GPtrArray* lines, gint x, gint y, gint width, gint height, gint linespace, GTextAlignment align);

#endif