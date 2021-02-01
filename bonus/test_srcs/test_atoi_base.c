/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_atoi_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjinichi <tjinichi@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/31 22:59:47 by tjinichi          #+#    #+#             */
/*   Updated: 2021/02/01 23:41:47 by tjinichi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libasm_bonus.h"

void	test_atoi_base(void)
{
	puts("ERROR CASE");
	printf("%d\n", ft_atoi_base("", "123")); // -> 0
	printf("%d\n", ft_atoi_base("aaa", NULL)); // -> 0
	printf("%d\n", ft_atoi_base(NULL, "123456+7890")); // -> 0
	printf("%d\n", ft_atoi_base(NULL, NULL)); // -> 0
	printf("%d\n", ft_atoi_base("1", "123456+7890")); // -> 0
	printf("%d\n", ft_atoi_base("2", "123456-7890"));
	printf("%d\n", ft_atoi_base("12", "123456 7890"));
	printf("%d\n", ft_atoi_base("12", ""));
	printf("%d\n", ft_atoi_base("qqqqqqqq", "q"));


	puts("NORMAL CASE");
	printf("%d\n", ft_atoi_base("011", "01"));
	printf("%d\n", ft_atoi_base("   128", "2134567890")); // -> 107
	printf("%d\n", ft_atoi_base("   a128", "a2134567890")); // -> 261

	printf("%d\n", ft_atoi_base("2147483647", "0123456789"));
	printf("%d\n", ft_atoi_base("-2147483648", "0123456789"));
	printf("%d\n", ft_atoi_base(" 644yo", "01234567"));
	printf("%d\n", ft_atoi_base(" -644yo", "01234567"));
	printf("%d\n", ft_atoi_base(" 700chmod", "01234567"));
	printf("%d\n", ft_atoi_base("  -+\r++-+--ff\xff", "0123456789abcdef"));
	printf("%d\n", ft_atoi_base("yo", "01234567"));
	printf("%d\n", ft_atoi_base("-yo", "01234567"));
	puts("======================================");
	printf("%d\n", ft_atoi_base("10", "011"));
	printf("%d\n", ft_atoi_base("-++10101\xff", "01"));
}
