#ifndef __G_HTML_VIEW_H__
#define __G_HTML_VIEW_H__

#include "gui.h"
#include "gwidget.h"
#include "grichtext.h"
#include "gxml.h"
#include "gcoroutine.h"
#include "gimagemanager.h"
#include "ghttp.h"

#define NBSP 160

#define HTML_TAG_HTML "html"
#define HTML_TAG_WML "wml"
#define HTML_TAG_HEAD "head"
#define HTML_TAG_BODY "body"
#define HTML_TAG_CARD "card"
#define HTML_TAG_SCRIPT "script"
#define HTML_TAG_IMAGE "img"
#define HTML_TAG_INPUT "input"
#define HTML_TAG_FONT "font"
#define HTML_TAG_A "a"
#define HTML_TAG_BR "br"
#define HTML_TAG_FORM "form"
#define HTML_TAG_TABLE "table"
#define HTML_TAG_TBODY "tbody"
#define HTML_TAG_TR "tr"
#define HTML_TAG_TD "td"
#define HTML_TAG_TH "th"
#define HTML_TAG_INPUT "input"
#define HTML_TAG_SELECT "select"
#define HTML_TAG_TEXTAREA "textarea"
#define HTML_TAG_OPTION "option"

#define HTML_ATTR_TYPE "type"
#define HTML_ATTR_VALUE "value"
#define HTML_ATTR_ROWS "rows"
#define HTML_ATTR_COLS "cols"
#define HTML_ATTR_NAME "name"
#define HTML_ATTR_TYPE_BUTTON "button"
#define HTML_ATTR_TYPE_SUBMIT "submit"
#define HTML_ATTR_TYPE_RESET "reset"
#define HTML_ATTR_TYPE_HIDDEN "hidden"
#define HTML_ATTR_TYPE_TEXT "text"
#define HTML_ATTR_TYPE_PASSWORD "password"
#define HTML_ATTR_TYPE_RADIO_BUTTON "radio"
#define HTML_ATTR_TYPE_CHECK_BOX "checkbox"
#define HTML_ATTR_SRC "src"
#define HTML_ATTR_SIZE "size"
#define HTML_ATTR_WIDTH "width"
#define HTML_ATTR_HEIGHT "height"
#define HTML_ATTR_COLOR "color"
#define HTML_ATTR_CLASS "class"
#define HTML_ATTR_ID "id"
#define HTML_ATTR_STYLE "style"
#define HTML_ATTR_HREF "href"
#define HTML_ATTR_ACTION "action"
#define HTML_ATTR_METHOD "method"
#define HTML_ATTR_ALIGN "align"
#define HTML_ATTR_ALIGN_LEFT "left"
#define HTML_ATTR_ALIGN_RIGHT "right"
#define HTML_ATTR_ALIGN_CENTER "center"
#define HTML_ATTR_VALIGN "valign"
#define HTML_ATTR_VALIGN_TOP "top"
#define HTML_ATTR_VALIGN_BOTTOM "bottom"
#define HTML_ATTR_VALIGN_MIDDLE "middle"
#define HTML_ATTR_VSPACE "vspace"
#define HTML_ATTR_HSPACE "hspace"
#define IS_HTTP_URL(uri) (g_strstartwith(uri, "http://") || g_strstartwith(uri, "https://"))
#define TAG_IS(node, t) ((node) != NULL && g_strequal(g_xml_get_name(node), t))

typedef enum 
{
	HTML_FLOAT_NONE = 0,
	HTML_FLOAT_LEFT,
	HTML_FLOAT_RIGHT
} GHtmlFloatType;

typedef enum 
{
	HTML_REPEAT_NONE = 0,
	HTML_REPEAT_X,
	HTML_REPEAT_Y,
	HTML_REPEAT
} GHtmlBackgroundRepeatType;

typedef enum
{
	HTML_WHITE_SPACE_NORMAL = 0,
	HTML_WHITE_SPACE_NO_WRAP,
	HTML_WHITE_SPACE_PRE,
	HTML_WHITE_SPACE_PRE_WRAP,
	HTML_WHITE_SPACE_PRE_LINE
} GHtmlWhiteSpaceType;

