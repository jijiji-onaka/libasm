/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_list_push_front.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjinichi <tjinichi@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/30 17:18:52 by tjinichi          #+#    #+#             */
/*   Updated: 2021/01/31 20:11:44 by tjinichi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libasm_bonus.h"

void	test_list_push_front(void)
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
	ft_list_push_front(&lst, "Takao");
	while (lst)
	{
		t_list *tmp;
		tmp = lst->next;
		printf("%s\n", (char *)(lst->data));
		free(lst);
		lst = tmp;
	}
	puts("============= argument = NULL ===============");
	ft_list_push_front(NULL, "Takao");
	puts("OK");
}


// int	main()
// {
// 	t_list	*lst;

// 	lst = NULL;
// 	ft_list_push_front(&lst, "ichiro");
// 	ft_list_push_front(&lst, "Jin");
// 	ft_list_push_front(&lst, "Takao");

// 	while (lst)
// 	{
// 		t_list	*tmp;
// 		tmp = lst->next;
// 		printf("%s\n", (char*)lst->data);
// 		free(lst);
// 		lst = tmp;
// 	}
// }
