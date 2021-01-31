/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_strdup.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjinichi <tjinichi@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/30 16:50:57 by tjinichi          #+#    #+#             */
/*   Updated: 2021/01/30 17:16:04 by tjinichi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libasm.h"

void	test_strdup(char *str)
{
	printf("strdup source : %s\nmemory : %p\n\n", str, str);
	char	*s1;
	s1 = ft_strdup(str);
	printf("ft_strdup : %s\nmemory : %p\n", s1, s1);
	char	*s2;
	s2 = strdup(str);
	printf("strdup    : %s\nmemory : %p\n", s2, s2);
	free(s1);
	free(s2);
}
