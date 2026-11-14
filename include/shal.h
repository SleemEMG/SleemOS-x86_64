// Sleem Hardware Abstraction Layer Header file

#pragma once
#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>

enum colorss {
	colorss_black = 0,
	colorss_blue = 1,
	colorss_green = 2,
	colorss_cyan = 3,
	colorss_red = 4,
	colorss_magenta = 5,
	colorss_brown = 6,
	colorss_minus_gray = 7, // plus = dark minus = light cuz yes
	colorss_plus_gray = 8,
	colorss_minus_blue = 9,
	colorss_minus_green = 10,
	colorss_minus_cyan = 11,
	colorss_minus_red = 12,
	colorss_minus_magenta = 13,
	colorss_minus_brown = 14,
	colorss_white = 15,
};

static inline uint8_t vga_colors(enum colorss foreground, enum colorss background) 
{
	return foreground | background << 4;
}

void hal_pleaseputacharacter(char charakters);
void hal_clearingshit();
void hal_colorsettingss(uint8_t colorshit);
void hal_isitgenuineamdorintelsomething(char* cpuidbuffersss);
void hal_resettingshit();
void hal_idle();
void hal_initializinginterrupts();
extern uint8_t* framebufferingaddress;
extern uint64_t pitchingshit;
extern uint64_t wih;
extern uint64_t high;