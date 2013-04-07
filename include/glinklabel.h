#ifndef _G_LINK_LABEL_H_
#define _G_LINK_LABEL_H_
#include "glabel.h"

#define GLINKLABEL(p) ((GLinkLabel *)(p))
#define GLINKLABELCLASS(p) ((GLinkLabelClass *)(p))
typedef struct _GLinkLabel GLinkLabel;
typedef struct _GLinkLabelClass GLinkLabelClass;

struct _GLinkLabel
{
	GLabel base;
};
struct _GLinkLabelClass
{
	GLabelClass base;
};

gpointer g_get_class_GLinkLabel(void);

void g_link_label_init(gpointer self);
void g_link_label_finalize(gpointer self);
void g_link_label_class_init(gpointer clazz);

#endif