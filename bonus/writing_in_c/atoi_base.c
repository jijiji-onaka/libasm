/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   atoi_base.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjinichi <tjinichi@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/01 03:46:07 by tjinichi          #+#    #+#             */
/*   Updated: 2021/02/02 00:00:53 by tjinichi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libasm_bonus.h"

int		my_clang_atoi_base(char *str, char *base)
{
	int	charset[256];

	if (str == NULL || base == NULL)
		return (0);
	int i = 0;
	while (i < 256)
	{
		charset[i] = 0;
		i++;
	}
	while (*str && (*str == '\t' || *str == '\n' || *str == '\v' ||
			*str == '\f' || *str == '\r' || *str == ' '))
		str++;
	i = 0;
	while (*base)
	{
		if (*base == '-' || *base == '+' || *base == '\t' || *base == '\n' || *base == '\v' ||
			*base == '\f' || *base == '\r' || *base == ' ')
			return (0);
		if (charset[*base] != 0)
			return (0);
		charset[*base] += i + 1;
		base++;
		i++;
	}
	printf("len = %d\n", i );
	if (i < 2)
		return (0);
	int	flag = 1;
	while (*str && (*str == '-' || *str == '+'))
	{
		flag *= (44 - *str);
		str++;
	}
	int	ret = 0;
	while (*str && *str >= 0 && (charset[*str] != 0))
	{
		ret *= i;
		ret += charset[*str] - 1;
		str++;
	}
	return (ret * flag);
}

# define TO_STRING(x) (#x)

int	main()
{
	printf("%d\n", my_clang_atoi_base("aaa", NULL)); // -> 0
	printf("%d\n", my_clang_atoi_base(NULL, "123456+7890")); // -> 0
	printf("%d\n", my_clang_atoi_base(NULL, NULL)); // -> 0
	printf("%d\n", my_clang_atoi_base("1", "123456+7890")); // -> 0
	printf("%d\n", my_clang_atoi_base("2", "123456-7890"));
	printf("%d\n", my_clang_atoi_base("12", "123456 7890"));
	printf("%d\n", my_clang_atoi_base("12", ""));
	printf("%d\n", my_clang_atoi_base("qqqqqqqq", "q"));


	printf("%d\n", my_clang_atoi_base("011", "01"));
	printf("%d\n", my_clang_atoi_base("   128", "2134567890")); // -> 107
	printf("%d\n", my_clang_atoi_base("   a128", "a2134567890")); // -> 261

	printf("%d\n", my_clang_atoi_base("2147483647", "0123456789"));
	printf("%d\n", my_clang_atoi_base("-2147483648", "0123456789"));
	printf("%d\n", my_clang_atoi_base(" 644yo", "01234567"));
	printf("%d\n", my_clang_atoi_base(" -644yo", "01234567"));
	printf("%d\n", my_clang_atoi_base(" 700chmod", "01234567"));
	printf("%d\n", my_clang_atoi_base("  -+\r++-+--ff\xff", "0123456789abcdef"));
	printf("%d\n", my_clang_atoi_base("yo", "01234567"));
	printf("%d\n", my_clang_atoi_base("-yo", "01234567"));
	puts("==");
	printf("%d\n", my_clang_atoi_base("-++++++-+--ff\xff", "0123456789abcdef"));
	printf("%d\n", my_clang_atoi_base("10", "011"));
	printf("%d\n", my_clang_atoi_base("-++10101\xff", "01"));
	// printf("%d\n", my_clang_atoi_base("456", "1234567890"));
	// printf("%d\n", my_clang_atoi_base("789", "1234567890"));
}