typedef enum
{
	HTML_CSS_UNIT_UNSET = 0,
	HTML_CSS_UNIT_EMPTY,
	HTML_CSS_UNIT_PIXEL,
	HTML_CSS_UNIT_EM,
	HTML_CSS_UNIT_PERCENT,
	HTML_CSS_UNIT_AUTO,
	HTML_CSS_UNIT_NORMAL,
	HTML_CSS_UNIT_INHERIT
} GHtmlCssUnit;

typedef enum
{
	HTML_BOX_BLOCK,
	HTML_BOX_WRAPPER,
	HTML_BOX_IMAGE,
	HTML_BOX_WIDGET
} GHtmlBoxType;

typedef enum
{
	HTML_DISPLAY_NONE = 0,
	HTML_DISPLAY_INLINE,
	HTML_DISPLAY_LIST_ITEM,
	HTML_DISPLAY_BLOCK,
	HTML_DISPLAY_TABLE,
	HTML_DISPLAY_TABLE_MIN = HTML_DISPLAY_TABLE,
	HTML_DISPLAY_TABLE_ROW,
	HTML_DISPLAY_TABLE_HEADER_GROUP,
	HTML_DISPLAY_TABLE_ROW_GROUP,
	HTML_DISPLAY_TABLE_FOOTER_GROUP,
	HTML_DISPLAY_TABLE_MAX = HTML_DISPLAY_TABLE_FOOTER_GROUP,
	HTML_DISPLAY_TABLE_CELL
} GHtmlDisplayType;

typedef struct _GHtmlView GHtmlView;
typedef struct _GHtmlBox GHtmlBox;

typedef struct _GHtmlLength
{
	gint value;
	GHtmlCssUnit unit;
} GHtmlLength;

typedef enum 
{
	HTML_CSS_RELATION_SELF,
	HTML_CSS_RELATION_PARENT,
	HTML_CSS_RELATION_ANCESTOR,
	HTML_CSS_RELATION_SIBLING
} GHtmlCssSelectorRelationType;

typedef struct _GHtmlCssSelector
{
	GHtmlCssSelectorRelationType relation;
	gstring id;
	gstring class;
	gstring tag;
	gstring pseudo;
} GHtmlCssSelector;

typedef struct _GHtmlCssRule
{
	GPtrArray * selectors;
	gint properties_no;
} GHtmlCssRule;

typedef struct
{
	GHtmlLength left, right, top, bottom;
} GHtmlBounds;

typedef struct
{
	gint style_no;
	gstring content;
	GPtrArray * segments;
	GHtmlBox * box;
} GHtmlItem;

typedef struct
{
	gint x;
	gint y;
	GHtmlItem * item;
} GHtmlFocusableArea;

typedef struct
{
	gstring uri;
	gint index;
	gint count;
} GHtmlCssUri;

typedef struct
{
	GHtmlFloatType float_type;
	GHtmlDisplayType display;
	gcolor backcolor;
	gstring backimage;
	GHtmlBackgroundRepeatType backimage_repeat;
	GHtmlBounds margins;
	GHtmlBounds borders;
	GHtmlBounds paddings;
	gcolor color;
	gfont font;
	GHtmlLength line_height;
	GTextAlignment text_align;
	GVerticalAlignment vertical_align;
	GHtmlLength width;
	GHtmlLength height;
	GHtmlWhiteSpaceType white_space;
	GXmlNode * action_node;
} GHtmlStyle;

typedef struct
{
	gwstring segment;
	grect bounds;
} GHtmlTextSegment;

typedef struct
{
	gint16 index;			// item index
	gint16 segment_index;	// segment index in text item
} GHtmlLineItem;

typedef struct _GHtmlLine
{
	GArray * items;
	gint baseline;
	grect bounds;
	gint max_width;
} GHtmlLine;

struct _GHtmlBox
{
	GHtmlBoxType type;
	gint style_no;

	GHtmlView * view;
	GHtmlBox * parent_box;
	GXmlNode * node; 
	gstring tag;
	grect bounds;	

	union
	{
		struct{
			GPtrArray * items;
			GPtrArray * lines;
		} wrapper;
		struct{
			GPtrArray * boxes;
		} block;
		struct{
			GWidget * peer;
		} widget;
		struct{
			gstring uri;
		} image;
	} data;
};
struct _GHtmlTagHandler
{
	void (*delegate_on_parse)(GHtmlBox* self); 
	void (*delegate_on_paint)(GHtmlBox* self, GGraphics * g); 
	void (*delegate_on_layout)(GHtmlBox* self); 
};

