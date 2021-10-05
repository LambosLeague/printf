#include "main.h"

int _printf(char const *format, ...)
{
	va_list arr;
	int cnt = 0, i = 0;
	char *wrd;

	convert conv_f[] = {
		{'c', _char},
		{'s', _strings},
		{'d', _int_s},
		{'i', _int_s}
	};

	va_start(arr, format);
	while (format != 0 && *format != 0)
	{
		if (*format != '%' && *format != 0)
		{
			cnt += _putch(*format);
			format++;
		}
		else
		{
			while (i < 4)
			{
				if (*(format + 1) == conv_f[i].x)
				{
					wrd = conv_f[i].func(arr, conv_f[i].x);
					format++;
					cnt += _putwrd(wrd);
				}
				else
					i++;
			}
			i = 0;
			format++;
		}
	}
	free(wrd);
	return (cnt);
}
