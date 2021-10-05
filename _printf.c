#include "main.h"

int _printf(char const *format, ...)
{
	va_list arr;
	int cnt = 0, i = 0, len = 0;
	char *wrd;
	size_t size = 0;

	convert conv_f[] = {
		{'c', _char},
		{'%', _char},
		{'s', _strings},
		{'d', _int_s},
		{'i', _int_s}
	};
	size = sizeof(conv_f) /sizeof(conv_f[0]);
	len = (int)size;

	va_start(arr, format);
	while (format != 0 && *format != 0)
	{
		if (*format != '%' && *format != 0)
		{
			cnt += _putch(*format);
			format++;
		}
		else if (*format == '%' && *format != 0)
		{
			while (i < len)
			{
				if (*(format + 1) == conv_f[i].x)
				{
					wrd = conv_f[i].func(arr, conv_f[i].x);
					format++;
					cnt += _putwrd(wrd);
					free(wrd);
					wrd = 0;
				}
				else
					i++;
			}
			i = 0;
			format++;
		}
	}

	return (cnt);
}
