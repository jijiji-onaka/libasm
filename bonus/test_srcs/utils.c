/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjinichi <tjinichi@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/01 03:31:14 by tjinichi          #+#    #+#             */
/*   Updated: 2021/02/01 03:47:52 by tjinichi         ###   ########.fr       */
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

void	my_clang_list_sort(t_list **list, int (*cmp)())
{
	void	*tmp;
	t_list	*begin;

	if (list == NULL || *list == NULL || (*list)->next == NULL)
		return ;
	begin = *list;
	while ((*list)->next)
	{
		if (cmp((*list)->data, (*list)->next->data) > 0)
		{
			tmp = (*list)->data;
			(*list)->data = (*list)->next->data;
			(*list)->next->data = tmp;
			*list = begin;
		}
		else
			*list = (*list)->next;
	}
	*list = begin;
}
