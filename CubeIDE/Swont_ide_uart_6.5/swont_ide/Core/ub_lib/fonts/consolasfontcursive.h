/*
 * consolasfontcursive.h
 *
 *  Created on: 24 mei 2023
 *      Author: Sjoerd
 */

#ifndef UB_LIB_FONTS_CONSOLASFONTCURSIVE_H_
#define UB_LIB_FONTS_CONSOLASFONTCURSIVE_H_

// Consolas (cursive) 16 px font, with 1 bit per pixel
// only these characters: !,.?ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz
// .ttf file (font files) converted to bitmap array with https://lvgl.io/tools/font_conv_v5_3

// Store the image of the letters (glyph)
const uint8_t consolas_cursive_bitmap[] =
{
	/*ASCII: 0021 (!) , Width: 5 */
	0x00,  //.....
	0x00,  //.....
	0x10,  //...%.
	0x10,  //...%.
	0x10,  //...%.
	0x30,  //..%%.
	0x30,  //..%%.
	0x20,  //..%..
	0x20,  //..%..
	0x20,  //..%..
	0x00,  //.....
	0x60,  //.%%..
	0x60,  //.%%..
	0x00,  //.....
	0x00,  //.....
	0x00,  //.....


	/*ASCII: 002c (,) , Width: 5 */
	0x00,  //.....
	0x00,  //.....
	0x00,  //.....
	0x00,  //.....
	0x00,  //.....
	0x00,  //.....
	0x00,  //.....
	0x00,  //.....
	0x00,  //.....
	0x00,  //.....
	0x00,  //.....
	0x18,  //...%%
	0x18,  //...%%
	0x18,  //...%%
	0x30,  //..%%.
	0x60,  //.%%..


	/*ASCII: 002e (.) , Width: 3 */
	0x00,  //...
	0x00,  //...
	0x00,  //...
	0x00,  //...
	0x00,  //...
	0x00,  //...
	0x00,  //...
	0x00,  //...
	0x00,  //...
	0x00,  //...
	0x00,  //...
	0x60,  //.%%
	0x60,  //.%%
	0x00,  //...
	0x00,  //...
	0x00,  //...


	/*ASCII: 003f (?) , Width: 6 */
	0x00,  //......
	0x00,  //......
	0x30,  //..%%..
	0x08,  //....%.
	0x0c,  //....%%
	0x0c,  //....%%
	0x0c,  //....%%
	0x70,  //.%%%..
	0x60,  //.%%...
	0x40,  //.%....
	0x00,  //......
	0xc0,  //%%....
	0xc0,  //%%....
	0x00,  //......
	0x00,  //......
	0x00,  //......


	/*ASCII: 0041 (A) , Width: 8 */
	0x00,  //........
	0x00,  //........
	0x00,  //........
	0x0e,  //....%%%.
	0x0e,  //....%%%.
	0x1a,  //...%%.%.
	0x12,  //...%..%.
	0x32,  //..%%..%.
	0x22,  //..%...%.
	0x62,  //.%%...%.
	0x7f,  //.%%%%%%%
	0xc3,  //%%....%%
	0x83,  //%.....%%
	0x00,  //........
	0x00,  //........
	0x00,  //........


	/*ASCII: 0042 (B) , Width: 9 */
	0x00, 0x00,  //.........
	0x00, 0x00,  //.........
	0x00, 0x00,  //.........
	0x3f, 0x00,  //..%%%%%%.
	0x31, 0x00,  //..%%...%.
	0x21, 0x00,  //..%....%.
	0x23, 0x00,  //..%...%%.
	0x3e, 0x00,  //..%%%%%..
	0x63, 0x00,  //.%%...%%.
	0x43, 0x00,  //.%....%%.
	0x43, 0x00,  //.%....%%.
	0x46, 0x00,  //.%...%%..
	0x7c, 0x00,  //.%%%%%...
	0x00, 0x00,  //.........
	0x00, 0x00,  //.........
	0x00, 0x00,  //.........


	/*ASCII: 0043 (C) , Width: 9 */
	0x00, 0x00,  //.........
	0x00, 0x00,  //.........
	0x00, 0x00,  //.........
	0x0f, 0x00,  //....%%%%.
	0x18, 0x80,  //...%%...%
	0x30, 0x00,  //..%%.....
	0x60, 0x00,  //.%%......
	0x60, 0x00,  //.%%......
	0x40, 0x00,  //.%.......
	0x40, 0x00,  //.%.......
	0x40, 0x00,  //.%.......
	0x62, 0x00,  //.%%...%..
	0x3c, 0x00,  //..%%%%...
	0x00, 0x00,  //.........
	0x00, 0x00,  //.........
	0x00, 0x00,  //.........


	/*ASCII: 0044 (D) , Width: 9 */
	0x00, 0x00,  //.........
	0x00, 0x00,  //.........
	0x00, 0x00,  //.........
	0x3e, 0x00,  //..%%%%%..
	0x23, 0x00,  //..%...%%.
	0x21, 0x00,  //..%....%.
	0x61, 0x00,  //.%%....%.
	0x61, 0x00,  //.%%....%.
	0x41, 0x00,  //.%.....%.
	0x41, 0x00,  //.%.....%.
	0x42, 0x00,  //.%....%..
	0xc6, 0x00,  //%%...%%..
	0xf8, 0x00,  //%%%%%....
	0x00, 0x00,  //.........
	0x00, 0x00,  //.........
	0x00, 0x00,  //.........


	/*ASCII: 0045 (E) , Width: 9 */
	0x00, 0x00,  //.........
	0x00, 0x00,  //.........
	0x00, 0x00,  //.........
	0x1f, 0x80,  //...%%%%%%
	0x10, 0x00,  //...%.....
	0x30, 0x00,  //..%%.....
	0x20, 0x00,  //..%......
	0x3e, 0x00,  //..%%%%%..
	0x20, 0x00,  //..%......
	0x60, 0x00,  //.%%......
	0x60, 0x00,  //.%%......
	0x40, 0x00,  //.%.......
	0x7e, 0x00,  //.%%%%%%..
	0x00, 0x00,  //.........
	0x00, 0x00,  //.........
	0x00, 0x00,  //.........


	/*ASCII: 0046 (F) , Width: 9 */
	0x00, 0x00,  //.........
	0x00, 0x00,  //.........
	0x00, 0x00,  //.........
	0x1f, 0x00,  //...%%%%%.
	0x10, 0x00,  //...%.....
	0x30, 0x00,  //..%%.....
	0x20, 0x00,  //..%......
	0x3e, 0x00,  //..%%%%%..
	0x20, 0x00,  //..%......
	0x20, 0x00,  //..%......
	0x20, 0x00,  //..%......
	0x20, 0x00,  //..%......
	0x20, 0x00,  //..%......
	0x00, 0x00,  //.........
	0x00, 0x00,  //.........
	0x00, 0x00,  //.........


	/*ASCII: 0047 (G) , Width: 9 */
	0x00, 0x00,  //.........
	0x00, 0x00,  //.........
	0x00, 0x00,  //.........
	0x0f, 0x00,  //....%%%%.
	0x18, 0x80,  //...%%...%
	0x20, 0x00,  //..%......
	0x60, 0x00,  //.%%......
	0x47, 0x00,  //.%...%%%.
	0x41, 0x00,  //.%.....%.
	0x43, 0x00,  //.%....%%.
	0x43, 0x00,  //.%....%%.
	0x62, 0x00,  //.%%...%..
	0x3e, 0x00,  //..%%%%%..
	0x00, 0x00,  //.........
	0x00, 0x00,  //.........
	0x00, 0x00,  //.........


	/*ASCII: 0048 (H) , Width: 10 */
	0x00, 0x00,  //..........
	0x00, 0x00,  //..........
	0x00, 0x00,  //..........
	0x20, 0x80,  //..%.....%.
	0x21, 0x80,  //..%....%%.
	0x21, 0x80,  //..%....%%.
	0x61, 0x00,  //.%%....%..
	0x7f, 0x00,  //.%%%%%%%..
	0x41, 0x00,  //.%.....%..
	0x43, 0x00,  //.%....%%..
	0x43, 0x00,  //.%....%%..
	0xc2, 0x00,  //%%....%...
	0xc2, 0x00,  //%%....%...
	0x00, 0x00,  //..........
	0x00, 0x00,  //..........
	0x00, 0x00,  //..........


	/*ASCII: 0049 (I) , Width: 9 */
	0x00, 0x00,  //.........
	0x00, 0x00,  //.........
	0x00, 0x00,  //.........
	0x3f, 0x80,  //..%%%%%%%
	0x04, 0x00,  //.....%...
	0x0c, 0x00,  //....%%...
	0x0c, 0x00,  //....%%...
	0x08, 0x00,  //....%....
	0x08, 0x00,  //....%....
	0x08, 0x00,  //....%....
	0x18, 0x00,  //...%%....
	0x18, 0x00,  //...%%....
	0x7e, 0x00,  //.%%%%%%..
	0x00, 0x00,  //.........
	0x00, 0x00,  //.........
	0x00, 0x00,  //.........


	/*ASCII: 004a (J) , Width: 9 */
	0x00, 0x00,  //.........
	0x00, 0x00,  //.........
	0x00, 0x00,  //.........
	0x1f, 0x00,  //...%%%%%.
	0x03, 0x00,  //......%%.
	0x03, 0x00,  //......%%.
	0x02, 0x00,  //......%..
	0x02, 0x00,  //......%..
	0x02, 0x00,  //......%..
	0x06, 0x00,  //.....%%..
	0x04, 0x00,  //.....%...
	0x4c, 0x00,  //.%..%%...
	0x78, 0x00,  //.%%%%....
	0x00, 0x00,  //.........
	0x00, 0x00,  //.........
	0x00, 0x00,  //.........


	/*ASCII: 004b (K) , Width: 10 */
	0x00, 0x00,  //..........
	0x00, 0x00,  //..........
	0x00, 0x00,  //..........
	0x31, 0x80,  //..%%...%%.
	0x33, 0x00,  //..%%..%%..
	0x26, 0x00,  //..%..%%...
	0x2c, 0x00,  //..%.%%....
	0x38, 0x00,  //..%%%.....
	0x70, 0x00,  //.%%%......
	0x68, 0x00,  //.%%.%.....
	0x4c, 0x00,  //.%..%%....
	0x44, 0x00,  //.%...%....
	0x46, 0x00,  //.%...%%...
	0x00, 0x00,  //..........
	0x00, 0x00,  //..........
	0x00, 0x00,  //..........


	/*ASCII: 004c (L) , Width: 7 */
	0x00,  //.......
	0x00,  //.......
	0x00,  //.......
	0x20,  //..%....
	0x20,  //..%....
	0x20,  //..%....
	0x60,  //.%%....
	0x60,  //.%%....
	0x40,  //.%.....
	0x40,  //.%.....
	0x40,  //.%.....
	0xc0,  //%%.....
	0xfc,  //%%%%%%.
	0x00,  //.......
	0x00,  //.......
	0x00,  //.......


	/*ASCII: 004d (M) , Width: 10 */
	0x00, 0x00,  //..........
	0x00, 0x00,  //..........
	0x00, 0x00,  //..........
	0x31, 0x80,  //..%%...%%.
	0x31, 0x80,  //..%%...%%.
	0x72, 0x80,  //.%%%..%.%.
	0x52, 0x80,  //.%.%..%.%.
	0x55, 0x00,  //.%.%.%.%..
	0x59, 0x00,  //.%.%%..%..
	0xc9, 0x00,  //%%..%..%..
	0x81, 0x00,  //%......%..
	0x81, 0x00,  //%......%..
	0x83, 0x00,  //%.....%%..
	0x00, 0x00,  //..........
	0x00, 0x00,  //..........
	0x00, 0x00,  //..........


	/*ASCII: 004e (N) , Width: 10 */
	0x00, 0x00,  //..........
	0x00, 0x00,  //..........
	0x00, 0x00,  //..........
	0x30, 0x80,  //..%%....%.
	0x31, 0x80,  //..%%...%%.
	0x39, 0x80,  //..%%%..%%.
	0x69, 0x00,  //.%%.%..%..
	0x69, 0x00,  //.%%.%..%..
	0x49, 0x00,  //.%..%..%..
	0x4d, 0x00,  //.%..%%.%..
	0x47, 0x00,  //.%...%%%..
	0xc6, 0x00,  //%%...%%...
	0xc6, 0x00,  //%%...%%...
	0x00, 0x00,  //..........
	0x00, 0x00,  //..........
	0x00, 0x00,  //..........


	/*ASCII: 004f (O) , Width: 9 */
	0x00, 0x00,  //.........
	0x00, 0x00,  //.........
	0x00, 0x00,  //.........
	0x0e, 0x00,  //....%%%..
	0x31, 0x00,  //..%%...%.
	0x21, 0x80,  //..%....%%
	0x61, 0x80,  //.%%....%%
	0x41, 0x80,  //.%.....%%
	0x41, 0x00,  //.%.....%.
	0x41, 0x00,  //.%.....%.
	0x43, 0x00,  //.%....%%.
	0x66, 0x00,  //.%%..%%..
	0x3c, 0x00,  //..%%%%...
	0x00, 0x00,  //.........
	0x00, 0x00,  //.........
	0x00, 0x00,  //.........


	/*ASCII: 0050 (P) , Width: 9 */
	0x00, 0x00,  //.........
	0x00, 0x00,  //.........
	0x00, 0x00,  //.........
	0x3e, 0x00,  //..%%%%%..
	0x31, 0x00,  //..%%...%.
	0x21, 0x80,  //..%....%%
	0x21, 0x00,  //..%....%.
	0x23, 0x00,  //..%...%%.
	0x7c, 0x00,  //.%%%%%...
	0x40, 0x00,  //.%.......
	0x40, 0x00,  //.%.......
	0x40, 0x00,  //.%.......
	0x40, 0x00,  //.%.......
	0x00, 0x00,  //.........
	0x00, 0x00,  //.........
	0x00, 0x00,  //.........


	/*ASCII: 0051 (Q) , Width: 9 */
	0x00, 0x00,  //.........
	0x00, 0x00,  //.........
	0x00, 0x00,  //.........
	0x0e, 0x00,  //....%%%..
	0x31, 0x00,  //..%%...%.
	0x21, 0x80,  //..%....%%
	0x61, 0x80,  //.%%....%%
	0x41, 0x80,  //.%.....%%
	0x41, 0x00,  //.%.....%.
	0x41, 0x00,  //.%.....%.
	0x43, 0x00,  //.%....%%.
	0x66, 0x00,  //.%%..%%..
	0x3c, 0x00,  //..%%%%...
	0x10, 0x00,  //...%.....
	0x18, 0x00,  //...%%....
	0x0e, 0x00,  //....%%%..


	/*ASCII: 0052 (R) , Width: 9 */
	0x00, 0x00,  //.........
	0x00, 0x00,  //.........
	0x00, 0x00,  //.........
	0x3e, 0x00,  //..%%%%%..
	0x33, 0x00,  //..%%..%%.
	0x21, 0x00,  //..%....%.
	0x23, 0x00,  //..%...%%.
	0x22, 0x00,  //..%...%..
	0x7c, 0x00,  //.%%%%%...
	0x64, 0x00,  //.%%..%...
	0x46, 0x00,  //.%...%%..
	0x46, 0x00,  //.%...%%..
	0x42, 0x00,  //.%....%..
	0x00, 0x00,  //.........
	0x00, 0x00,  //.........
	0x00, 0x00,  //.........


	/*ASCII: 0053 (S) , Width: 9 */
	0x00, 0x00,  //.........
	0x00, 0x00,  //.........
	0x00, 0x00,  //.........
	0x0f, 0x00,  //....%%%%.
	0x30, 0x00,  //..%%.....
	0x20, 0x00,  //..%......
	0x30, 0x00,  //..%%.....
	0x18, 0x00,  //...%%....
	0x0e, 0x00,  //....%%%..
	0x02, 0x00,  //......%..
	0x02, 0x00,  //......%..
	0x06, 0x00,  //.....%%..
	0x7c, 0x00,  //.%%%%%...
	0x00, 0x00,  //.........
	0x00, 0x00,  //.........
	0x00, 0x00,  //.........


	/*ASCII: 0054 (T) , Width: 9 */
	0x00, 0x00,  //.........
	0x00, 0x00,  //.........
	0x00, 0x00,  //.........
	0x7f, 0x00,  //.%%%%%%%.
	0x08, 0x00,  //....%....
	0x18, 0x00,  //...%%....
	0x18, 0x00,  //...%%....
	0x10, 0x00,  //...%.....
	0x10, 0x00,  //...%.....
	0x10, 0x00,  //...%.....
	0x30, 0x00,  //..%%.....
	0x30, 0x00,  //..%%.....
	0x20, 0x00,  //..%......
	0x00, 0x00,  //.........
	0x00, 0x00,  //.........
	0x00, 0x00,  //.........


	/*ASCII: 0055 (U) , Width: 10 */
	0x00, 0x00,  //..........
	0x00, 0x00,  //..........
	0x00, 0x00,  //..........
	0x20, 0x80,  //..%.....%.
	0x20, 0x80,  //..%.....%.
	0x21, 0x80,  //..%....%%.
	0x61, 0x00,  //.%%....%..
	0x61, 0x00,  //.%%....%..
	0x41, 0x00,  //.%.....%..
	0x43, 0x00,  //.%....%%..
	0x42, 0x00,  //.%....%...
	0x46, 0x00,  //.%...%%...
	0x3c, 0x00,  //..%%%%....
	0x00, 0x00,  //..........
	0x00, 0x00,  //..........
	0x00, 0x00,  //..........


	/*ASCII: 0056 (V) , Width: 9 */
	0x00, 0x00,  //.........
	0x00, 0x00,  //.........
	0x00, 0x00,  //.........
	0xc1, 0x80,  //%%.....%%
	0xc1, 0x00,  //%%.....%.
	0x43, 0x00,  //.%....%%.
	0x42, 0x00,  //.%....%..
	0x46, 0x00,  //.%...%%..
	0x44, 0x00,  //.%...%...
	0x68, 0x00,  //.%%.%....
	0x78, 0x00,  //.%%%%....
	0x70, 0x00,  //.%%%.....
	0x30, 0x00,  //..%%.....
	0x00, 0x00,  //.........
	0x00, 0x00,  //.........
	0x00, 0x00,  //.........


	/*ASCII: 0057 (W) , Width: 10 */
	0x00, 0x00,  //..........
	0x00, 0x00,  //..........
	0x00, 0x00,  //..........
	0x20, 0xc0,  //..%.....%%
	0x60, 0x80,  //.%%.....%.
	0x40, 0x80,  //.%......%.
	0x48, 0x80,  //.%..%...%.
	0x4d, 0x00,  //.%..%%.%..
	0x5d, 0x00,  //.%.%%%.%..
	0x55, 0x00,  //.%.%.%.%..
	0x65, 0x00,  //.%%..%.%..
	0xe6, 0x00,  //%%%..%%...
	0xc6, 0x00,  //%%...%%...
	0x00, 0x00,  //..........
	0x00, 0x00,  //..........
	0x00, 0x00,  //..........


	/*ASCII: 0058 (X) , Width: 10 */
	0x00, 0x00,  //..........
	0x00, 0x00,  //..........
	0x00, 0x00,  //..........
	0x20, 0x80,  //..%.....%.
	0x31, 0x00,  //..%%...%..
	0x12, 0x00,  //...%..%...
	0x1e, 0x00,  //...%%%%...
	0x0c, 0x00,  //....%%....
	0x1c, 0x00,  //...%%%....
	0x3c, 0x00,  //..%%%%....
	0x66, 0x00,  //.%%..%%...
	0x46, 0x00,  //.%...%%...
	0xc3, 0x00,  //%%....%%..
	0x00, 0x00,  //..........
	0x00, 0x00,  //..........
	0x00, 0x00,  //..........


	/*ASCII: 0059 (Y) , Width: 9 */
	0x00, 0x00,  //.........
	0x00, 0x00,  //.........
	0x00, 0x00,  //.........
	0xc1, 0x80,  //%%.....%%
	0x43, 0x00,  //.%....%%.
	0x62, 0x00,  //.%%...%..
	0x24, 0x00,  //..%..%...
	0x2c, 0x00,  //..%.%%...
	0x38, 0x00,  //..%%%....
	0x10, 0x00,  //...%.....
	0x30, 0x00,  //..%%.....
	0x30, 0x00,  //..%%.....
	0x20, 0x00,  //..%......
	0x00, 0x00,  //.........
	0x00, 0x00,  //.........
	0x00, 0x00,  //.........


	/*ASCII: 005a (Z) , Width: 9 */
	0x00, 0x00,  //.........
	0x00, 0x00,  //.........
	0x00, 0x00,  //.........
	0x3f, 0x80,  //..%%%%%%%
	0x01, 0x00,  //.......%.
	0x02, 0x00,  //......%..
	0x06, 0x00,  //.....%%..
	0x0c, 0x00,  //....%%...
	0x18, 0x00,  //...%%....
	0x10, 0x00,  //...%.....
	0x20, 0x00,  //..%......
	0x60, 0x00,  //.%%......
	0xfe, 0x00,  //%%%%%%%..
	0x00, 0x00,  //.........
	0x00, 0x00,  //.........
	0x00, 0x00,  //.........


	/*ASCII: 0061 (a) , Width: 9 */
	0x00, 0x00,  //.........
	0x00, 0x00,  //.........
	0x00, 0x00,  //.........
	0x00, 0x00,  //.........
	0x00, 0x00,  //.........
	0x00, 0x00,  //.........
	0x1f, 0x00,  //...%%%%%.
	0x33, 0x00,  //..%%..%%.
	0x63, 0x00,  //.%%...%%.
	0x42, 0x00,  //.%....%..
	0x46, 0x00,  //.%...%%..
	0x4e, 0x00,  //.%..%%%..
	0x7a, 0x00,  //.%%%%.%..
	0x00, 0x00,  //.........
	0x00, 0x00,  //.........
	0x00, 0x00,  //.........


	/*ASCII: 0062 (b) , Width: 8 */
	0x00,  //........
	0x00,  //........
	0x10,  //...%....
	0x30,  //..%%....
	0x30,  //..%%....
	0x20,  //..%.....
	0x2e,  //..%.%%%.
	0x33,  //..%%..%%
	0x61,  //.%%....%
	0x63,  //.%%...%%
	0x43,  //.%....%%
	0x46,  //.%...%%.
	0x7c,  //.%%%%%..
	0x00,  //........
	0x00,  //........
	0x00,  //........


	/*ASCII: 0063 (c) , Width: 7 */
	0x00,  //.......
	0x00,  //.......
	0x00,  //.......
	0x00,  //.......
	0x00,  //.......
	0x00,  //.......
	0x1e,  //...%%%%
	0x60,  //.%%....
	0x40,  //.%.....
	0xc0,  //%%.....
	0xc0,  //%%.....
	0xc0,  //%%.....
	0x7c,  //.%%%%%.
	0x00,  //.......
	0x00,  //.......
	0x00,  //.......


	/*ASCII: 0064 (d) , Width: 9 */
	0x00, 0x00,  //.........
	0x00, 0x00,  //.........
	0x01, 0x80,  //.......%%
	0x01, 0x80,  //.......%%
	0x01, 0x00,  //.......%.
	0x01, 0x00,  //.......%.
	0x1f, 0x00,  //...%%%%%.
	0x33, 0x00,  //..%%..%%.
	0x63, 0x00,  //.%%...%%.
	0x42, 0x00,  //.%....%..
	0x46, 0x00,  //.%...%%..
	0x4e, 0x00,  //.%..%%%..
	0x7a, 0x00,  //.%%%%.%..
	0x00, 0x00,  //.........
	0x00, 0x00,  //.........
	0x00, 0x00,  //.........


	/*ASCII: 0065 (e) , Width: 8 */
	0x00,  //........
	0x00,  //........
	0x00,  //........
	0x00,  //........
	0x00,  //........
	0x00,  //........
	0x1e,  //...%%%%.
	0x33,  //..%%..%%
	0x63,  //.%%...%%
	0x7e,  //.%%%%%%.
	0x40,  //.%......
	0x60,  //.%%.....
	0x3e,  //..%%%%%.
	0x00,  //........
	0x00,  //........
	0x00,  //........


	/*ASCII: 0066 (f) , Width: 10 */
	0x00, 0x00,  //..........
	0x00, 0x00,  //..........
	0x03, 0x80,  //......%%%.
	0x04, 0x00,  //.....%....
	0x08, 0x00,  //....%.....
	0x08, 0x00,  //....%.....
	0x7e, 0x00,  //.%%%%%%...
	0x18, 0x00,  //...%%.....
	0x18, 0x00,  //...%%.....
	0x10, 0x00,  //...%......
	0x10, 0x00,  //...%......
	0x10, 0x00,  //...%......
	0x30, 0x00,  //..%%......
	0x30, 0x00,  //..%%......
	0x60, 0x00,  //.%%.......
	0xc0, 0x00,  //%%........


	/*ASCII: 0067 (g) , Width: 9 */
	0x00, 0x00,  //.........
	0x00, 0x00,  //.........
	0x00, 0x00,  //.........
	0x00, 0x00,  //.........
	0x00, 0x00,  //.........
	0x00, 0x00,  //.........
	0x1f, 0x00,  //...%%%%%.
	0x31, 0x00,  //..%%...%.
	0x63, 0x00,  //.%%...%%.
	0x42, 0x00,  //.%....%..
	0x46, 0x00,  //.%...%%..
	0x4e, 0x00,  //.%..%%%..
	0x7e, 0x00,  //.%%%%%%..
	0x06, 0x00,  //.....%%..
	0x4c, 0x00,  //.%..%%...
	0x78, 0x00,  //.%%%%....


	/*ASCII: 0068 (h) , Width: 8 */
	0x00,  //........
	0x00,  //........
	0x10,  //...%....
	0x30,  //..%%....
	0x30,  //..%%....
	0x20,  //..%.....
	0x2e,  //..%.%%%.
	0x33,  //..%%..%%
	0x63,  //.%%...%%
	0x63,  //.%%...%%
	0x42,  //.%....%.
	0x42,  //.%....%.
	0x42,  //.%....%.
	0x00,  //........
	0x00,  //........
	0x00,  //........


	/*ASCII: 0069 (i) , Width: 7 */
	0x00,  //.......
	0x00,  //.......
	0x08,  //....%..
	0x18,  //...%%..
	0x00,  //.......
	0x00,  //.......
	0x70,  //.%%%...
	0x90,  //%..%...
	0x10,  //...%...
	0x10,  //...%...
	0x10,  //...%...
	0x10,  //...%...
	0x1c,  //...%%%.
	0x00,  //.......
	0x00,  //.......
	0x00,  //.......


	/*ASCII: 006a (j) , Width: 8 */
	0x00,  //........
	0x00,  //........
	0x03,  //......%%
	0x02,  //......%.
	0x00,  //........
	0x00,  //........
	0x1c,  //...%%%..
	0x26,  //..%..%%.
	0x06,  //.....%%.
	0x06,  //.....%%.
	0x04,  //.....%..
	0x04,  //.....%..
	0x04,  //.....%..
	0x0c,  //....%%..
	0x98,  //%..%%...
	0xf0,  //%%%%....


	/*ASCII: 006b (k) , Width: 8 */
	0x00,  //........
	0x00,  //........
	0x10,  //...%....
	0x30,  //..%%....
	0x30,  //..%%....
	0x20,  //..%.....
	0x2e,  //..%.%%%.
	0x33,  //..%%..%%
	0x63,  //.%%...%%
	0x7c,  //.%%%%%..
	0x4c,  //.%..%%..
	0x44,  //.%...%..
	0x46,  //.%...%%.
	0x00,  //........
	0x00,  //........
	0x00,  //........


	/*ASCII: 006c (l) , Width: 7 */
	0x00,  //.......
	0x00,  //.......
	0x10,  //...%...
	0x30,  //..%%...
	0x30,  //..%%...
	0x20,  //..%....
	0x20,  //..%....
	0x20,  //..%....
	0x60,  //.%%....
	0x60,  //.%%....
	0x40,  //.%.....
	0x64,  //.%%..%.
	0x38,  //..%%%..
	0x00,  //.......
	0x00,  //.......
	0x00,  //.......


	/*ASCII: 006d (m) , Width: 9 */
	0x00, 0x00,  //.........
	0x00, 0x00,  //.........
	0x00, 0x00,  //.........
	0x00, 0x00,  //.........
	0x00, 0x00,  //.........
	0x00, 0x00,  //.........
	0x5b, 0x00,  //.%.%%.%%.
	0x6d, 0x00,  //.%%.%%.%.
	0x6d, 0x00,  //.%%.%%.%.
	0x49, 0x00,  //.%..%..%.
	0xc9, 0x00,  //%%..%..%.
	0x9b, 0x00,  //%..%%.%%.
	0x92, 0x00,  //%..%..%..
	0x00, 0x00,  //.........
	0x00, 0x00,  //.........
	0x00, 0x00,  //.........


	/*ASCII: 006e (n) , Width: 8 */
	0x00,  //........
	0x00,  //........
	0x00,  //........
	0x00,  //........
	0x00,  //........
	0x00,  //........
	0x2e,  //..%.%%%.
	0x33,  //..%%..%%
	0x63,  //.%%...%%
	0x63,  //.%%...%%
	0x42,  //.%....%.
	0x42,  //.%....%.
	0x42,  //.%....%.
	0x00,  //........
	0x00,  //........
	0x00,  //........


	/*ASCII: 006f (o) , Width: 9 */
	0x00, 0x00,  //.........
	0x00, 0x00,  //.........
	0x00, 0x00,  //.........
	0x00, 0x00,  //.........
	0x00, 0x00,  //.........
	0x00, 0x00,  //.........
	0x1e, 0x00,  //...%%%%..
	0x23, 0x00,  //..%...%%.
	0x61, 0x00,  //.%%....%.
	0x41, 0x00,  //.%.....%.
	0x43, 0x00,  //.%....%%.
	0x46, 0x00,  //.%...%%..
	0x3c, 0x00,  //..%%%%...
	0x00, 0x00,  //.........
	0x00, 0x00,  //.........
	0x00, 0x00,  //.........


	/*ASCII: 0070 (p) , Width: 9 */
	0x00, 0x00,  //.........
	0x00, 0x00,  //.........
	0x00, 0x00,  //.........
	0x00, 0x00,  //.........
	0x00, 0x00,  //.........
	0x00, 0x00,  //.........
	0x2e, 0x00,  //..%.%%%..
	0x33, 0x00,  //..%%..%%.
	0x61, 0x00,  //.%%....%.
	0x61, 0x00,  //.%%....%.
	0x43, 0x00,  //.%....%%.
	0x46, 0x00,  //.%...%%..
	0x7c, 0x00,  //.%%%%%...
	0xc0, 0x00,  //%%.......
	0xc0, 0x00,  //%%.......
	0x80, 0x00,  //%........


	/*ASCII: 0071 (q) , Width: 9 */
	0x00, 0x00,  //.........
	0x00, 0x00,  //.........
	0x00, 0x00,  //.........
	0x00, 0x00,  //.........
	0x00, 0x00,  //.........
	0x00, 0x00,  //.........
	0x1c, 0x00,  //...%%%...
	0x33, 0x00,  //..%%..%%.
	0x63, 0x00,  //.%%...%%.
	0x43, 0x00,  //.%....%%.
	0x46, 0x00,  //.%...%%..
	0x4e, 0x00,  //.%..%%%..
	0x7e, 0x00,  //.%%%%%%..
	0x06, 0x00,  //.....%%..
	0x04, 0x00,  //.....%...
	0x04, 0x00,  //.....%...


	/*ASCII: 0072 (r) , Width: 9 */
	0x00, 0x00,  //.........
	0x00, 0x00,  //.........
	0x00, 0x00,  //.........
	0x00, 0x00,  //.........
	0x00, 0x00,  //.........
	0x00, 0x00,  //.........
	0x27, 0x00,  //..%..%%%.
	0x39, 0x00,  //..%%%..%.
	0x31, 0x00,  //..%%...%.
	0x20, 0x00,  //..%......
	0x60, 0x00,  //.%%......
	0x60, 0x00,  //.%%......
	0x40, 0x00,  //.%.......
	0x00, 0x00,  //.........
	0x00, 0x00,  //.........
	0x00, 0x00,  //.........


	/*ASCII: 0073 (s) , Width: 8 */
	0x00,  //........
	0x00,  //........
	0x00,  //........
	0x00,  //........
	0x00,  //........
	0x00,  //........
	0x1f,  //...%%%%%
	0x30,  //..%%....
	0x30,  //..%%....
	0x1c,  //...%%%..
	0x06,  //.....%%.
	0x06,  //.....%%.
	0x7c,  //.%%%%%..
	0x00,  //........
	0x00,  //........
	0x00,  //........


	/*ASCII: 0074 (t) , Width: 8 */
	0x00,  //........
	0x00,  //........
	0x00,  //........
	0x10,  //...%....
	0x10,  //...%....
	0x10,  //...%....
	0xfe,  //%%%%%%%.
	0x20,  //..%.....
	0x20,  //..%.....
	0x20,  //..%.....
	0x20,  //..%.....
	0x20,  //..%.....
	0x3c,  //...%%%..
	0x00,  //........
	0x00,  //........
	0x00,  //........


	/*ASCII: 0075 (u) , Width: 9 */
	0x00, 0x00,  //.........
	0x00, 0x00,  //.........
	0x00, 0x00,  //.........
	0x00, 0x00,  //.........
	0x00, 0x00,  //.........
	0x00, 0x00,  //.........
	0x21, 0x00,  //..%....%.
	0x21, 0x00,  //..%....%.
	0x63, 0x00,  //.%%...%%.
	0x63, 0x00,  //.%%...%%.
	0x46, 0x00,  //.%...%%..
	0x46, 0x00,  //.%...%%..
	0x7a, 0x00,  //.%%%%.%..
	0x00, 0x00,  //.........
	0x00, 0x00,  //.........
	0x00, 0x00,  //.........


	/*ASCII: 0076 (v) , Width: 8 */
	0x00,  //........
	0x00,  //........
	0x00,  //........
	0x00,  //........
	0x00,  //........
	0x00,  //........
	0xc2,  //%%....%.
	0x42,  //.%....%.
	0x46,  //.%...%%.
	0x44,  //.%...%..
	0x48,  //.%..%...
	0x68,  //.%%.%...
	0x30,  //..%%....
	0x00,  //........
	0x00,  //........
	0x00,  //........


	/*ASCII: 0077 (w) , Width: 9 */
	0x00, 0x00,  //.........
	0x00, 0x00,  //.........
	0x00, 0x00,  //.........
	0x00, 0x00,  //.........
	0x00, 0x00,  //.........
	0x00, 0x00,  //.........
	0x40, 0x80,  //.%......%
	0x41, 0x80,  //.%.....%%
	0x49, 0x80,  //.%..%..%%
	0x55, 0x00,  //.%.%.%.%.
	0x47, 0x00,  //.%...%%%.
	0x66, 0x00,  //.%%..%%..
	0x46, 0x00,  //.%...%%..
	0x00, 0x00,  //.........
	0x00, 0x00,  //.........
	0x00, 0x00,  //.........


	/*ASCII: 0078 (x) , Width: 9 */
	0x00, 0x00,  //.........
	0x00, 0x00,  //.........
	0x00, 0x00,  //.........
	0x00, 0x00,  //.........
	0x00, 0x00,  //.........
	0x00, 0x00,  //.........
	0x21, 0x00,  //..%....%.
	0x32, 0x00,  //..%%..%..
	0x14, 0x00,  //...%.%...
	0x18, 0x00,  //...%%....
	0x34, 0x00,  //..%%.%...
	0x66, 0x00,  //.%%..%%..
	0xc2, 0x00,  //%%....%..
	0x00, 0x00,  //.........
	0x00, 0x00,  //.........
	0x00, 0x00,  //.........


	/*ASCII: 0079 (y) , Width: 9 */
	0x00, 0x00,  //.........
	0x00, 0x00,  //.........
	0x00, 0x00,  //.........
	0x00, 0x00,  //.........
	0x00, 0x00,  //.........
	0x00, 0x00,  //.........
	0x61, 0x00,  //.%%....%.
	0x23, 0x00,  //..%...%%.
	0x22, 0x00,  //..%...%..
	0x22, 0x00,  //..%...%..
	0x34, 0x00,  //..%%.%...
	0x18, 0x00,  //...%%....
	0x18, 0x00,  //...%%....
	0x30, 0x00,  //..%%.....
	0x60, 0x00,  //.%%......
	0xc0, 0x00,  //%%.......


	/*ASCII: 007a (z) , Width: 9 */
	0x00, 0x00,  //.........
	0x00, 0x00,  //.........
	0x00, 0x00,  //.........
	0x00, 0x00,  //.........
	0x00, 0x00,  //.........
	0x00, 0x00,  //.........
	0x3f, 0x00,  //..%%%%%%.
	0x02, 0x00,  //......%..
	0x04, 0x00,  //.....%...
	0x08, 0x00,  //....%....
	0x10, 0x00,  //...%.....
	0x20, 0x00,  //..%......
	0x7e, 0x00,  //.%%%%%%..
	0x00, 0x00,  //.........
	0x00, 0x00,  //.........
	0x00, 0x00,  //.........


};


#endif /* UB_LIB_FONTS_CONSOLASFONTCURSIVE_H_ */
