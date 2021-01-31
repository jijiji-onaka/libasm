/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_strcpy.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjinichi <tjinichi@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/28 21:56:21 by tjinichi          #+#    #+#             */
/*   Updated: 2021/01/30 17:16:04 by tjinichi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libasm.h"

void	test_strcpy(char s1[10], char *s2)
{
	printf("[strcpy(\"%s\", \"%s\")]\n", s1, s2);
	printf("ft_strcpy : [%s]\n", ft_strcpy(s1, s2));
	char	strcpy_buf[10] = "abcdefgh";
	printf("   strcpy : [%s]\n", strcpy(strcpy_buf, s2));
	puts("");
}