typedef struct
{
	gpointer self;
	GHttpMethod method;
	gstring uri;
	GHashTable * parameters;
} GHtmlLoaderData;

struct _GHtmlView
{
	gstring uri;
	gboolean need_relayout;
	GXmlNode * root;

	GWidget * host;
	GHtmlBox * body;
	GPtrArray * styles;
	GPtrArray * css_rules;
	GPtrArray * css_properties;
	GPtrArray * css_to_free;
	GArray * css_uris;

	grect viewport;
	GHtmlItem * focused_item;
	GArray * focusable_items;
	GPtrArray * loaded_images;
	GPtrArray * uncacheable_images;

	GEvent * event_submit;
	GWidget * (*delegate_on_create_widget)(GHtmlView * self, GXmlNode * node, GHtmlStyle * style);
	void (*delegate_on_build_params_for_widget)(GHtmlView * self, GHashTable * params, GWidget * widget);
	gstring (*delegate_on_normalize_uri)(GHtmlView * self, gstring base_uri, gstring uri);
};

GHtmlView * g_html_view_new();
void g_html_view_free(GHtmlView * self);
GHashTable * g_html_parse_css_properties_in_place(gstring css);
void g_html_view_add_css_rule(GHtmlView * self, gstring css, gboolean inplace, gboolean needfree, gstring cssuri);
void g_html_view_paint(GHtmlView * self, GGraphics * g);
void g_html_view_load_html(GHtmlView * self, gstring uri, gstring html, gboolean inplace);
void g_html_view_parse(GHtmlView * self);

// if there is <body scroll="no"> return FALSE, otherwise return TRUE
gboolean g_html_view_is_scrollable(GHtmlView * self);

void g_html_view_do_layout(GHtmlView * self);
void g_html_view_relayout_wrapper(GHtmlView * self, GHtmlBox * box);
void g_html_view_relayout_block(GHtmlView * self, GHtmlBox * box);
void g_html_view_relayout_table(GHtmlView * self, GHtmlBox * box);
void g_html_view_set_focused_item(GHtmlView * view, GHtmlItem * hi);

gstring g_normalize_uri(gstring base_uri, gstring uri);
gstring g_html_view_normalize_uri(GHtmlView * self, gstring base_uri, gstring uri);
gboolean g_html_view_is_item_focused(GHtmlView * self, GHtmlItem * hi);
gint g_html_view_get_focused_item_index(GHtmlView * self);
void g_html_view_add_focusable_item(GHtmlItem * item, gint x, gint y);
void g_html_view_build_params(GHtmlView * self, GHashTable * params, GWidget * button);
gint g_html_length_get_px(GHtmlBox * parent, GHtmlLength * len, gint deflen, gboolean horizontal);
gstring g_html_node_get_attribute_as_string(GXmlNode * self, gstring name, gstring def);
gint g_html_node_get_attribute_as_int(GXmlNode * self, gstring name, gint def);
void g_html_view_apply_css_rule(GHtmlView * self, GHtmlStyle * style, GXmlNode * node, gstring peudoclass);

void g_html_view_reset(GHtmlView * self);
void g_html_view_delete_uncacheable_images(GHtmlView * self);
GWidget* g_html_view_create_widget(GHtmlView * self, GXmlNode * node, GHtmlStyle * style);
void g_html_view_build_params_for_widget(GHtmlView * self, GHashTable * params, GWidget * widget);

GHtmlTextSegment * g_html_text_segment_new();
void g_html_text_segment_free(GHtmlTextSegment * self);
GHtmlLine * g_html_line_new();
void g_html_line_free(GHtmlLine * self);
GHtmlStyle * g_html_style_new();
GHtmlStyle * g_html_style_copy(GHtmlView * view, gint style_no);
void g_html_style_free(GHtmlStyle * self);
GHtmlCssRule * g_html_css_rule_new();
void g_html_css_rule_free(GHtmlCssRule * cssrule);
GHtmlItem * g_html_item_new();
void g_html_item_free(GHtmlItem * self);
GHtmlBox * g_html_box_new(GHtmlView * view, GHtmlBoxType type, GHtmlBox * parent_box, GXmlNode * node);
void g_html_box_free(GHtmlBox * self);

void g_html_view_print_layout(GHtmlView * self);
#endif