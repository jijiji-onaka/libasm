/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_strlen.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjinichi <tjinichi@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/28 18:45:45 by tjinichi          #+#    #+#             */
/*   Updated: 2021/02/02 02:04:23 by tjinichi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libasm.h"

void	test_strlen(char *arg)
{
	printf("[strlen(\"%s\")]", arg);
	size_t rc1, rc2;
	rc1 = ft_strlen(arg);
	rc2 = strlen(arg);
	if (rc1 == rc2)
		OK;
	else
		NG;
	printf("ft_strlen : %zu\n", rc1);
	printf("   strlen : %zu\n", rc2);
}
