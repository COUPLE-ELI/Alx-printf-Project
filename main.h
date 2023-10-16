#ifndef MAIN_H
#define MAIN_H
#include <stdio.h>
#include <stdarg.h>
#include <stdlib.h>

typedef struct funct_character
{
	char specifier;
	int funct;
}f-ch;

int _printf(const char *format, ...);

#endif
