#include "main.h"

char *_strings(va_list arr, int x)
{
	char *wrdd, *wrd;
	int len = 0;

	if (x == 115)
		wrdd = va_arg(arr, char *);

	while (wrdd[len] != 0)
		len++;
	wrd = malloc(len + 1);
	len = 0;

	while (wrdd[len] != 0)
	{
		wrd[len] = wrdd[len];
		len++;
	}
	wrd[len] = 0;

	return (wrd);
}

char *_char(va_list arr, int x)
{
	char *m = malloc(2);
	int c;

	if (x == 99 && m != 0)
	{
		c = va_arg(arr, int);
		*m = c;
		*(m + 1) = 0;
	}
	else if (x == 37 && m != 0)
	{
		*m = 37;
		m[1] = 0;
	}

	return (m);
}

char *_int_s(va_list arr, int f)
{
	int i = va_arg(arr, int), x, ln = i_len(i), cnt = 0;
	long int sqr = i_sqr(10, ln);
	char *m;

	if (i >= 0)
		m = malloc(ln + 1);
	else
		m = malloc(ln + 2);

	if (m != 0 && (f == 100 || f == 105))
	{
		if ((i < 10) && (i >= 0))
			*m[cnt++] = (i + 48);
		else
		{
			if ((i < 0) && (i > -10))
			{
				m[cnt++] = 45;
				m[cnt++] = ((i * (-1)) + 48);
			}
			else if (i <= -10)
			{
				m[cnt++] = 45;
				while(ln != 0)
				{
					x = (i % sqr) / (sqr / 10);
					m[cnt++] = ((x * (-1)) + 48);
					sqr = sqr / 10;
					ln--;
				}
			}
			else
			{
				while(ln != 0)
				{
					x = (i % sqr) / (sqr / 10);
					m[cnt++] = (x + 48);
					sqr = sqr / 10;
					ln--;
				}
			}
		}
		m[cnt] = 0;
	}
	return (m);
}
int i_len(int i)
{
	int cnt = 0;
	
	if (i < 0)
		i *= (-1);

	while(i != 0)
	{
		i /= 10;
		cnt++;
	}
	return (cnt);
}
long int i_sqr(int x, int y)
{
	if(x == 0)
		return (0);
	if(y < 0)
		return (-1);
	if(y == 0 || x == 1)
		return (1);
	if(y == 1)
		return (x);

	return (x * i_sqr(x, ( y = y - 1)));
}

int _putch(int x)
{
	char i = x;
	return (write(1, &i, 1));
}

int _putwrd(char *s)
{
	int cnt = 0;

	if (!s)
		return 0;
	while (s[cnt] != 0)
	{
		_putch(s[cnt]);
		cnt++;
	}
	return (cnt);
}
