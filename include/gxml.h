#ifndef _G_XML_H_
#define _G_XML_H_
#include "glib.h"

typedef void * GXmlNode;

void g_xml_set_html_mode(gboolean mode);
gboolean g_xml_is_html_single_tag(const gstring tag);
GXmlNode * g_xml_parse(const gstring xml);
GXmlNode * g_xml_parse_in_place(gstring xml);
GXmlNode * g_xml_parse_in_place_shared(gstring xml);

GXmlNode * g_xml_get_root(GXmlNode * self);
GXmlNode * g_xml_get_parent(GXmlNode * self);
GXmlNode * g_xml_get_next(GXmlNode * self);
GXmlNode * g_xml_get_next_with_the_same_name(GXmlNode * self);
GXmlNode * g_xml_get_child(GXmlNode * self);
GXmlNode * g_xml_get_last_child(GXmlNode * self);
GXmlNode * g_xml_get_by_path(GXmlNode * self, gstring path);

GXmlNode * g_xml_new(gstring name);
void g_xml_set_text(GXmlNode * self, gstring text);
void g_xml_set_attribute(GXmlNode * self, gstring name, gstring val);
void g_xml_remove(GXmlNode * self);
GXmlNode * g_xml_add(GXmlNode * self, GXmlNode * child);

gstring g_xml_get_name(GXmlNode * self);
gstring g_xml_get_text(GXmlNode * self);
gstring g_xml_get_attribute(GXmlNode * self, gstring name);
gint g_xml_get_attribute_count(GXmlNode * self);
void g_xml_get_attribute_by_index(GXmlNode * self, gint index, gstring * name, gstring * val);

void g_xml_get_first_text_segment(GXmlNode * self, gstring * text, gint * len);
void g_xml_get_next_text_segment(GXmlNode * self, gstring * text, gint * len);

void g_xml_destroy(GXmlNode * node);
gstring g_xml_to_string(GXmlNode * node);

#ifdef _WIN32
void g_xml_print(GXmlNode * node);
#else
#define g_xml_print
#endif
#endif