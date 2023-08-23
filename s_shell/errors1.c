#include "shell.h"

/**
 * _erratoi - s ==> int
 * @s: string to convert
 * Return: 0 if no num in str, converted num, -1 on error
 *
 */
int _erratoi(char *s)
{
	unsigned long int rslt = 0;
	int i = 0;

	if (*s == '+')
		s++;  
	for (i = 0;  s[i] != '\0'; i++)
	{
		if (s[i] >= '0' && s[i] <= '9')
		{
			rslt *= 10;
			rslt += (s[i] - '0');
			if (rslt > INT_MAX)
				return (-1);
		}
		else
			return (-1);
	}
	return (rslt);
}

/**
 * cnvrt_num - converter function, a clone of itoa
 * @num: number
 * @base: base
 * @flags: argument flags
 *
 * Return: string pointer
 */
char *cnvrt_num(long int num, int base, int flags)
{
	static char *arr;
	static char buf[50];
	char sign = 0;
	char *ptr;
	unsigned long n = num;

	if (!(flags & CNVRT_UNSIGNED) && num < 0)
	{
		n = -num;
		sign = '-';

	}
	arr = flags & CNVRT_LOWERCASE ? "0123456789abcdef" : "0123456789ABCDEF";
	ptr = &buf[49];
	*ptr = '\0';

	do	{
		*--ptr = arr[n % base];
		n /= base;
	} while (n != 0);

	if (sign)
		*--ptr = sign;
	return (ptr);
}


/**
 * print_dec - function prints a decimal (integer) number (base 10)
 * @input: the input
 * @fd: the filedescriptor to write to
 *
 * Return: num of chars printed
 */
int print_dec(int input, int fd)
{
	int (*__putchar)(char) = _putchar;
	int i, count = 0;
	unsigned int _abs_, curr;

	if (fd == STDERR_FILENO)
		__putchar = _errputchar;
	if (input < 0)
	{
		_abs_ = -input;
		__putchar('-');
		count++;
	}
	else
		_abs_ = input;
	curr = _abs_;
	for (i = 1000000000; i > 1; i /= 10)
	{
		if (_abs_ / i)
		{
			__putchar('0' + curr / i);
			count++;
		}
		curr %= i;
	}
	__putchar('0' + curr);
	count++;

	return (count);
}

/**
 * print_err - prints error msg
 * @info: info struct
 * @estr: str (error type)
 * 
 */
void print_err(inf *info, char *estr)
{
	_errputs(info->file_name);
	_errputs(": ");
	print_dec(info->line_count, STDERR_FILENO);
	_errputs(": ");
	_errputs(info->argv[0]);
	_errputs(": ");
	_errputs(estr);
}

/**
 * rmv_cmt - first '#' ==> '\0'
 * @buff: addrss of str to modify
 * Return: Always 0;
 */
void rmv_cmt(char *buff)
{
	int i;

	for (i = 0; buff[i] != '\0'; i++)
		if (buff[i] == '#' && (!i || buff[i - 1] == ' '))
		{
			buff[i] = '\0';
			break;
		}
}
