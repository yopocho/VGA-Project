/*
 * consolasfont.h
 *
 *  Created on: 17 mei 2023
 *      Author: Sjoerd
 */

#ifndef UB_LIB_CONSOLASFONT_H_
#define UB_LIB_CONSOLASFONT_H_

#include <drawtext.h>

// Consolas (regular) 16 px font, with 1 bit per pixel
// only these characters: !,.?ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz
// .ttf file (font files) converted to bitmap array with https://lvgl.io/tools/font_conv_v5_3

// Store the image of the letters (glyph)
const uint8_t consolas_normal_bitmap[] =
{
	/*ASCII: 0021 (!) , Width: 3 */
	0x00, //...
	0x00, //...
	0x40, //.%.
	0x40, //.%.
	0x40, //.%.
	0x40, //.%.
	0x40, //.%.
	0x40, //.%.
	0x40, //.%.
	0x40, //.%.
	0x00, //...
	0x40, //.%.
	0x40, //.%.
	0x00, //...
	0x00, //...
	0x00, //...

	/*ASCII: 002c (,) , Width: 5 */
	0x00, //.....
	0x00, //.....
	0x00, //.....
	0x00, //.....
	0x00, //.....
	0x00, //.....
	0x00, //.....
	0x00, //.....
	0x00, //.....
	0x00, //.....
	0x00, //.....
	0x30, //..%%.
	0x18, //...%%
	0x10, //...%.
	0x30, //..%%.
	0x60, //.%%..

	/*ASCII: 002e (.) , Width: 3 */
	0x00, //...
	0x00, //...
	0x00, //...
	0x00, //...
	0x00, //...
	0x00, //...
	0x00, //...
	0x00, //...
	0x00, //...
	0x00, //...
	0x00, //...
	0xc0, //%%.
	0xc0, //%%.
	0x00, //...
	0x00, //...
	0x00, //...

	/*ASCII: 003f (?) , Width: 6 */
	0x00, //......
	0x00, //......
	0xe0, //%%%...
	0x30, //..%%..
	0x18, //...%%.
	0x08, //....%.
	0x18, //...%%.
	0x70, //.%%%..
	0x40, //.%....
	0x40, //.%....
	0x00, //......
	0x60, //.%%...
	0x60, //.%%...
	0x00, //......
	0x00, //......
	0x00, //......

	/*ASCII: 0041 (A) , Width: 9 */
	0x00, 0x00, //.........
	0x00, 0x00, //.........
	0x00, 0x00, //.........
	0x1c, 0x00, //...%%%...
	0x1c, 0x00, //...%%%...
	0x14, 0x00, //...%.%...
	0x36, 0x00, //..%%.%%..
	0x26, 0x00, //..%..%%..
	0x22, 0x00, //..%...%..
	0x63, 0x00, //.%%...%%.
	0x7f, 0x00, //.%%%%%%%.
	0x41, 0x00, //.%.....%.
	0xc1, 0x80, //%%.....%%
	0x00, 0x00, //.........
	0x00, 0x00, //.........
	0x00, 0x00, //.........

	/*ASCII: 0042 (B) , Width: 7 */
	0x00, //.......
	0x00, //.......
	0x00, //.......
	0xf8, //%%%%%..
	0xc4, //%%...%.
	0xc6, //%%...%%
	0xc4, //%%...%.
	0xfc, //%%%%%%.
	0xc6, //%%...%%
	0xc6, //%%...%%
	0xc6, //%%...%%
	0xc4, //%%...%.
	0xf8, //%%%%%..
	0x00, //.......
	0x00, //.......
	0x00, //.......

	/*ASCII: 0043 (C) , Width: 8 */
	0x00, //........
	0x00, //........
	0x00, //........
	0x1e, //...%%%%.
	0x31, //..%%...%
	0x60, //.%%.....
	0x40, //.%......
	0x40, //.%......
	0x40, //.%......
	0x40, //.%......
	0x60, //.%%.....
	0x31, //..%%...%
	0x1e, //...%%%%.
	0x00, //........
	0x00, //........
	0x00, //........

	/*ASCII: 0044 (D) , Width: 9 */
	0x00, 0x00, //.........
	0x00, 0x00, //.........
	0x00, 0x00, //.........
	0x7c, 0x00, //.%%%%%...
	0x46, 0x00, //.%...%%..
	0x43, 0x00, //.%....%%.
	0x41, 0x00, //.%.....%.
	0x41, 0x00, //.%.....%.
	0x41, 0x00, //.%.....%.
	0x41, 0x00, //.%.....%.
	0x43, 0x00, //.%....%%.
	0x46, 0x00, //.%...%%..
	0x7c, 0x00, //.%%%%%...
	0x00, 0x00, //.........
	0x00, 0x00, //.........
	0x00, 0x00, //.........

	/*ASCII: 0045 (E) , Width: 7 */
	0x00, //.......
	0x00, //.......
	0x00, //.......
	0x7c, //.%%%%%.
	0x40, //.%.....
	0x40, //.%.....
	0x40, //.%.....
	0x7c, //.%%%%%.
	0x40, //.%.....
	0x40, //.%.....
	0x40, //.%.....
	0x40, //.%.....
	0x7c, //.%%%%%.
	0x00, //.......
	0x00, //.......
	0x00, //.......

	/*ASCII: 0046 (F) , Width: 7 */
	0x00, //.......
	0x00, //.......
	0x00, //.......
	0x7c, //.%%%%%.
	0x40, //.%.....
	0x40, //.%.....
	0x40, //.%.....
	0x40, //.%.....
	0x7c, //.%%%%%.
	0x40, //.%.....
	0x40, //.%.....
	0x40, //.%.....
	0x40, //.%.....
	0x00, //.......
	0x00, //.......
	0x00, //.......

	/*ASCII: 0047 (G) , Width: 8 */
	0x00, //........
	0x00, //........
	0x00, //........
	0x1e, //...%%%%.
	0x31, //..%%...%
	0x60, //.%%.....
	0x40, //.%......
	0x40, //.%......
	0x4f, //.%..%%%%
	0x41, //.%.....%
	0x61, //.%%....%
	0x23, //..%...%%
	0x1f, //...%%%%%
	0x00, //........
	0x00, //........
	0x00, //........

	/*ASCII: 0048 (H) , Width: 8 */
	0x00, //........
	0x00, //........
	0x00, //........
	0x41, //.%.....%
	0x41, //.%.....%
	0x41, //.%.....%
	0x41, //.%.....%
	0x7f, //.%%%%%%%
	0x41, //.%.....%
	0x41, //.%.....%
	0x41, //.%.....%
	0x41, //.%.....%
	0x41, //.%.....%
	0x00, //........
	0x00, //........
	0x00, //........

	/*ASCII: 0049 (I) , Width: 7 */
	0x00, //.......
	0x00, //.......
	0x00, //.......
	0xfc, //%%%%%%.
	0x10, //...%...
	0x10, //...%...
	0x10, //...%...
	0x10, //...%...
	0x10, //...%...
	0x10, //...%...
	0x10, //...%...
	0x10, //...%...
	0xfc, //%%%%%%.
	0x00, //.......
	0x00, //.......
	0x00, //.......

	/*ASCII: 004a (J) , Width: 6 */
	0x00, //......
	0x00, //......
	0x00, //......
	0x7c, //.%%%%%
	0x0c, //....%%
	0x0c, //....%%
	0x0c, //....%%
	0x0c, //....%%
	0x0c, //....%%
	0x0c, //....%%
	0x0c, //....%%
	0x08, //....%.
	0x70, //.%%%..
	0x00, //......
	0x00, //......
	0x00, //......

	/*ASCII: 004b (K) , Width: 8 */
	0x00, //........
	0x00, //........
	0x00, //........
	0xc6, //%%...%%.
	0xcc, //%%..%%..
	0xc8, //%%..%...
	0xd0, //%%.%....
	0xe0, //%%%.....
	0xe0, //%%%.....
	0xd0, //%%.%....
	0xd8, //%%.%%...
	0xcc, //%%..%%..
	0xc6, //%%...%%.
	0x00, //........
	0x00, //........
	0x00, //........

	/*ASCII: 004c (L) , Width: 7 */
	0x00, //.......
	0x00, //.......
	0x00, //.......
	0x40, //.%.....
	0x40, //.%.....
	0x40, //.%.....
	0x40, //.%.....
	0x40, //.%.....
	0x40, //.%.....
	0x40, //.%.....
	0x40, //.%.....
	0x40, //.%.....
	0x7e, //.%%%%%%
	0x00, //.......
	0x00, //.......
	0x00, //.......

	/*ASCII: 004d (M) , Width: 9 */
	0x00, 0x00, //.........
	0x00, 0x00, //.........
	0x00, 0x00, //.........
	0x63, 0x00, //.%%...%%.
	0x63, 0x00, //.%%...%%.
	0x65, 0x00, //.%%..%.%.
	0x55, 0x00, //.%.%.%.%.
	0x55, 0x00, //.%.%.%.%.
	0x59, 0x00, //.%.%%..%.
	0x49, 0x00, //.%..%..%.
	0x41, 0x00, //.%.....%.
	0xc1, 0x00, //%%.....%.
	0xc1, 0x00, //%%.....%.
	0x00, 0x00, //.........
	0x00, 0x00, //.........
	0x00, 0x00, //.........

	/*ASCII: 004e (N) , Width: 8 */
	0x00, //........
	0x00, //........
	0x00, //........
	0x61, //.%%....%
	0x61, //.%%....%
	0x51, //.%.%...%
	0x51, //.%.%...%
	0x49, //.%..%..%
	0x49, //.%..%..%
	0x45, //.%...%.%
	0x45, //.%...%.%
	0x47, //.%...%%%
	0x43, //.%....%%
	0x00, //........
	0x00, //........
	0x00, //........

	/*ASCII: 004f (O) , Width: 9 */
	0x00, 0x00, //.........
	0x00, 0x00, //.........
	0x00, 0x00, //.........
	0x1c, 0x00, //...%%%...
	0x63, 0x00, //.%%...%%.
	0x43, 0x00, //.%....%%.
	0x41, 0x00, //.%.....%.
	0xc1, 0x00, //%%.....%.
	0x41, 0x00, //.%.....%.
	0x41, 0x00, //.%.....%.
	0x43, 0x00, //.%....%%.
	0x62, 0x00, //.%%...%..
	0x3c, 0x00, //..%%%%...
	0x00, 0x00, //.........
	0x00, 0x00, //.........
	0x00, 0x00, //.........

	/*ASCII: 0050 (P) , Width: 7 */
	0x00, //.......
	0x00, //.......
	0x00, //.......
	0xf8, //%%%%%..
	0xc6, //%%...%%
	0xc6, //%%...%%
	0xc6, //%%...%%
	0xc4, //%%...%.
	0xf8, //%%%%%..
	0xc0, //%%.....
	0xc0, //%%.....
	0xc0, //%%.....
	0xc0, //%%.....
	0x00, //.......
	0x00, //.......
	0x00, //.......

	/*ASCII: 0051 (Q) , Width: 9 */
	0x00, 0x00, //.........
	0x00, 0x00, //.........
	0x00, 0x00, //.........
	0x1c, 0x00, //...%%%...
	0x63, 0x00, //.%%...%%.
	0x43, 0x00, //.%....%%.
	0x41, 0x00, //.%.....%.
	0xc1, 0x00, //%%.....%.
	0xc1, 0x00, //%%.....%.
	0x41, 0x00, //.%.....%.
	0x43, 0x00, //.%....%%.
	0x62, 0x00, //.%%...%..
	0x3c, 0x00, //..%%%%...
	0x08, 0x00, //....%....
	0x0c, 0x00, //....%%...
	0x07, 0x00, //.....%%%.

	/*ASCII: 0052 (R) , Width: 8 */
	0x00, //........
	0x00, //........
	0x00, //........
	0xf8, //%%%%%...
	0xc4, //%%...%..
	0xc4, //%%...%..
	0xcc, //%%..%%..
	0xf8, //%%%%%...
	0xc8, //%%..%...
	0xc8, //%%..%...
	0xc4, //%%...%..
	0xc4, //%%...%..
	0xc6, //%%...%%.
	0x00, //........
	0x00, //........
	0x00, //........

	/*ASCII: 0053 (S) , Width: 8 */
	0x00, //........
	0x00, //........
	0x00, //........
	0x1e, //...%%%%.
	0x60, //.%%.....
	0x60, //.%%.....
	0x60, //.%%.....
	0x38, //..%%%...
	0x0e, //....%%%.
	0x03, //......%%
	0x03, //......%%
	0x02, //......%.
	0x7c, //.%%%%%..
	0x00, //........
	0x00, //........
	0x00, //........

	/*ASCII: 0054 (T) , Width: 9 */
	0x00, 0x00, //.........
	0x00, 0x00, //.........
	0x00, 0x00, //.........
	0x7f, 0x00, //.%%%%%%%.
	0x08, 0x00, //....%....
	0x08, 0x00, //....%....
	0x08, 0x00, //....%....
	0x08, 0x00, //....%....
	0x08, 0x00, //....%....
	0x08, 0x00, //....%....
	0x08, 0x00, //....%....
	0x08, 0x00, //....%....
	0x08, 0x00, //....%....
	0x00, 0x00, //.........
	0x00, 0x00, //.........
	0x00, 0x00, //.........

	/*ASCII: 0055 (U) , Width: 8 */
	0x00, //........
	0x00, //........
	0x00, //........
	0x41, //.%.....%
	0x41, //.%.....%
	0x41, //.%.....%
	0x41, //.%.....%
	0x41, //.%.....%
	0x41, //.%.....%
	0x41, //.%.....%
	0x43, //.%....%%
	0x62, //.%%...%.
	0x3c, //..%%%%..
	0x00, //........
	0x00, //........
	0x00, //........

	/*ASCII: 0056 (V) , Width: 9 */
	0x00, 0x00, //.........
	0x00, 0x00, //.........
	0x00, 0x00, //.........
	0xc1, 0x80, //%%.....%%
	0x41, 0x00, //.%.....%.
	0x43, 0x00, //.%....%%.
	0x63, 0x00, //.%%...%%.
	0x22, 0x00, //..%...%..
	0x26, 0x00, //..%..%%..
	0x36, 0x00, //..%%.%%..
	0x14, 0x00, //...%.%...
	0x1c, 0x00, //...%%%...
	0x18, 0x00, //...%%....
	0x00, 0x00, //.........
	0x00, 0x00, //.........
	0x00, 0x00, //.........

	/*ASCII: 0057 (W) , Width: 9 */
	0x00, 0x00, //.........
	0x00, 0x00, //.........
	0x00, 0x00, //.........
	0xc1, 0x00, //%%.....%.
	0xc1, 0x00, //%%.....%.
	0x41, 0x00, //.%.....%.
	0x49, 0x00, //.%..%..%.
	0x59, 0x00, //.%.%%..%.
	0x55, 0x00, //.%.%.%.%.
	0x55, 0x00, //.%.%.%.%.
	0x55, 0x00, //.%.%.%.%.
	0x67, 0x00, //.%%..%%%.
	0x63, 0x00, //.%%...%%.
	0x00, 0x00, //.........
	0x00, 0x00, //.........
	0x00, 0x00, //.........

	/*ASCII: 0058 (X) , Width: 9 */
	0x00, 0x00, //.........
	0x00, 0x00, //.........
	0x00, 0x00, //.........
	0x43, 0x00, //.%....%%.
	0x62, 0x00, //.%%...%..
	0x36, 0x00, //..%%.%%..
	0x1c, 0x00, //...%%%...
	0x18, 0x00, //...%%....
	0x1c, 0x00, //...%%%...
	0x3c, 0x00, //..%%%%...
	0x26, 0x00, //..%..%%..
	0x63, 0x00, //.%%...%%.
	0xc1, 0x00, //%%.....%.
	0x00, 0x00, //.........
	0x00, 0x00, //.........
	0x00, 0x00, //.........

	/*ASCII: 0059 (Y) , Width: 9 */
	0x00, 0x00, //.........
	0x00, 0x00, //.........
	0x00, 0x00, //.........
	0xc1, 0x00, //%%.....%.
	0x63, 0x00, //.%%...%%.
	0x22, 0x00, //..%...%..
	0x36, 0x00, //..%%.%%..
	0x1c, 0x00, //...%%%...
	0x18, 0x00, //...%%....
	0x08, 0x00, //....%....
	0x08, 0x00, //....%....
	0x08, 0x00, //....%....
	0x08, 0x00, //....%....
	0x00, 0x00, //.........
	0x00, 0x00, //.........
	0x00, 0x00, //.........

	/*ASCII: 005a (Z) , Width: 8 */
	0x00, //........
	0x00, //........
	0x00, //........
	0x7f, //.%%%%%%%
	0x02, //......%.
	0x06, //.....%%.
	0x04, //.....%..
	0x08, //....%...
	0x18, //...%%...
	0x10, //...%....
	0x30, //..%%....
	0x20, //..%.....
	0x7f, //.%%%%%%%
	0x00, //........
	0x00, //........
	0x00, //........

	/*ASCII: 0061 (a) , Width: 7 */
	0x00, //.......
	0x00, //.......
	0x00, //.......
	0x00, //.......
	0x00, //.......
	0x00, //.......
	0x38, //..%%%..
	0x44, //.%...%.
	0x06, //.....%%
	0x7e, //.%%%%%%
	0xc6, //%%...%%
	0xce, //%%..%%%
	0x7e, //.%%%%%%
	0x00, //.......
	0x00, //.......
	0x00, //.......

	/*ASCII: 0062 (b) , Width: 7 */
	0x00, //.......
	0x00, //.......
	0xc0, //%%.....
	0xc0, //%%.....
	0xc0, //%%.....
	0xc0, //%%.....
	0xfc, //%%%%%%.
	0xe6, //%%%..%%
	0xc6, //%%...%%
	0xc2, //%%....%
	0xc6, //%%...%%
	0xc4, //%%...%.
	0x78, //.%%%%..
	0x00, //.......
	0x00, //.......
	0x00, //.......

	/*ASCII: 0063 (c) , Width: 7 */
	0x00, //.......
	0x00, //.......
	0x00, //.......
	0x00, //.......
	0x00, //.......
	0x00, //.......
	0x3c, //..%%%%.
	0x60, //.%%....
	0xc0, //%%.....
	0xc0, //%%.....
	0xc0, //%%.....
	0x60, //.%%....
	0x3c, //..%%%%.
	0x00, //.......
	0x00, //.......
	0x00, //.......

	/*ASCII: 0064 (d) , Width: 8 */
	0x00, //........
	0x00, //........
	0x03, //......%%
	0x03, //......%%
	0x03, //......%%
	0x03, //......%%
	0x1f, //...%%%%%
	0x23, //..%...%%
	0x43, //.%....%%
	0x43, //.%....%%
	0x43, //.%....%%
	0x67, //.%%..%%%
	0x3b, //..%%%.%%
	0x00, //........
	0x00, //........
	0x00, //........

	/*ASCII: 0065 (e) , Width: 8 */
	0x00, //........
	0x00, //........
	0x00, //........
	0x00, //........
	0x00, //........
	0x00, //........
	0x1c, //...%%%..
	0x22, //..%...%.
	0x43, //.%....%%
	0x7f, //.%%%%%%%
	0x40, //.%......
	0x60, //.%%.....
	0x1e, //...%%%%.
	0x00, //........
	0x00, //........
	0x00, //........

	/*ASCII: 0066 (f) , Width: 9 */
	0x00, 0x00, //.........
	0x00, 0x00, //.........
	0x0f, 0x00, //....%%%%.
	0x18, 0x00, //...%%....
	0x18, 0x00, //...%%....
	0x18, 0x00, //...%%....
	0x7f, 0x00, //.%%%%%%%.
	0x18, 0x00, //...%%....
	0x18, 0x00, //...%%....
	0x18, 0x00, //...%%....
	0x18, 0x00, //...%%....
	0x18, 0x00, //...%%....
	0x18, 0x00, //...%%....
	0x00, 0x00, //.........
	0x00, 0x00, //.........
	0x00, 0x00, //.........

	/*ASCII: 0067 (g) , Width: 9 */
	0x00, 0x00, //.........
	0x00, 0x00, //.........
	0x00, 0x00, //.........
	0x00, 0x00, //.........
	0x00, 0x00, //.........
	0x00, 0x00, //.........
	0x3f, 0x00, //..%%%%%%.
	0x26, 0x00, //..%..%%..
	0x62, 0x00, //.%%...%..
	0x66, 0x00, //.%%..%%..
	0x3c, 0x00, //..%%%%...
	0x60, 0x00, //.%%......
	0x7e, 0x00, //.%%%%%%..
	0x43, 0x00, //.%....%%.
	0x43, 0x00, //.%....%%.
	0x3e, 0x00, //..%%%%%..

	/*ASCII: 0068 (h) , Width: 7 */
	0x00, //.......
	0x00, //.......
	0xc0, //%%.....
	0xc0, //%%.....
	0xc0, //%%.....
	0xc0, //%%.....
	0xfc, //%%%%%%.
	0xe4, //%%%..%.
	0xc6, //%%...%%
	0xc6, //%%...%%
	0xc6, //%%...%%
	0xc6, //%%...%%
	0xc6, //%%...%%
	0x00, //.......
	0x00, //.......
	0x00, //.......

	/*ASCII: 0069 (i) , Width: 7 */
	0x00, //.......
	0x00, //.......
	0x10, //...%...
	0x10, //...%...
	0x00, //.......
	0x00, //.......
	0x70, //.%%%...
	0x10, //...%...
	0x10, //...%...
	0x10, //...%...
	0x10, //...%...
	0x10, //...%...
	0xfe, //%%%%%%%
	0x00, //.......
	0x00, //.......
	0x00, //.......

	/*ASCII: 006a (j) , Width: 6 */
	0x00, //......
	0x00, //......
	0x0c, //....%%
	0x0c, //....%%
	0x00, //......
	0x00, //......
	0xfc, //%%%%%%
	0x0c, //....%%
	0x0c, //....%%
	0x0c, //....%%
	0x0c, //....%%
	0x0c, //....%%
	0x0c, //....%%
	0x08, //....%.
	0x88, //%...%.
	0x70, //.%%%..

	/*ASCII: 006b (k) , Width: 8 */
	0x00, //........
	0x00, //........
	0xc0, //%%......
	0xc0, //%%......
	0xc0, //%%......
	0xc0, //%%......
	0xc4, //%%...%..
	0xd8, //%%.%%...
	0xf0, //%%%%....
	0xf0, //%%%%....
	0xd8, //%%.%%...
	0xcc, //%%..%%..
	0xc6, //%%...%%.
	0x00, //........
	0x00, //........
	0x00, //........

	/*ASCII: 006c (l) , Width: 7 */
	0x00, //.......
	0x00, //.......
	0x70, //.%%%...
	0x10, //...%...
	0x10, //...%...
	0x10, //...%...
	0x10, //...%...
	0x10, //...%...
	0x10, //...%...
	0x10, //...%...
	0x10, //...%...
	0x10, //...%...
	0xfe, //%%%%%%%
	0x00, //.......
	0x00, //.......
	0x00, //.......

	/*ASCII: 006d (m) , Width: 9 */
	0x00, 0x00, //.........
	0x00, 0x00, //.........
	0x00, 0x00, //.........
	0x00, 0x00, //.........
	0x00, 0x00, //.........
	0x00, 0x00, //.........
	0x7b, 0x00, //.%%%%.%%.
	0x6d, 0x00, //.%%.%%.%.
	0x49, 0x00, //.%..%..%.
	0x49, 0x00, //.%..%..%.
	0x49, 0x00, //.%..%..%.
	0x49, 0x00, //.%..%..%.
	0x49, 0x00, //.%..%..%.
	0x00, 0x00, //.........
	0x00, 0x00, //.........
	0x00, 0x00, //.........

	/*ASCII: 006e (n) , Width: 7 */
	0x00, //.......
	0x00, //.......
	0x00, //.......
	0x00, //.......
	0x00, //.......
	0x00, //.......
	0xfc, //%%%%%%.
	0xe4, //%%%..%.
	0xc6, //%%...%%
	0xc6, //%%...%%
	0xc6, //%%...%%
	0xc6, //%%...%%
	0xc6, //%%...%%
	0x00, //.......
	0x00, //.......
	0x00, //.......

	/*ASCII: 006f (o) , Width: 9 */
	0x00, 0x00, //.........
	0x00, 0x00, //.........
	0x00, 0x00, //.........
	0x00, 0x00, //.........
	0x00, 0x00, //.........
	0x00, 0x00, //.........
	0x1c, 0x00, //...%%%...
	0x63, 0x00, //.%%...%%.
	0x41, 0x00, //.%.....%.
	0x41, 0x00, //.%.....%.
	0x41, 0x00, //.%.....%.
	0x62, 0x00, //.%%...%..
	0x3c, 0x00, //..%%%%...
	0x00, 0x00, //.........
	0x00, 0x00, //.........
	0x00, 0x00, //.........

	/*ASCII: 0070 (p) , Width: 7 */
	0x00, //.......
	0x00, //.......
	0x00, //.......
	0x00, //.......
	0x00, //.......
	0x00, //.......
	0xfc, //%%%%%%.
	0xe6, //%%%..%%
	0xc6, //%%...%%
	0xc2, //%%....%
	0xc6, //%%...%%
	0xc4, //%%...%.
	0xf8, //%%%%%..
	0xc0, //%%.....
	0xc0, //%%.....
	0xc0, //%%.....

	/*ASCII: 0071 (q) , Width: 8 */
	0x00, //........
	0x00, //........
	0x00, //........
	0x00, //........
	0x00, //........
	0x00, //........
	0x1e, //...%%%%.
	0x23, //..%...%%
	0x43, //.%....%%
	0x43, //.%....%%
	0x43, //.%....%%
	0x67, //.%%..%%%
	0x3b, //..%%%.%%
	0x03, //......%%
	0x03, //......%%
	0x03, //......%%

	/*ASCII: 0072 (r) , Width: 7 */
	0x00, //.......
	0x00, //.......
	0x00, //.......
	0x00, //.......
	0x00, //.......
	0x00, //.......
	0x5c, //.%.%%%.
	0x66, //.%%..%%
	0x42, //.%....%
	0x40, //.%.....
	0x40, //.%.....
	0x40, //.%.....
	0x40, //.%.....
	0x00, //.......
	0x00, //.......
	0x00, //.......

	/*ASCII: 0073 (s) , Width: 7 */
	0x00, //.......
	0x00, //.......
	0x00, //.......
	0x00, //.......
	0x00, //.......
	0x00, //.......
	0x3c, //..%%%%.
	0x40, //.%.....
	0x40, //.%.....
	0x38, //..%%%..
	0x04, //.....%.
	0x04, //.....%.
	0xf8, //%%%%%..
	0x00, //.......
	0x00, //.......
	0x00, //.......

	/*ASCII: 0074 (t) , Width: 8 */
	0x00, //........
	0x00, //........
	0x00, //........
	0x10, //...%....
	0x10, //...%....
	0x10, //...%....
	0x7f, //.%%%%%%%
	0x10, //...%....
	0x10, //...%....
	0x10, //...%....
	0x10, //...%....
	0x10, //...%....
	0x0f, //....%%%%
	0x00, //........
	0x00, //........
	0x00, //........

	/*ASCII: 0075 (u) , Width: 7 */
	0x00, //.......
	0x00, //.......
	0x00, //.......
	0x00, //.......
	0x00, //.......
	0x00, //.......
	0xc6, //%%...%%
	0xc6, //%%...%%
	0xc6, //%%...%%
	0xc6, //%%...%%
	0xc6, //%%...%%
	0xce, //%%..%%%
	0x76, //.%%%.%%
	0x00, //.......
	0x00, //.......
	0x00, //.......

	/*ASCII: 0076 (v) , Width: 9 */
	0x00, 0x00, //.........
	0x00, 0x00, //.........
	0x00, 0x00, //.........
	0x00, 0x00, //.........
	0x00, 0x00, //.........
	0x00, 0x00, //.........
	0x41, 0x00, //.%.....%.
	0x63, 0x00, //.%%...%%.
	0x22, 0x00, //..%...%..
	0x26, 0x00, //..%..%%..
	0x34, 0x00, //..%%.%...
	0x1c, 0x00, //...%%%...
	0x18, 0x00, //...%%....
	0x00, 0x00, //.........
	0x00, 0x00, //.........
	0x00, 0x00, //.........

	/*ASCII: 0077 (w) , Width: 9 */
	0x00, 0x00, //.........
	0x00, 0x00, //.........
	0x00, 0x00, //.........
	0x00, 0x00, //.........
	0x00, 0x00, //.........
	0x00, 0x00, //.........
	0xc1, 0x00, //%%.....%.
	0x41, 0x00, //.%.....%.
	0x49, 0x00, //.%..%..%.
	0x59, 0x00, //.%.%%..%.
	0x55, 0x00, //.%.%.%.%.
	0x77, 0x00, //.%%%.%%%.
	0x62, 0x00, //.%%...%..
	0x00, 0x00, //.........
	0x00, 0x00, //.........
	0x00, 0x00, //.........

	/*ASCII: 0078 (x) , Width: 9 */
	0x00, 0x00, //.........
	0x00, 0x00, //.........
	0x00, 0x00, //.........
	0x00, 0x00, //.........
	0x00, 0x00, //.........
	0x00, 0x00, //.........
	0x63, 0x00, //.%%...%%.
	0x36, 0x00, //..%%.%%..
	0x1c, 0x00, //...%%%...
	0x1c, 0x00, //...%%%...
	0x14, 0x00, //...%.%...
	0x26, 0x00, //..%..%%..
	0x63, 0x00, //.%%...%%.
	0x00, 0x00, //.........
	0x00, 0x00, //.........
	0x00, 0x00, //.........

	/*ASCII: 0079 (y) , Width: 9 */
	0x00, 0x00, //.........
	0x00, 0x00, //.........
	0x00, 0x00, //.........
	0x00, 0x00, //.........
	0x00, 0x00, //.........
	0x00, 0x00, //.........
	0x41, 0x00, //.%.....%.
	0x63, 0x00, //.%%...%%.
	0x22, 0x00, //..%...%..
	0x26, 0x00, //..%..%%..
	0x14, 0x00, //...%.%...
	0x1c, 0x00, //...%%%...
	0x18, 0x00, //...%%....
	0x18, 0x00, //...%%....
	0x10, 0x00, //...%.....
	0xe0, 0x00, //%%%......

	/*ASCII: 007a (z) , Width: 7 */
	0x00, //.......
	0x00, //.......
	0x00, //.......
	0x00, //.......
	0x00, //.......
	0x00, //.......
	0xfc, //%%%%%%.
	0x08, //....%..
	0x08, //....%..
	0x10, //...%...
	0x20, //..%....
	0x40, //.%.....
	0xfe, //%%%%%%%
	0x00, //.......
	0x00, //.......
	0x00, //.......

};

#endif /* UB_LIB_CONSOLASFONT_H_ */
