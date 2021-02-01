/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_strcmp.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjinichi <tjinichi@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/28 18:45:45 by tjinichi          #+#    #+#             */
/*   Updated: 2021/02/02 02:04:00 by tjinichi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libasm.h"

void		test_strcmp(char *s1, char *s2)
{
	printf("[strcmp(\"%s\", \"%s\")]", s1, s2);
	int	rc1, rc2;
	rc1 = ft_strcmp(s1, s2);
	rc2 = strcmp(s1, s2);
	if (signbit(rc1) == signbit(rc2))
		OK;
	else
		NG;
	printf("ft_strcmp : %d\n", rc1);
	printf("   strcmp : %d\n", rc2);
}
