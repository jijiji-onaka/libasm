/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_strcpy.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjinichi <tjinichi@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/28 21:56:21 by tjinichi          #+#    #+#             */
/*   Updated: 2021/02/02 02:09:04 by tjinichi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libasm.h"

void	test_strcpy(char s1[10], char *s2)
{
	char	s3[10] = "abcdefgh";
	printf("[strcpy(\"%s\", \"%s\")]\n", s1, s2);
	char *rc1, *rc2;
	rc1 = ft_strcpy(s1, s2);
	rc2 = strcpy(s3, s2);
	if (strcmp(rc1, rc2) == 0)
		OK;
	else
		NG;
	printf("ft_strcpy : [%s]\n", rc1);
	printf("   strcpy : [%s]\n", rc2);
}
