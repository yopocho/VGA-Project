/*
 * fonts.h
 *
 *  Created on: 31 mei 2023
 *      Author: Sjoerd
 */

#ifndef UB_LIB_FONTS_FONTS_H_
#define UB_LIB_FONTS_FONTS_H_

#include <stdio.h>
#include <stdint.h>

/*! Struct for storing bitmap information about glyphs (font characters) */
typedef struct _font_glyph_desc
{
	uint8_t width_px;        /*!< Width in pixels of the glyph */
	uint16_t offset;         /*!< Byte offset of the glyph in the bitmap array */
} font_glyph_desc;


// extern variables
extern const uint32_t glyphs_ascii_list[];

extern const uint8_t arial_normal_bitmap[];
extern const uint8_t arial_bold_bitmap[];
extern const uint8_t arial_cursive_bitmap[];
extern const uint8_t consolas_normal_bitmap[];
extern const uint8_t consolas_bold_bitmap[];
extern const uint8_t consolas_cursive_bitmap[];

extern const font_glyph_desc arial_normal_glyph_dsc[];
extern const font_glyph_desc arial_bold_glyph_dsc[];
extern const font_glyph_desc arial_cursive_glyph_dsc[];
extern const font_glyph_desc consolas_normal_glyph_dsc[];
extern const font_glyph_desc consolas_bold_glyph_dsc[];
extern const font_glyph_desc consolas_cursive_glyph_dsc[];

extern const char *font_types_list[];
extern const uint8_t *font_bitmaps_list[];
extern const font_glyph_desc *font_dsc_list[];

#endif /* UB_LIB_FONTS_FONTS_H_ */
