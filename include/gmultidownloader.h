#ifndef _G_MULTI_DOWNLOADER_H_
#define _G_MULTI_DOWNLOADER_H_

#include "ghttp.h"

typedef void (*DOWNLOADING_FUNC)(GHttpSession * session, gstring url, gstring path, gpointer data);
typedef void (*DOWNLOADED_FUNC)(GHttpSession * session, gstring url, gstring path, gpointer data);

typedef struct
{
	GList * items;
} GMultiDownloader;

typedef struct  
{
	GMultiDownloader * downloader;
	gstring url;
	gstring path;
	gint retry;
	GHttpSession * session;
	DOWNLOADING_FUNC downloading;
	DOWNLOADED_FUNC downloaded;
	gpointer data;
	gboolean resuming;
}GMultiDownloaderItem;


GMultiDownloader * g_multi_downloader_new(void);
void g_multi_downloader_free(GMultiDownloader * self);
GMultiDownloaderItem * g_multi_downloader_add_task(GMultiDownloader * self, gstring url, gstring path, gpointer data, DOWNLOADED_FUNC downloaded, DOWNLOADING_FUNC downloading);
GMultiDownloaderItem * g_multi_downloader_add_resuming_task(GMultiDownloader * self, gstring url, gstring path, gpointer data, DOWNLOADED_FUNC downloaded, DOWNLOADING_FUNC downloading);
GMultiDownloaderItem * g_multi_downloader_get_task(GMultiDownloader * self, gstring url);
void g_multi_downloader_remove_task(GMultiDownloader * self, gstring url);

#endif