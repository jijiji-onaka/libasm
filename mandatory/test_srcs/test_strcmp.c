/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_strcmp.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjinichi <tjinichi@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/28 18:45:45 by tjinichi          #+#    #+#             */
/*   Updated: 2021/01/30 17:16:04 by tjinichi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libasm.h"

void	test_strcmp(char *s1, char *s2)
{
	printf("[strcmp(\"%s\", \"%s\")]\n", s1, s2);
	printf("ft_strcmp : %d\n", ft_strcmp(s1, s2));
	printf("   strcmp : %d\n", strcmp(s1, s2));
	puts("");
}
