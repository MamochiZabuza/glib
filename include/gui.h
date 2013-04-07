#ifndef __G_UI_H__
#define __G_UI_H__

#include "glib.h"
#include "vmio.h"

#define VK_UP VM_KEY_UP  
#define VK_DOWN VM_KEY_DOWN   
#define VK_LEFT VM_KEY_LEFT         
#define VK_RIGHT VM_KEY_RIGHT      
#define VK_LEFT_SOFTKEY VM_KEY_LEFT_SOFTKEY  
#define VK_RIGHT_SOFTKEY VM_KEY_RIGHT_SOFTKEY 
#define VK_OK VM_KEY_OK        
#define VK_CLEAR VM_KEY_CLEAR  
#define VK_BACK VM_KEY_BACK   
#define VK_NUM0 VM_KEY_NUM0 
#define VK_NUM1 VM_KEY_NUM1   
#define VK_NUM2 VM_KEY_NUM2   
#define VK_NUM3 VM_KEY_NUM3         
#define VK_NUM4 VM_KEY_NUM4  
#define VK_NUM5 VM_KEY_NUM5    
#define VK_NUM6 VM_KEY_NUM6   
#define VK_NUM7 VM_KEY_NUM7  
#define VK_NUM8 VM_KEY_NUM8     
#define VK_NUM9 VM_KEY_NUM9       
#define VK_VOL_UP VM_KEY_VOL_UP        
#define VK_VOL_DOWN VM_KEY_VOL_DOWN      
#define VK_POUND VM_KEY_POUND        /* Key # */
#define VK_STAR VM_KEY_STAR          /* Key * */

typedef guint32 gcolor;
#define COLOR_TRANSPARENT 0x01234567

#define COLOR_TO_565(i) ((((((i) >> 16) & 0xFF) << 8) & 0xF800) | (((((i) >> 8) & 0xFF) << 3) & 0x7E0)  | ((((i) & 0xFF) >> 3)))

#define FONT_STYLE_PLAIN 0
#define FONT_STYLE_BOLD 1
#define FONT_STYLE_ITALIC 2
#define FONT_STYLE_UNDERLINED 4

#define FONT g_font_get_default()


typedef enum
{
	DOCK_STYLE_NONE, 
	DOCK_STYLE_TOP,
	DOCK_STYLE_BOTTOM,
	DOCK_STYLE_LEFT,
	DOCK_STYLE_RIGHT,
	DOCK_STYLE_FILL
}GDockStyle;

typedef enum
{
	ANCHOR_TYPE_NONE = 0,
	ANCHOR_TYPE_LEFT = 1,
	ANCHOR_TYPE_CENTER = 2,
	ANCHOR_TYPE_RIGHT = 4,
	ANCHOR_TYPE_TOP = 8,
	ANCHOR_TYPE_MIDDLE = 16,
	ANCHOR_TYPE_BOTTOM = 32
}GAnchorType;

typedef enum
{
	DIRECTION_UP,
	DIRECTION_DOWN,
	DIRECTION_LEFT,
	DIRECTION_RIGHT
}GDirection;


typedef enum
{
	TEXT_ALIGN_LEFT = 0,
	TEXT_ALIGN_RIGHT,
	TEXT_ALIGN_CENTER,
	TEXT_ALIGN_JUSTIFY
}GTextAlignment;

typedef enum
{
	VERTICAL_ALIGN_TOP = 0,
	VERTICAL_ALIGN_BOTTOM,
	VERTICAL_ALIGN_MIDDLE
}GVerticalAlignment;

typedef enum
{
	TOUCH_STATE_STOPPED,
	TOUCH_STATE_PRESSED,
	TOUCH_STATE_DRAGGING,
	TOUCH_STATE_SCROLLING
}GTouchState;

typedef struct 
{
	gint size;
	gint style;
} gfont;

typedef struct
{
	gboolean consumed;
	gint keycode;
} GKeyEventArgs;

typedef struct
{
	gboolean consumed;
	gint x;
	gint y;
} GPenEventArgs;

gfont g_font_get(gint size, gint fs);
gint g_font_get_string_width(gfont f, gwstring str);
gint g_font_get_string_height(gfont f, gwstring str);
gint g_font_get_string_baseline(gfont f, gwstring str);
gint g_font_get_height(gfont f);
gint g_font_get_baseline(gfont f);
gfont g_font_get_default(void);
void g_font_set_default(gfont f);
void g_font_reset(void);

gint g_get_screen_width(void);
gint g_get_screen_height(void);
void g_set_screen_width(gint w);
void g_set_screen_height(gint h);
void g_set_screen_size(gint w, gint h);
void g_refresh_screen(void);

void g_cursor_load(gstring uri);
void g_cursor_move_to(gint x, gint y);
void g_cursor_hide(void);
gint g_cursor_get_width(void);
gint g_cursor_get_height(void);


typedef void (*GHintPaintFunc)(gpointer graphics, gint x, gint y, gstring text, GDirection dir);
void g_hint_hide(void);
void g_hint_show_at(gint x, gint y, gstring text, GDirection dir, gint delay, gint duration);
void g_hint_set_style(gfont font, gcolor forecolor, gcolor backcolor, gcolor border_color);
void g_hint_set_custom_painter(GHintPaintFunc func);

#endif
