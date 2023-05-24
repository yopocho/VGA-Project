/*
 * drawtext.c
 *
 *  Created on: 17 mei 2023
 *      Author: Sjoerd
 */

#include <fonts/drawtext.h>
#include <main.h>

int8_t FindGlyph(char c)
{
	uint8_t index = 0;

	// return 127 if it found a space, there's no glyph available for space character
	if (c == ' ')
		return 127;

	// look through ASCII array of glyphs until array end indicator (0)
	while (glyphs_ascii_list[index] != 0)
	{
		if (c == glyphs_ascii_list[index])
			return index;	// found the character
		else
			index++;
	}

	return -1;	// error: character glyph not found in ASCII array of glyphs
}

void DrawGlyph(int8_t index_glyph, int16_t x1, int16_t y1, uint8_t color, uint8_t fontSize, const uint8_t *fontBitmap, const font_glyph_desc *fontDesc)
{
	uint8_t byte_pixels = 0;			   // byte with 8 monochrome pixel bits of font glyph

	uint8_t width_px = fontDesc[index_glyph].width_px;
	short byte_index = fontDesc[index_glyph].offset;

	// draw STANDARD_FONT_SIZE * width pixels (font_size: 0 = 16px height)
	// or (STANDARD_FONT_SIZE*2) * (width*2) pixels (font_size: 1 = 32px height)
	for (int16_t ypos = 0; ypos < (STANDARD_FONT_SIZE * fontSize); ypos++)
	{
		for (int16_t xpos = 0; xpos < (width_px * fontSize); xpos++)
		{
			if (xpos & (7 + 8 * (fontSize-1)))
			{
				if (fontSize == 1)
					byte_pixels <<= 1;		// bit shift left after each xpos increment
				else if (fontSize == 2)
					byte_pixels <<= 1 - (xpos % 2);		// bit shift left every other xpos increment to double size horizontally
			}
			else
			{
				byte_pixels = fontBitmap[byte_index];
				byte_index++; // increment every 8 or 16 steps
			}

			// draw pixel with color if MSB is set
			if (byte_pixels & 0x80)
				UB_VGA_SetPixel(xpos + x1, ypos + y1, color);
		}

		// repeat line when font_size is 2 to double size vertically
		if (ypos % 2 == 0 && fontSize == 2)
			byte_index -= (7 + width_px) / 8;
	}

}

uint16_t DrawText(uint16_t x1, uint16_t y1, uint8_t color, char *textString, char *fontName, uint8_t fontSize, char *fontStyle)
{
	uint8_t i = 0;
	int8_t index_glyph = 0;
	int16_t x_offset = 0;
	uint8_t width_px;

	const uint8_t *fontBitmap = NULL;				 	// pointer to specified font bitmap array
	const font_glyph_desc *fontDesc = NULL; 	// pointer to description of specified font bitmap array

	// combine fontName and fontStyle in single string for processing
	char font_type[20];
	memset(font_type, 0, 20);
	strcat(font_type, fontName);
	strcat(font_type, (char *)" ");
	strcat(font_type, fontStyle);

	uint8_t k = 0;
	while (font_types_list[k] != NULL)
	{
		// find correct fontname and type
		if (!strcmp(font_type, font_types_list[k]))
		{
			fontBitmap = font_bitmaps_list[k];
			fontDesc = font_dsc_list[k];
			break;
		}
		k++;
	}

	// font type not found in font_types_list array, so return error code

	while (*(textString + i) != '\0')
	{
		index_glyph = FindGlyph(*(textString + i));

		// invalid character received

		// space character received
		if (index_glyph == 127)
		{
			x_offset += 4 * fontSize;	// add space between glyphs
			i++;
			continue;	// go to next character in textString
		}

		DrawGlyph(index_glyph, x1 + x_offset, y1, color, fontSize, fontBitmap, fontDesc);	// test with different font types

		width_px = arial_regular_glyph_dsc[index_glyph].width_px;
		x_offset += (width_px * fontSize) + 1; 	// 1px room between subsequent glyphs

		// warning check: text glyphs out of bounds
		if ((x_offset + x1) < 0 || (x_offset + x1) > VGA_DISPLAY_X || (y1 + fontSize*16) < 0 || (y1 + fontSize*16) > VGA_DISPLAY_Y )
		i++;
	}
	return 0;
}
