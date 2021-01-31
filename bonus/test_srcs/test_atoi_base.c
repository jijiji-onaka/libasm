/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_atoi_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjinichi <tjinichi@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/31 22:59:47 by tjinichi          #+#    #+#             */
/*   Updated: 2021/02/01 02:12:45 by tjinichi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libasm_bonus.h"

void	test_atoi_base(void)
{
	printf("%d\n", ft_atoi_base("aaa", NULL)); // -> 0
	printf("%d\n", ft_atoi_base(NULL, "123456+7890")); // -> 0
	printf("%d\n", ft_atoi_base(NULL, NULL)); // -> 0
	printf("%d\n", ft_atoi_base("1", "123456+7890")); // -> 0
	printf("%d\n", ft_atoi_base("2", "123456-7890"));
	printf("%d\n", ft_atoi_base("12", "123456 7890"));
	printf("%d\n", ft_atoi_base("12", ""));
	printf("%d\n", ft_atoi_base("qqqqqqqq", "q"));


	printf("%d\n", ft_atoi_base("   128", "2134567890")); // -> 107
	printf("%d\n", ft_atoi_base("   a128", "a2134567890")); // -> 261
	// printf("%d\n", ft_atoi_base("456", "1234567890"));
	// printf("%d\n", ft_atoi_base("789", "1234567890"));
}

// int		ft_atoi_base(char *str, char *base)
// {
// 	int	charset[255] = {0};

// 	if (str == NULL || base == NULL)
// 		return (0);
// 	while (*str && (*str == '\t' || *str == '\n' || *str == '\v' ||
// 			*str == '\f' || *str == '\r' || *str == ' '))
// 		str++;
// 	int	len = 0;
// 	while (base[len])
// 	{
// 		if (charset[base[len]] != 0)
// 			return (0);
// 		charset[base[len]] += len + 1;
// 		if (base[len] == '-' || base[len] == '+' || base[len] == ' ')
// 			return (0);
// 		len++;
// 	}
// 	if (len < 2)
// 		return (0);
// 	int	ret = 0;
// 	while (*str)
// 	{
// 		ret *= len;
// 		ret += charset[*str] - 1;
// 		str++;
// 	}
// 	return (ret);
// }

// int	main()
// {
// 	printf("%d\n", ft_atoi_base("1", "123456+7890")); // -> 0
// 	printf("%d\n", ft_atoi_base("2", "123456-7890"));
// 	printf("%d\n", ft_atoi_base("12", "123456 7890"));
// 	printf("%d\n", ft_atoi_base("12", ""));
// 	printf("%d\n", ft_atoi_base("qqqqqqqq", "q"));


// 	printf("%d\n", ft_atoi_base("   128", "2134567890")); // -> 107
// 	printf("%d\n", ft_atoi_base("   a128", "a2134567890")); // -> 261
// 	// printf("%d\n", ft_atoi_base("456", "1234567890"));
// 	// printf("%d\n", ft_atoi_base("789", "1234567890"));
// }
