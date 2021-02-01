/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_size.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjinichi <tjinichi@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/01 03:42:33 by tjinichi          #+#    #+#             */
/*   Updated: 2021/02/01 03:43:57 by tjinichi         ###   ########.fr       */
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

	new = ft_create_elem(data);
	new->next = *begin_list;
	*begin_list = new;
}

int	ft_list_size(t_list *lst)
{
	if (lst == NULL)
		return (-1);
	int count = 0;
	while (lst)
	{
		count++;
		lst = lst->next;
	}
	return (count);
}

int	main()
{
	t_list *lst;

	lst = NULL;
	my_clang_list_push_front(&lst, "ichiro");
	my_clang_list_push_front(&lst, "Jin");
	my_clang_list_push_front(&lst, "Takao");

	puts("============= Normal =============");
	int count = ft_list_size(lst);
	printf("%d\n", count);
	while (lst)
		lst = lst->next;
	puts("============= lst == NULL =============");
	count = ft_list_size(lst);
	printf("%d\n", count);
}
