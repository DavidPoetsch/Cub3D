/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lstefane <lstefane@student.42vienna.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/21 12:05:49 by dpotsch           #+#    #+#             */
/*   Updated: 2025/01/27 15:06:29 by dpotsch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/**
 * @brief Prints and formats a string based on the given specifiers.
 *        Format definition '%[flags][width][.precision][length]'.
 *        [flags]: (-0.# +):
 *          '-' output is left justified.
 *          '0' output is zero padded.
 *          '.' adds precision to argument.
 *          '#' output with alternate form (%#x adds 0x).
 *          ' ' adds a leading space to numbers.
 *          '+' adds explicit sign to numbers.
 *        [width]:
 *          defines the width of the output.
 *        [.precision]:
 *          defines the precision of the argument.
 *        [length]: (datatype) (cspdiuxX%):
 *          %c Prints a single character.
 *          %s Prints a string.
 *          %p Prints the address of a void pointer as hex.
 *          %d Prints a decimal (base 10) number.
 *          %i Prints an integer in base 10.
 *          %u Prints an unsigned decimal (base 10) number.
 *          %x Prints a number in hexadecimal (base 16) lowercase format.
 *          %X Prints a number in hexadecimal (base 16) uppercase format.
 *          %% Prints a percent sign.
 * @param fd	The file where to write
 * @param format	The string with possible format specifiers.
 * @param ... 	arguments for each format specifier.
 * @return int	length of the output.
 */
int	ft_printf_main(const int fd, const char *format, va_list *parg)
{
	size_t				i;
	int					result;
	t_format_specifier	fs;
	int					index_percent;

	i = 0;
	result = 0;
	init_format_specifier(&fs, fd);
	while (format && format[i] != '\0')
	{
		reset_format_specifier(&fs);
		if (format[i] == '%')
		{
			index_percent = i;
			check_format_specifiers(format, &i, &fs);
			result += apply_format(parg, &fs);
		}
		result += write_default(format, &i, &fs, index_percent);
	}
	if (!format || fs.invalid_eol)
		result = -1;
	va_end(*parg);
	return (result);
}

int	ft_printf(const char *format, ...)
{
	va_list	args;
	int		result;

	va_start(args, format);
	result = ft_printf_main(STDOUT_FILENO, format, &args);
	va_end(args);
	flush_print_buffer(STDOUT_FILENO);
	return (result);
}

int	ft_eprintf(const char *format, ...)
{
	va_list	args;
	int		result;

	va_start(args, format);
	result = ft_printf_main(STDERR_FILENO, format, &args);
	va_end(args);
	flush_print_buffer(STDERR_FILENO);
	return (result);
}

