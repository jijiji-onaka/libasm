/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_list_size.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjinichi <tjinichi@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/30 19:24:13 by tjinichi          #+#    #+#             */
/*   Updated: 2021/02/02 02:26:42 by tjinichi         ###   ########.fr       */
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

	STATUS("[Before list]");
	t_list *begin = lst;
	while (lst)
	{
		printf("%s\n", (char *)(lst->data));
		lst = lst->next;
	}
	lst = begin;
	STATUS("[Normal]");
	int	count = ft_list_size(lst);
	printf("%d\n", count);
	STATUS("[ft_list_size(NULL)]");
	count = ft_list_size(NULL);
	printf("%d\n", count);
	while (lst)
	{
		t_list	*tmp = lst->next;
		free(lst);
		lst = tmp;
	}
}
