#include "main.h"

/**
 * main - Entry point
 *
 * Return: Always 0
 */
int main(void)
{
	int len;

	len = _printf("Let's try to printf a simple sentence.\n");
	_printf("%d\n", len);
	len = _printf("Character:[%c]\n", 'H');
	_printf("Length:[%d, %i]\n", len, len);
	len = _printf("Negative:[%d]\n", -762534);
	_printf("Length:[%d, %i]\n", len, len);
	_printf("String:[%s]\n", "I am a string !");
	_printf("Length:[%d, %i]\n", len, len);

	return (0);
}
