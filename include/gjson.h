#ifndef _G_JSON_H_
#define _G_JSON_H_

#include "gvalue.h"
#include "gstream.h"

#ifdef __cplusplus
extern "C" {
#pragma }
#endif /* __cplusplus */
GValue* g_json_new_object();
GValue* g_json_parse_uri(gstring uri);
GValue* g_json_parse_uri_in_place(gstring uri);
GValue* g_json_parse(gchar* json_buffer);
GValue* g_json_parse_in_place(gchar* json_buffer);
gchar* g_json_to_string(GValue *);
const gchar* g_json_get_last_error(void);
void g_json_save_to_file(GValue * val, gstring filename, gboolean encrypt);
void g_json_save_to_stream(GValue * val, GStream * stream);

#ifdef __cplusplus
}
#endif /* __cplusplus */

#endif