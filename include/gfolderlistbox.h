#ifndef _G_FOLDER_LIST_BOX_H_
#define _G_FOLDER_LIST_BOX_H_
#include "glistbox.h"
#define GFOLDERLISTBOX(p) ((GFolderListBox *)(p))
#define GFOLDERLISTBOXCLASS(p) ((GFolderListBoxClass *)(p))
typedef struct _GFolderListBox GFolderListBox;
typedef struct _GFolderListBoxClass GFolderListBoxClass;

typedef struct 
{
	gboolean visible;
	gboolean expanded;
	gpointer data;
	GPtrArray * items;
} GFolderListBoxItem;

struct _GFolderListBox
{
	GListBox base;
	GPtrArray * folders;
};
struct _GFolderListBoxClass
{
	GListBoxClass base;
};

GFolderListBoxItem * g_folder_list_box_get_parent_folder(gpointer self, void* item);
gboolean g_folder_list_box_is_folder(gpointer self, gpointer data);
void g_folder_list_box_update_items(gpointer self);

gpointer g_get_class_GFolderListBox(void);
void g_folder_list_box_init(gpointer self);
void g_folder_list_box_finalize(gpointer self);
void g_folder_list_box_class_init(gpointer clazz);

GFolderListBoxItem * g_folder_list_box_new(gpointer data);
void g_folder_list_box_free(GFolderListBoxItem * folder);

#endif