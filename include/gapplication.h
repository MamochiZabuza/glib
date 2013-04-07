#ifndef _G_APPLICATION_H_
#define _G_APPLICATION_H_
#include "glib.h"
#include "gform.h"
#include "gimage.h"
#include "gevent.h"
typedef enum
{
	APP_RUN_MODE_BACKGROUND,
	APP_RUN_MODE_FOREGROUND,
	APP_RUN_MODE_SHARED_MODULE
} GAppRunMode;
#define APP_EVENTS_ENABLED
#ifdef APP_EVENTS_ENABLED
extern GEvent * event_app_on_show;
extern GEvent * event_app_on_hide;
extern GEvent * event_app_on_quit;
extern GEvent * event_app_on_push_message;

typedef struct  
{
	GForm * form;
} GFormEventArgs;

extern GEvent * event_app_form_on_push;
extern GEvent * event_app_form_on_pop;
extern GEvent * event_app_form_on_show;
extern GEvent * event_app_form_on_hide;
#endif
// command format 
// cmd:parameters
// for examples: run:c:\mre\app.vxp
// cmd length must less than 1024
void g_app_command_queue_push(gstring cmd);
gboolean g_app_command_queue_pop(gstring cmd);
gint g_app_command_queue_length(void);

void g_app_create_events(void);
void g_app_start(gboolean support_background, gint fps);
void g_app_exit(void);
void g_app_start_coroutines(void);

void g_app_start_in_shared_module(gint fps);
void g_app_exit_in_shared_module(void);
void g_app_delay_exit_in_shared_module(void);
gboolean g_app_is_foreground(void);
void g_app_run(gstring vxp_path);

void g_app_register_form(gstring name, GForm* form);
GForm* g_app_get_form(gstring name);
gstring g_app_get_form_name(GForm* form);
GForm* g_app_get_current_form(void);
void g_app_set_current_form(GForm* form);
void g_app_push_form(GForm * form);
void g_app_pop_form(void);
void g_app_pop_form_to(GForm * form);
GList * g_app_get_form_stack(void);
void g_app_force_paint(void);

#endif


