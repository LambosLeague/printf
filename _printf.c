#include "main.h"

int _printf(char const *format, ...)
{
	va_list arr;
	int cnt = 0, i = 0, len = 0, rnt = 0;
	char *wrd;
	size_t size = 0;

	convert conv_f[] = {
		{'i', _int_s},
		{'c', _char},
		{'%', _char},
		{'s', _strings},
		{'d', _int_s}
	};
	size = sizeof(conv_f) /sizeof(conv_f[0]);
	len = (int)size;
	if (!format)
		return (0);
	va_start(arr, format);
	while (format != 0 && *format != 0)
	{
again:
		if (*format != '%' && *format != 0)
		{
			cnt += _putch(*format);
			format++;
		}
		else if (*format == '%' && (*(format + 1) == 0))
			 format++;
		else if (*format == '%' && *format != 0)
		{
			while (i < len)
			{
				if ((*(format + 1) == conv_f[i].x) && *format == '%')
				{
					wrd = conv_f[i].func(arr, conv_f[i].x);
					format += 2;
					cnt += _putwrd(wrd);
					free(wrd);
					wrd = 0;
					i = 0;
					if (conv_f[i].x == '%')
						rnt = -1;
				}
				else
					i++;
			}
			if (i == len && (rnt != -1) && *format == '%')
			{
				cnt += _putch(*format);
				format++;
			}
			i = 0;
		}
		else
			goto again;
	}
	return (cnt);
}