int	ft_fprintf(const int fd, const char *format, ...)
{
	va_list	args;
	int		result;

	va_start(args, format);
	result = ft_printf_main(fd, format, &args);
	va_end(args);
	flush_print_buffer(fd);
	return (result);
}
/*
//! Test function
#include <stdio.h>

void	result(int res1, int res2)
{
	if (res1 == res2)
	{
		printf("\033[0;32mMY = %d\n", res1);
		printf("\033[0;32mOG = %d\n", res2);
	}
	else
	{
		printf("\033[0;31mMY = %d\n", res1);
		printf("\033[0;31mOG = %d\n", res2);
	}
	printf("\033[0m\n");
}

void	basic(void)
{
	int				res1;
	int				res2;
	char			c;
	char			*s;
	char			*p;
	int				d;
	int				i;
	unsigned int	u;
	unsigned int	x;
	unsigned int	X;
	char			*test;
	int				a;

	c = 'F';
	s = "ourty";
	d = 2;
	i = INT_MIN;
	p = s;
	u = UINT_MAX;
	x = UINT_MAX;
	X = UINT_MAX;
	res1 = ft_printf("%c%s %d || %i || %p || %u || %x || %X\n", c, s, d, i, p,
			u, x, X);
	res2 = printf("%c%s %d || %i || %p || %u || %x || %X\n", c, s, d, i, p, u,
			x, X);
	result(res1, res2);
}

//! BONUS
void	bonus1(void)
{
	char	*test;
	int		*a;

	int res1, res2;
	a = NULL;
	// %c tests
	puts("%c-------------------------");
	res1 = ft_printf("'%-10c'\n", 'A');
	res2 = printf("'%-10c'\n", 'A');
	result(res1, res2);
	res1 = ft_printf("'%010c'\n", 'A');
	res2 = printf("'%010c'\n", 'A');
	result(res1, res2);
	// %s tests
	puts("\n%s-------------------------");
	res1 = ft_printf("'%-10s'\n", "Hello");
	res2 = printf("'%-10s'\n", "Hello");
	result(res1, res2);
	res1 = ft_printf("'%10s'\n", "Hello");
	res2 = printf("'%10s'\n", "Hello");
	result(res1, res2);
	res1 = ft_printf("'%10.3s'\n", "Hello");
	res2 = printf("'%10.3s'\n", "Hello");
	result(res1, res2);
	test = NULL;
	res1 = ft_printf("'%s'\n", test);
	res2 = printf("'%s'\n", test);
	result(res1, res2);
	// %p tests
	puts("\n%p-------------------------");
	a = test;
	res1 = ft_printf("'%-20p'\n", &a);
	res2 = printf("'%-20p'\n", &a);
	result(res1, res2);
	res1 = ft_printf("'%+25.20p'\n", &a);
	res2 = printf("'%+25.20p'\n", &a);
	result(res1, res2);
	res1 = ft_printf("'% 25.20p'\n", &a);
	res2 = printf("'% 25.20p'\n", &a);
	result(res1, res2);
	res1 = ft_printf("'%p'\n", (void *)0);
	res2 = printf("'%p'\n", (void *)0);
	result(res1, res2);
	res1 = ft_printf("'%-p'\n", (void *)17240180584784891087lu);
	res2 = printf("'%-p'\n", (void *)17240180584784891087lu);
	result(res1, res2);
	res1 = ft_printf("'%030.8p'\n", 2705171059u);
	res2 = printf("'%030.8p'\n", 2705171059u);
	result(res1, res2);
	res1 = ft_printf("'%30p'\n", (void *)1312307382483808423lu);
	res2 = printf("'%30p'\n", (void *)1312307382483808423lu);
	result(res1, res2);
	res1 = ft_printf("p: '%+30p'\n", (void *)-123);
	res2 = printf("p: '%+30p'\n", (void *)-123);
	result(res1, res2);
	res1 = ft_printf("p: '%5.15p'\n", (void *)13134134);
	res2 = printf("p: '%5.15p'\n", (void *)13134134);
	result(res1, res2);
	res1 = ft_printf("p: '% 5.15p'\n", (void *)13134134);
	res2 = printf("p: '% 5.15p'\n", (void *)13134134);
	result(res1, res2);
	res1 = ft_printf("p: '% 15.p'\n", (void *)13134134);
	res2 = printf("p: '% 15.p'\n", (void *)13134134);
	result(res1, res2);
	// %d, %i tests
	puts("\n%d-------------------------");
	res1 = ft_printf("'%08.3d'\n", 8123);
	res2 = printf("'%08.3d'\n", 8123);
	result(res1, res2);
	res1 = ft_printf("'%+10d'\n", 123);
	res2 = printf("'%+10d'\n", 123);
	result(res1, res2);
	res1 = ft_printf("'%+10d'\n", -123);
	res2 = printf("'%+10d'\n", -123);
	result(res1, res2);
	res1 = ft_printf("'% 10d'\n", 123);
	res2 = printf("'% 10d'\n", 123);
	result(res1, res2);
	res1 = ft_printf("'%+010d'\n", -123);
	res2 = printf("'%+010d'\n", -123);
	result(res1, res2);
	res1 = ft_printf("'%010.6d'\n", 123);
	res2 = printf("'%010.6d'\n", 123);
	result(res1, res2);
	res1 = ft_printf("'%d'\n", INT_MAX + 1);
	res2 = printf("'%d'\n", INT_MAX + 1);
	result(res1, res2);
	res1 = ft_printf("'%+-15.10d'\n", 123);
	res2 = printf("'%+-15.10d'\n", 123);
	result(res1, res2);
	res1 = ft_printf("'% +15.10d'\n", 123);
	res2 = printf("'% +15.10d'\n", 123);
	result(res1, res2);
	res1 = ft_printf("'%10.d'\n", 0);
	res2 = printf("'%10.d'\n", 0);
	result(res1, res2);
	res1 = ft_printf("'%010.d'\n", 0);
	res2 = printf("'%010.d'\n", 0);
	result(res1, res2);
	res1 = ft_printf("'%+10.d'\n", 0);
	res2 = printf("'%+10.d'\n", 0);
	result(res1, res2);
	res1 = ft_printf("'% -10.5d'\n", 345);
	res2 = printf("'% -10.5d'\n", 345);
	result(res1, res2);
	res1 = ft_printf("'% -5.15d'\n", 345);
	res2 = printf("'% -5.15d'\n", 345);
	result(res1, res2);
	// %u tests
	puts("\n%u-------------------------");
	res1 = ft_printf("'%10u'\n", 123);
	res2 = printf("'%10u'\n", 123);
	result(res1, res2);
	res1 = ft_printf("'%+010.3u'\n", 123);
	res2 = printf("'%+010.3u'\n", 123);
	result(res1, res2);
	res1 = ft_printf("'%+010u'\n", 0);
	res2 = printf("'%+010u'\n", 0);
	result(res1, res2);
	res1 = ft_printf("'%#010u'\n", 123);
	res2 = printf("'%#010u'\n", 123);
	result(res1, res2);
	res1 = ft_printf("'%# 25.10u'\n", 123);
	res2 = printf("'%# 25.10u'\n", 123);
	result(res1, res2);
	res1 = ft_printf("'%# +5.6u'\n", 123);
	res2 = printf("'%# +5.6u'\n", 123);
	result(res1, res2);
	// %X tests
	puts("\n%X-------------------------");
	res1 = ft_printf("1: '%#10X'\n", 123);
	res2 = printf("1: '%#10X'\n", 123);
	result(res1, res2);
	res1 = ft_printf("2: '%#010X'\n", 123);
	res2 = printf("2: '%#010X'\n", 123);
	result(res1, res2);
	res1 = ft_printf("3: '%# 5.15X'\n", 123);
	res2 = printf("3: '%# 5.15X'\n", 123);
	result(res1, res2);
	res1 = ft_printf("4: '%# 25.15X'\n", 123);
	res2 = printf("4: '%# 25.15X'\n", 123);
	result(res1, res2);
	res1 = ft_printf("5: '%#- 25.15x'\n", 123);
	res2 = printf("5: '%#- 25.15x'\n", 123);
	result(res1, res2);
		res1 = ft_printf("6: '%#5.x'\n", 123);
	res2 = printf("6: '%#5.x'\n", 123);
	result(res1, res2);
	res1 = ft_printf("7: '%+x'\n", 123);
	res2 = printf("7: '%+x'\n", 123);
	result(res1, res2);
	// %% tests
	puts("\n%%-------------------------");
	res1 = ft_printf("'%-10%%'\n");
	res2 = printf("'%-10%%'\n");
	result(res1, res2);
	res1 = ft_printf("'%10%%'\n");
	res2 = printf("'%10%%'\n");
	result(res1, res2);
}

void	bonus2(void)
{
	int	og_len;
	int	my_len;
	int	test01;
	int	test02;
	int	test03;

	og_len = 0;
	my_len = 0;
	test01 = 0;
	test02 = INT_MAX;
	test03 = INT_MIN;
	og_len += printf("1.Og:[%+40.d]\n", test01);
	my_len += ft_printf("1.My:[%+40.d]\n", test01);
	og_len += printf("2.Og:[%+40d]\n", test01);
	my_len += ft_printf("2.My:[%+40d]\n", test01);
	og_len += printf("3.Og:[%-+40.20d]\n", test01);
	my_len += ft_printf("3.My:[%-+40.20d]\n", test01);
	og_len += printf("4.Og:[%+35.25d]\n", test01);
	my_len += ft_printf("4.My:[%+35.25d]\n", test01);
	og_len += printf("5.Og:[%+-35.25d]\n", test01);
	my_len += ft_printf("5.My:[%+-35.25d]\n", test01);
	og_len += printf("6.Og:[%-+40.d]\n", test01);
	my_len += ft_printf("6.My:[%-+40.d]\n", test01);
	ft_printf("\n");
	og_len += printf("1.Og:[%+40.d]\n", test02);
	my_len += ft_printf("1.My:[%+40.d]\n", test02);
	og_len += printf("2.Og:[%+40d]\n", test02);
	my_len += ft_printf("2.My:[%+40d]\n", test02);
	og_len += printf("3.Og:[%-+80.20d]\n", test02);
	my_len += ft_printf("3.My:[%-+80.20d]\n", test02);
	og_len += printf("4.Og:[%+35.25d]\n", test02);
	my_len += ft_printf("4.My:[%+35.25d]\n", test02);
	og_len += printf("5.Og:[%+-35.25d]\n", test02);
	my_len += ft_printf("5.My:[%+-35.25d]\n", test02);
	og_len += printf("6.Og:[%+-40.d]\n", test02);
	my_len += ft_printf("6.My:[%+-40.d]\n", test02);
	ft_printf("\n");
	og_len += printf("1.Og:[%+40.d]\n", test03);
	my_len += ft_printf("1.My:[%+40.d]\n", test03);
	og_len += printf("2.Og:[%0+40d]\n", test03);
	my_len += ft_printf("2.My:[%0+40d]\n", test03);
	og_len += printf("3.Og:[%+-40.20d]\n", test03);
	my_len += ft_printf("3.My:[%+-40.20d]\n", test03);
	og_len += printf("4.Og:[%+50.35d]\n", test03);
	my_len += ft_printf("4.My:[%+50.35d]\n", test03);
	og_len += printf("5.Og:[%-+50.25d]\n", test03);
	my_len += ft_printf("5.My:[%-+50.25d]\n", test03);
	og_len += printf("6.Og:[%-+70.d]\n", test03);
	my_len += ft_printf("6.My:[%-+70.d]\n", test03);
	result(my_len, og_len);
}

int	main(void)
{
	puts("***************************************************");
	//basic();
	bonus1();
	//bonus2();
}
*/