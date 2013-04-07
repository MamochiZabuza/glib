#ifndef _G_IMAGE_MANAGER_H_
#define _G_IMAGE_MANAGER_H_
#include "glib.h"
#include "gevent.h"
#include "gimage.h"

typedef enum
{
	IMAGE_BUFFER_TYPE_RES,
	IMAGE_BUFFER_TYPE_FILE,
	IMAGE_BUFFER_TYPE_PACKAGE,
	IMAGE_BUFFER_TYPE_HTTP,
	IMAGE_BUFFER_TYPE_IN_MEMORY
}GBufferedImageType;

typedef struct  
{
	gstring uri;
	GEvent * event_on_loaded;
} GBufferedImage;

typedef struct
{
	gstring uri;
} GImageLoadedEventArgs;

void g_image_manager_use_single_thread_download(void);

void g_image_manager_cache_resources(gboolean cache);
gboolean g_image_manager_is_loaded(gstring uri);
void g_image_manager_add_image_loaded_listener(gstring uri, EVENT_CALLBACK callback, gpointer data);
GBufferedImage* g_image_manager_look_for(gstring uri);
GBufferedImage* g_image_manager_get(gstring uri);
GBufferedImage* g_image_manager_add_in_memory_image(gstring uri, GImage* img);
GImage* g_image_manager_load(gstring uri);
GImage* g_image_manager_lite_load(gstring uri);
void g_image_manager_unload(gstring uri);
void g_image_manager_free(gstring uri);
GImage* g_image_manager_load_resized(gstring uri, gint w, gint h);
GImage* g_image_manager_lite_load_resized(gstring uri, gint w, gint h);

void g_image_manager_category_begin(gstring cat);
void g_image_manager_category_end(void);
void g_image_manager_category_unload(gstring cat);
void g_image_manager_category_free(gstring cat);
gint g_image_manager_category_get_image_count(gstring cat);

void g_image_manager_unload_all(void);
void g_image_manager_free_all(void);

GBufferedImage* g_buffered_image_new(gstring uri);
GImage* g_buffered_image_load(GBufferedImage * img, gint w, gint h);
GImage* g_buffered_image_lite_load(GBufferedImage * img, gint w, gint h);
void g_buffered_image_release_image(GBufferedImage * img);
gboolean g_buffered_image_is_cacheable(GBufferedImage * img);

void g_image_manager_set_cache_path(gstring path);
gstring g_image_manager_get_cache_file(gstring uri);

void g_image_manager_set_default_uri_prefix(gstring prefix);

#endif