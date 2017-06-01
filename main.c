/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kzakharc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/19 15:52:16 by kzakharc          #+#    #+#             */
/*   Updated: 2017/05/07 21:09:32 by kzakharc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <limits.h>
#include <stdio.h>
#include <locale.h>

int     main(void)
{
	setlocale(LC_ALL, "");
	const wchar_t B[] = L"ድመቶች ሰዎች አልወደውም.";
/*	ft_printf("\n");
	ft_printf("%%\n");
	ft_printf("%d\n", 42);
	ft_printf("%d%d\n", 42, 41);
	ft_printf("%d%d%d\n", 42, 43, 44);
	ft_printf("%ld\n", 2147483647);
	ft_printf("%lld\n", 9223372036854775807);
	ft_printf("%x\n", 505);
	ft_printf("%X\n", 505);
	ft_printf("%p\n", &ft_printf);
	ft_printf("%20.15d\n", 54321);
	ft_printf("%-10d\n", 3);
	ft_printf("% d\n", 3);
	ft_printf("%+d\n", 3);
	ft_printf("%010d\n", 1);
	ft_printf("%hhd\n", 0);
	ft_printf("%jd\n", 9223372036854775807);
	ft_printf("%zd\n", 4294967295);
	ft_printf("%\n");
	ft_printf("%U\n", 4294967295);
	ft_printf("%u\n", 4294967295);
	ft_printf("%o\n", 40);
	ft_printf("%%#08x\n", 42);
	ft_printf("%x\n", 1000);
	ft_printf("%#X\n", 1000);
	ft_printf("%s\n", NULL);
	ft_printf("%S\n", L"ݗݜशব");
	ft_printf("%s%s\n", "test", "test");
	ft_printf("%s%s%s\n", "test", "test", "test");
	ft_printf("%C\n", 15000);

	while (1);*/

	printf("count: %d\n", ft_printf("%4.15S\n", L"ÊM-M-^QÊM-^XØ‰∏M-ÂM-^O™ÁM-^L´„M-M-^B"));
	/*printf("my count: %d\n", ft_printf("ft_printf(c): %-10c\n", 65));
	printf("my count: %d\n", ft_printf("ft_printf(s): %-25.3s\n", "print string"));
	printf("my count: %d\n", ft_printf("ft_printf(o): %#-10.3o  %o\n", 173, -256));
	printf("my count: %d\n", ft_printf("ft_printf(u): %-10.6u  %u\n", 173, -256));
	printf("my count: %d\n", ft_printf("ft_printf(x/X): %#-10.5x  %X\n%%\n", 173, -256));
	printf("my count: %d\n", ft_printf("ft_printf(p): %p\n", 100));*/
	printf("__________________________________\n");
	/*printf("count: %d\n", printf("or_printf(c): %-10c\n", 65));
	printf("count: %d\n", printf("or_printf(s): %-25.3s\n", "print string"));
	printf("count: %d\n", printf("or_printf(o): %#-10.3o  %o\n", 173, -256));
	printf("count: %d\n", printf("or_printf(u): %-10.6u  %u\n", 173, -256));
	printf("count: %d\n", printf("or_printf(x/X): %#-10.5x  %X\n%%\n", 173, -256));
	printf("count: %d\n", printf("or_printf(p): %p\n", 100));*/
	printf("count: %d\n", printf("%4.15S\n", L"ÊM-M-^QÊM-^XØ‰∏M-ÂM-^O™ÁM-^L´„M-M-^B"));
	printf("__________________________________");
	return (0);
}

