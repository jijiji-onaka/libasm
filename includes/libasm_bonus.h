/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libasm_bonus.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjinichi <tjinichi@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/12 15:18:24 by tjinichi          #+#    #+#             */
/*   Updated: 2021/02/01 01:17:43 by tjinichi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBASM_BONUS_H
# define LIBASM_BONUS_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <string.h>
# include <errno.h>
# include <limits.h>
# include <fcntl.h>

typedef struct		s_list
{
	void			*data;
	struct s_list	*next;
}					t_list;

# define TITLE(x) printf("\033[36m\033[1m-------------%s---------------\033[m\n", x)

int		ft_list_size(t_list *begin_list);
void	ft_list_push_front(t_list **begin_list, void *data);
void	ft_list_remove_if(t_list **begin_list,
			void *data_ref, int (*cmp)(), void (*free_fct)(void *));
void	ft_list_sort(t_list **begin_list, int (*cmp)());
int		ft_atoi_base(char *str, char *base);

void	test_list_push_front(void);
void	test_list_size(void);
void	test_list_remove(void);
void	test_list_sort(void);
void	test_atoi_base(void);

t_list	*ft_create_elem(void *data);
void	my_clang_list_push_front(t_list **begin_list, void *data);

#endif
