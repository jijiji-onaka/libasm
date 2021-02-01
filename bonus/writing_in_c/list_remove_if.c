/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_remove_if.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjinichi <tjinichi@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/01 03:37:44 by tjinichi          #+#    #+#             */
/*   Updated: 2021/02/01 18:03:43 by tjinichi         ###   ########.fr       */
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

void	FREE(void *ptr)
{
	free(ptr);
}

void	my_clang_list_remove_if(t_list **list,
			void *data, int (*cmp)(), void (*free_fct)(void *))
{
	t_list	*begin;
	t_list	*save;

	begin = *list;
	if (*list == NULL)
		return ;
	while (*list && (*list)->next)
	{
		if (cmp(data, (*list)->next->data) == 0)
		{
			save = (*list)->next;
			(*list)->next = (*list)->next->next;
			free_fct(save->data);
			free(save);
		}
		else
			*list = (*list)->next;
	}
	*list = begin;
	if (cmp(data, (*list)->data) == 0)
	{
		save = (*list)->next;
		free_fct((*list)->data);
	    free(*list);
		*list = save;
	}
}

int	main()
{
	t_list	*lst;

	puts("============= Before list ==============");
	lst = NULL;
	my_clang_list_push_front(&lst, strdup("last"));
	my_clang_list_push_front(&lst, "ichiro");
	my_clang_list_push_front(&lst, "Jin");
	my_clang_list_push_front(&lst, strdup("ft_services"));
	my_clang_list_push_front(&lst, "Takao");
	my_clang_list_push_front(&lst, strdup("first"));
	t_list	*begin = lst;
	while (lst)
	{
		printf("%s\n", (char *)(lst->data));
		lst = lst->next;
	}
	puts("============= Remove middle data(= ft_services) ==============");
	lst = begin;
	my_clang_list_remove_if(&lst, "ft_services", strcmp, FREE);
	t_list	*begin1 = lst;
	while (lst)
	{
		t_list *tmp;
		tmp = lst->next;
		printf("%s\n", (char *)(lst->data));
		lst = tmp;
	}
	puts("============= Remove first data(= first) ==============");
	lst = begin1;
	my_clang_list_remove_if(&lst, "first", strcmp, FREE);
	t_list	*begin2 = lst;
	while (lst)
	{
		t_list *tmp;
		tmp = lst->next;
		printf("%s\n", (char *)(lst->data));
		lst = tmp;
	}
	puts("============= Remove last data(= last) ==============");
	lst = begin2;
	my_clang_list_remove_if(&lst, "last", strcmp, FREE);
	while (lst)
	{
		t_list *tmp;
		tmp = lst->next;
		printf("%s\n", (char *)(lst->data));
		free(lst);
		lst = tmp;
	}
	puts("============= *begin == NULL pattern ================");
	lst = NULL;
	my_clang_list_remove_if(&lst, "ft_services", strcmp, FREE);
	printf("%p\n", lst);
	puts("============= all same data ================");
	lst = NULL;
	my_clang_list_push_front(&lst, strdup("same"));
	my_clang_list_push_front(&lst, strdup("same"));
	my_clang_list_push_front(&lst, strdup("same"));
	my_clang_list_push_front(&lst, strdup("same"));
	my_clang_list_push_front(&lst, strdup("same"));
	my_clang_list_push_front(&lst, strdup("same"));
	my_clang_list_push_front(&lst, strdup("same"));
	my_clang_list_push_front(&lst, strdup("same"));
	my_clang_list_push_front(&lst, strdup("same"));
	my_clang_list_remove_if(&lst, "same", strcmp, FREE);
	int	f = 0;
	while (lst)
	{
		f = 1;
		t_list *tmp;
		tmp = lst->next;
		printf("%s\n", (char *)(lst->data));
		free(lst);
		lst = tmp;
	}
	if (f == 0)
		puts("OK");
	else
		puts("NG");
}
