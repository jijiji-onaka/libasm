/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_list_size.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjinichi <tjinichi@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/30 19:24:13 by tjinichi          #+#    #+#             */
/*   Updated: 2021/01/31 19:48:29 by tjinichi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libasm_bonus.h"

static t_list	*ft_create_elem(void *data)
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

static void my_clang_list_push_front(t_list **begin_list, void *data)
{
	t_list	*new;

	new = ft_create_elem(data);
	new->next = *begin_list;
	*begin_list = new;
}

// int	ft_list_size(t_list *lst)
// {
// 	int count = 0;
// 	while (lst)
// 	{
// 		count++;
// 		lst = lst->next;
// 	}
// 	return (count);
// }

void	test_list_size(void)
{
	t_list	*lst;

	lst = NULL;
	my_clang_list_push_front(&lst, "ichiro");
	my_clang_list_push_front(&lst, "Jin");
	my_clang_list_push_front(&lst, "Takao");

puts("============= Normal =============");
	int	count = ft_list_size(lst);
	printf("%d\n", count);
	while (lst)
		lst = lst->next;
puts("============= lst == NULL =============");
	count = ft_list_size(lst);
	printf("%d\n", count);
}


// int	main()
// {
// 	t_list	*lst;

// 	lst = NULL;
// 	ft_list_push_front(&lst, "ichiro");
// 	ft_list_push_front(&lst, "Jin");
// 	ft_list_push_front(&lst, "Takao");

// 	int	count = ft_list_size(lst);
// 	printf("%d\n", count);
// }
