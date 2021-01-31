/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_list_sort.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjinichi <tjinichi@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/31 20:05:24 by tjinichi          #+#    #+#             */
/*   Updated: 2021/01/31 20:59:29 by tjinichi         ###   ########.fr       */
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

// void	my_clang_list_sort(t_list **list, int (*cmp)())
// {
// 	void	*tmp;
// 	t_list	*begin;

// 	if (list == NULL || *list == NULL || (*list)->next == NULL)
// 		return ;
// 	begin = *list;
// 	while ((*list)->next)
// 	{
// 		if (cmp((*list)->data, (*list)->next->data) > 0)
// 		{
// 			tmp = (*list)->data;
// 			(*list)->data = (*list)->next->data;
// 			(*list)->next->data = tmp;
// 			*list = begin;
// 		}
// 		else
// 			*list = (*list)->next;
// 	}
// 	*list = begin;
// }

// int	main()
// {
// 	t_list	*lst;

// 	my_clang_list_push_front(&lst, "tjinichi");
// 	my_clang_list_push_front(&lst, "aaa");
// 	my_clang_list_push_front(&lst, "aaa");
// 	my_clang_list_push_front(&lst, "zzz");
// 	puts("============= Before sort ==============");
// 	t_list *begin = lst;
// 	while (lst)
// 	{
// 		t_list *tmp;
// 		tmp = lst->next;
// 		printf("%s\n", (char *)(lst->data));
// 		lst = tmp;
// 	}
// 	puts("============= after sort ==============");
// 	lst = begin;
// 	my_clang_list_sort(&lst, strcmp);
// 	while (lst)
// 	{
// 		t_list *tmp;
// 		tmp = lst->next;
// 		printf("%s\n", (char *)(lst->data));
// 		free(lst);
// 		lst = NULL;
// 		lst = tmp;
// 	}
// 	puts("============= *begin_list == NULL ==============");
// 	lst = NULL;
// 	my_clang_list_sort(&lst, strcmp);
// 	puts("OK");
// 	puts("============= begin_list == NULL ==============");
// 	my_clang_list_sort(NULL, strcmp);
// 	puts("OK");
// 	puts("============= Only one element. ==============");
// 	my_clang_list_push_front(&lst, "tjinichi");
// 	my_clang_list_sort(&lst, strcmp);
// 	while (lst)
// 	{
// 		t_list *tmp;
// 		tmp = lst->next;
// 		printf("%s\n", (char *)(lst->data));
// 		free(lst);
// 		lst = NULL;
// 		lst = tmp;
// 	}
// }
