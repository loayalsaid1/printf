#include "main.h"

/**
 * _putchar - writes the character c to stdout
 * @c: The character to print
 *
 * Return: On success 1.
 * On error, -1 is returned, and errno is set appropriately.
 */
int _putchar(char c)
{
	return (write(1, &c, 1));
}

/**
 * _puts - prints a string, followed by a new line
 * to stdout
 * @str: string to be processed
 */
void _puts(char *str)
{
	int i;
	for (i = 0; str[i] != '\0'; i++)
		_putchar(str[i]);
}

/**
 * _strlen - returns the length of a string
 * @str: string to be processed
 *
 * ********** IMPORTANT NOTE: I THOUGH IT MAY
 * BE MORE BETTER IF I USE A COUNTER VARIABLE
 * BUT IT TURNED OUT THAT NO!
 *
 *
 * one more edit: i will change the i to make it
 * named counter, to have a middle ground
 * and make it more readable
 *
 * Return: lenth of string
 */
int _strlen(char *str)
{
	int counter;

	for (counter = 0; str[counter] != '\0'; counter++)
		;
	return (counter);
}

/**
 * _printf -  simulate printf
 * @format: the string
 * @...: the variadic variabels
 * Return: the resl
*/
int _printf(const char *format, ...)
{
	int i, len;
	char *str;
	va_list ap;

	va_start(ap, format);

	if(format == NULL)
		return (-1);

	len = 0;
	i = 0;
	while(format[i])
	{
		if (format[i] == '%' && format[i + 1] != '\0')
		{
			switch (format[i + 1])
			{
				case 's':
				{
					str = va_arg(ap, char *);
					if (str == NULL)
						str = "(null)";
					len += _strlen(str);
					_puts(str);
					i++;
					break;
				}
				case 'c':
				{
					_putchar(va_arg(ap, int));
					len++;
					i++;
					break;
				}
				case '%':
				{
					_putchar('%');
					len++;
					i++;
					break;
				}
				default:
				{
					_putchar('%');
					_putchar(format[i + 1]);
					len += 2;
					i++;
					break;
				}
			}
		}
		else if (format[i] == '%' && format[i + 1] == '\0')
		{
			i++;
			break;
		}
		else
		{
			_putchar(format[i]);
			len++;
		}
		i++;
	}
	va_end(ap);

	return (len);
}

	/*
	int main(void)
	{
		char *string = "loay";

		int len = printf("%!\n");
		printf("%d\n", len);

		int len2 = _printf("%!\n");
		printf("%d\n", len2);


	/*
		// _printf("red."); DONE
		// _printf("\n"); DONE
		// _printf("\nred"); DONE 
		// _printf("\nred\n"); DONE
		// _printf("\nred\nred");  DONE
		// _printf("\nred\nred\n"); DONE
		// _printf("my name is: %s", string); DONE 
		// _printf("my name is: %s\n", string); DONE
		// _printf("%s is my name \n", string); DONE
		// _printf("%s is my name ", string); DONE
		// _printf(".%s is my name \n", string); DONE
		// _printf("%s", string); DONE
		// _printf("\n"); DONE
		// _printf("%s\n", string); DONE
		// _printf("%s %s", string, string); DONE
		// _printf("%s\n%s", string, string); DONE
		// _printf("%s.\n.%s", string, srting); DONE 
		// _printf("%s", "adsfas");
	*/
	/*	return 0;
}
*/