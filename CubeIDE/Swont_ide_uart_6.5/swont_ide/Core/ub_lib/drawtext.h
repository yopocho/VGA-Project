/*
 * drawtext.h
 *
 *  Created on: 31 mei 2023
 *      Author: Sjoerd
 */

#ifndef UB_LIB_DRAWTEXT_H_
#define UB_LIB_DRAWTEXT_H_

#define STANDARD_FONT_SIZE 16
#define SPACESIZE 4
#define PIXELBETWEENGLYPHS 2


#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "errorHandling.h"

extern Error DrawText(uint16_t x1, uint16_t y1, uint8_t color, char *textString,
                      char *fontName, uint8_t fontSize, char *fontStyle);

#endif /* UB_LIB_DRAWTEXT_H_ */
