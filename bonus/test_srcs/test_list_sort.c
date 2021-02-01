/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_list_sort.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjinichi <tjinichi@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/31 20:05:24 by tjinichi          #+#    #+#             */
/*   Updated: 2021/02/02 02:33:22 by tjinichi         ###   ########.fr       */
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
	STATUS("[Before list]");
	t_list *begin = lst;
	while (lst)
	{
		t_list *tmp;
		tmp = lst->next;
		printf("%s\n", (char *)(lst->data));
		lst = tmp;
	}
	STATUS("[Sorted list]");
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
	STATUS("[Pattern : *lst = NULL]");
	lst = NULL;
	ft_list_sort(&lst, strcmp);
	if (lst == NULL)
		puts("OK");
	else
		puts("NG");
	STATUS("[ft_list_sort(NULL, strcmp)]");
	ft_list_sort(NULL, strcmp);
	puts("OK");
	STATUS("[Only one element]");
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
