/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_strlen.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjinichi <tjinichi@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/28 18:45:45 by tjinichi          #+#    #+#             */
/*   Updated: 2021/01/30 17:16:04 by tjinichi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libasm.h"

void	test_strlen(char *arg)
{
	printf("[strlen(\"%s\")]\n", arg);
	printf("ft_strlen : %zu\n", ft_strlen(arg));
	printf("   strlen : %zu\n", strlen(arg));
	puts("");
}
