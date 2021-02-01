/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_list_push_front.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjinichi <tjinichi@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/30 17:18:52 by tjinichi          #+#    #+#             */
/*   Updated: 2021/02/02 02:26:51 by tjinichi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libasm_bonus.h"

void	test_list_push_front(void)
{
	t_list *lst;

	lst = NULL;
	my_clang_list_push_front(&lst, "ichiro");
	my_clang_list_push_front(&lst, "Jin");

	STATUS("[Before list]");
	t_list *begin = lst;
	while (lst)
	{
		printf("%s\n", (char *)(lst->data));
		lst = lst->next;
	}
	STATUS("[ft_list_push_front(&lst, arg)]");
	lst = begin;
	ft_list_push_front(&lst, "Takao");
	while (lst)
	{
		t_list *tmp;
		tmp = lst->next;
		printf("%s\n", (char *)(lst->data));
		free(lst);
		lst = tmp;
	}
	STATUS("[ft_list_push_front(NULL, arg)]");
	ft_list_push_front(NULL, "Takao");
	puts("OK");
}
