/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjinichi <tjinichi@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/30 17:55:51 by tjinichi          #+#    #+#             */
/*   Updated: 2021/01/30 23:15:11 by tjinichi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libasm_bonus.h"

int	main()
{
	setbuf(stdout, NULL);
	TITLE("ft_list_push_front");
	test_list_push_front();

	TITLE("ft_list_size");
	test_list_size();

	TITLE("ft_list_remove");
	test_list_remove();
}

// __attribute__((destructor))
// void end()
// {
// 	system("leaks test");
// }
