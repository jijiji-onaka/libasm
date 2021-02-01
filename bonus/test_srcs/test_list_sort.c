/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_list_sort.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjinichi <tjinichi@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/31 20:05:24 by tjinichi          #+#    #+#             */
/*   Updated: 2021/02/01 03:44:29 by tjinichi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libasm_bonus.h"

void	test_list_sort(void)
{
	t_list	*lst;

	my_clang_list_push_front(&lst, "tjinichi");
	my_clang_list_push_front(&lst, "aaa");
	my_clang_list_push_front(&lst, "aaa");
	my_clang_list_push_front(&lst, "zzz");
	puts("============= Before sort ==============");
	t_list *begin = lst;
	while (lst)
	{
		t_list *tmp;
		tmp = lst->next;
		printf("%s\n", (char *)(lst->data));
		lst = tmp;
	}
	puts("============= after sort ==============");
	lst = begin;
	ft_list_sort(&lst, strcmp);
	while (lst)
	{
		t_list *tmp;
		tmp = lst->next;
		printf("%s\n", (char *)(lst->data));
		free(lst);
		lst = NULL;
		lst = tmp;
	}
	puts("============= *begin_list == NULL ==============");
	lst = NULL;
	ft_list_sort(&lst, strcmp);
	puts("OK");
	puts("============= begin_list == NULL ==============");
	ft_list_sort(NULL, strcmp);
	puts("OK");
	puts("============= Only one element. ==============");
	my_clang_list_push_front(&lst, "tjinichi");
	ft_list_sort(&lst, strcmp);
	while (lst)
	{
		t_list *tmp;
		tmp = lst->next;
		printf("%s\n", (char *)(lst->data));
		free(lst);
		lst = NULL;
		lst = tmp;
	}
}
