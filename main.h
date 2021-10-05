#ifndef MAIN_H
#define MAIN_H
#include <stdarg.h>
#include <stdlib.h>
#include <unistd.h>

typedef struct conv {
	char x;
	char * (*func)(va_list, int);
}convert;

int _printf(const char *format, ...);
char *_strings(va_list, int);
char *_char(va_list, int);
char *_int_s(va_list, int);
int _int_sqr(int, int);
int _int_len(int);
int _putch(int);
int _putwrd(char *);

#endif /* MAIN_H*/
