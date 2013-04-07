#ifndef _G_LZW_H_
#define _G_LZW_H_
#include "gstream.h"

void g_lzw_compress(GStream *input,GStream *output);
void g_lzw_decompress(GStream *input,GStream *output);
void g_lzw_release();

#endif