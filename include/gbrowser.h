#ifndef _G_BROWSER_H_
#define _G_BROWSER_H_
#include "gwidget.h"
#include "ghtmlview.h"
#include "gdownloader.h"
#define GBROWSER(p) ((GBrowser *)(p))
#define GBROWSERCLASS(p) ((GBrowserClass *)(p))
typedef struct _GBrowser GBrowser;
typedef struct _GBrowserClass GBrowserClass;

#define BROWSER_ERROR_FAILS_TO_LOAD_HTML	-1
#define BROWSER_ERROR_OUT_OF_MEMORY			-2

struct _GBrowser
{
	GWidget base;
	GHtmlView * html_view;
	GDownloader * css_downloader;
	gstring cache_path;
	gpoint pen_down_position;
	gint pen_down_scrollbar_offset;
	gint pen_move_max_scrollbar_offset_change;
	GTouchState touch_state;

	GCoroutine * html_loader;
	GHttpSession * current_session;

	gint max_css_size;
	gint max_html_size;
	gboolean mem_leak_test;

	gint load_percent;
	gstring uri_to_history;
	GPtrArray * history;
	GArray * history_of_scroll;
	GHashTable * cookies;
	GHashTable * preset_headers;
	gboolean enable_page_mode;
	void (*delegate_on_draw_scrollbar)(gpointer self, GGraphics * g);
	gboolean (*delegate_on_load_uri)(gpointer self, GHttpMethod method, gstring uri, GHashTable * params);

	void (*delegate_on_progress_changed)(gpointer self, gint percent);
	void (*delegate_on_title_changed)(gpointer self, gstring title);
	void (*delegate_on_error_occurred)(gpointer self, gint error_code, gstring * error_page);
};
struct _GBrowserClass
{
	GWidgetClass base;
};
gstring g_browser_get_title(gpointer self);
void g_browser_load_uri(gpointer self, gstring uri);
void g_browser_load_uri_with_params(gpointer self, GHttpMethod method, gstring uri, GHashTable * params);
gboolean g_browser_back(gpointer self);
void g_browser_reload(gpointer self);
void g_browser_release(gpointer self);

void g_browser_set_focus(gpointer self, gint fi);
void g_browser_on_focused_item_click(gpointer self);
void g_browser_do_layout(gpointer self);
void g_browser_on_paint(gpointer self, GGraphics * g);
void g_browser_on_key_up(gpointer self, gint keycode);
void g_browser_on_key_down(gpointer self, gint keycode);
void g_browser_on_key_repeat(gpointer self, gint keycode);
void g_browser_on_pen_up(gpointer self, gint x, gint y);
void g_browser_on_pen_down(gpointer self, gint x, gint y);
void g_browser_on_pen_move(gpointer self, gint x, gint y);
void g_browser_on_pen_click(gpointer self, gint x, gint y);
void g_browser_show_error(gpointer self, gint error_code);

gpointer g_get_class_GBrowser(void);

void g_browser_init(gpointer self);
void g_browser_finalize(gpointer self);
void g_browser_class_init(gpointer clazz);

#endif