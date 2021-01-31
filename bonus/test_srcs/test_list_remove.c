/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_list_remove.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjinichi <tjinichi@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/30 19:51:53 by tjinichi          #+#    #+#             */
/*   Updated: 2021/01/31 20:08:06 by tjinichi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libasm_bonus.h"

void	FREE(void *ptr)
{
	free(ptr);
}

void	test_list_remove(void)
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
	ft_list_remove_if(&lst, "ft_services", strcmp, FREE);
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
	ft_list_remove_if(&lst, "first", strcmp, FREE);
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
	ft_list_remove_if(&lst, "last", strcmp, FREE);
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
	ft_list_remove_if(&lst, "ft_services", strcmp, FREE);
	printf("%p\n", lst);
}

// void	ft_list_remove_if2(t_list **list,
// 			void *data, int (*cmp)(), void (*free_fct)(void *))
// {
// 	t_list	*begin;
// 	t_list	*save;

// 	begin = *list;
// 	if (*list == NULL)
// 		return ;
// 	while (*list && (*list)->next)
// 	{
// 		if (cmp(data, (*list)->next->data) == 0)
// 		{
// 			save = (*list)->next;
// 			(*list)->next = (*list)->next->next;
// 			free(save->data);
// 			free(save);
// 		}
// 		*list = (*list)->next;
// 	}
// 	*list = begin;
// 	if (cmp(data, (*list)->data) == 0)
// 	{
// 		save = (*list)->next;
// 		free((*list)->data);
// 	    free(*list);
// 		*list = save;
// 	}
// }

// int	main()
// {
// 	t_list	*lst;

// 	puts("============= Before list ==============");
// 	lst = NULL;
// 	my_clang_list_push_front(&lst, strdup("last"));
// 	ft_list_push_front(&lst, "ichiro");
// 	ft_list_push_front(&lst, "Jin");
// 	ft_list_push_front(&lst, strdup("ft_services"));
// 	ft_list_push_front(&lst, "Takao");
// 	ft_list_push_front(&lst, strdup("first"));
// 	t_list	*begin = lst;
// 	while (lst)
// 	{
// 		printf("%s\n", (char *)(lst->data));
// 		lst = lst->next;
// 	}
// 	puts("============= Remove middle data(= ft_services) ==============");
// 	lst = begin;
// 	ft_list_remove_if2(&lst, "ft_services", strcmp, FREE);
// 	t_list	*begin1 = lst;
// 	while (lst)
// 	{
// 		t_list *tmp;
// 		tmp = lst->next;
// 		printf("%s\n", (char *)(lst->data));
// 		lst = tmp;
// 	}
// 	puts("============= Remove first data(= first) ==============");
// 	lst = begin1;
// 	ft_list_remove_if2(&lst, "first", strcmp, FREE);
// 	t_list	*begin2 = lst;
// 	while (lst)
// 	{
// 		t_list *tmp;
// 		tmp = lst->next;
// 		printf("%s\n", (char *)(lst->data));
// 		lst = tmp;
// 	}
// 	puts("============= Remove last data(= last) ==============");
// 	lst = begin2;
// 	ft_list_remove_if2(&lst, "last", strcmp, FREE);
// 	while (lst)
// 	{
// 		t_list *tmp;
// 		tmp = lst->next;
// 		printf("%s\n", (char *)(lst->data));
// 		free(lst);
// 		lst = tmp;
// 	}
// 	puts("============= *begin == NULL pattern ================");
// 	lst = NULL;
// 	ft_list_remove_if2(&lst, "ft_services", strcmp, FREE);
// 	printf("%p\n", lst);
// }
