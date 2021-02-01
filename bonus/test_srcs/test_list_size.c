/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_list_size.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjinichi <tjinichi@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/30 19:24:13 by tjinichi          #+#    #+#             */
/*   Updated: 2021/02/01 17:54:06 by tjinichi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libasm_bonus.h"

void	test_list_size(void)
{
	t_list	*lst;

	lst = NULL;
	my_clang_list_push_front(&lst, "ichiro");
	my_clang_list_push_front(&lst, "Jin");
	my_clang_list_push_front(&lst, "Takao");

puts("============= Normal =============");
	int	count = ft_list_size(lst);
	printf("%d\n", count);
puts("============= lst == NULL =============");
	count = ft_list_size(NULL);
	printf("%d\n", count);
	while (lst)
	{
		t_list	*tmp = lst->next;
		free(lst);
		lst = tmp;
	}
}
