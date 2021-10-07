#include "main.h"
#include <limits.h>
#include <stdio.h>
/**
 * main - Entry point
 *
 * Return: Always 0
 */
int main(void)
{
	int len = 6, ct = 890;

	_printf("iddi%diddiiddi\n", 1024);
	_printf("%d\n", 214748364);
	_printf("%d\n", INT_MIN);
	_printf("%d\n", len);
	_printf("%s\n", "jobless");
	_printf("%d\n", ct);
	_printf("%d\n-i%i\n", ct, len);
	len = _printf("Let's try to printf a simple sentence.\n");
	_printf("%d\n", len);
	len = _printf("Character:[%c]\n", 'H');
	_printf("Length:[%d, %i]\n", len, len);
	len = _printf("Negative:[%d]\n", -762534);
	_printf("Length:[%d, %i]\n", len, len);
	_printf("String:[%s]\n", "I am a string !");
	_printf("Length:[%d, %i]\n", len, len);
	len = _printf("Percent:[100%%]\n");
	_printf("Length:[%d, %i]\n", len, len);
	return (0);
}
