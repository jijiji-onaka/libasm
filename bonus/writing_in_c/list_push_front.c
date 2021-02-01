/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_push_front.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjinichi <tjinichi@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/01 03:44:14 by tjinichi          #+#    #+#             */
/*   Updated: 2021/02/01 03:45:42 by tjinichi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libasm_bonus.h"

t_list	*ft_create_elem(void *data)
{
	t_list	*list;

	list = malloc(sizeof(t_list));
	if (list)
	{
		list->data = data;
		list->next = NULL;
	}
	return (list);
}

void my_clang_list_push_front(t_list **begin_list, void *data)
{
	t_list	*new;

	if (begin_list == NULL)
		return ;
	new = ft_create_elem(data);
	new->next = *begin_list;
	*begin_list = new;
}

int	main()
{
	t_list *lst;

	lst = NULL;
	my_clang_list_push_front(&lst, "ichiro");
	my_clang_list_push_front(&lst, "Jin");

	puts("============= Before list ==============");
	t_list *begin = lst;
	while (lst)
	{
		t_list *tmp;
		tmp = lst->next;
		printf("%s\n", (char *)(lst->data));
		lst = tmp;
	}
	puts("============= push front ===============");
	lst = begin;
	my_clang_list_push_front(&lst, "Takao");
	while (lst)
	{
		t_list *tmp;
		tmp = lst->next;
		printf("%s\n", (char *)(lst->data));
		free(lst);
		lst = tmp;
	}
	puts("============= argument = NULL ===============");
	my_clang_list_push_front(NULL, "Takao");
	puts("OK");
}
