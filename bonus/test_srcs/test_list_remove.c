/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_list_remove.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjinichi <tjinichi@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/30 19:51:53 by tjinichi          #+#    #+#             */
/*   Updated: 2021/02/02 02:31:19 by tjinichi         ###   ########.fr       */
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

	STATUS("[Before list]");
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
	STATUS("[Remove middle data(= ft_services)]");
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
	STATUS("[Remove first data(= first)]");
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
	STATUS("[Remove last data(= last)]");
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
	STATUS("[Pattern : *lst = NULL]");
	lst = NULL;
	ft_list_remove_if(&lst, "ft_services", strcmp, FREE);
	if (lst == NULL)
		puts("OK");
	else
		puts("NG");
	STATUS("[All same data]");
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
	ft_list_remove_if(&lst, "same", strcmp, FREE);
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
