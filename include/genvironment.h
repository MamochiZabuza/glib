#ifndef _G_ENVIRONMENT_H_
#define _G_ENVIRONMENT_H_
#include "glib.h"

gstring g_environment_get_user_agent(void);
gstring g_environment_get_imsi(void);
gstring g_environment_get_imei(void);
gstring g_environment_get_mcc(void);
gstring g_environment_get_sms_center(void);


void g_environment_set_user_agent(gstring ua);
void g_environment_set_imsi(gstring imsi);
void g_environment_set_imei(gstring imei);
void g_environment_set_sms_center(gstring smsc);

#endif