/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjinichi <tjinichi@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/12 15:15:45 by tjinichi          #+#    #+#             */
/*   Updated: 2020/11/12 15:33:02 by tjinichi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// nasm -f macho64 ft_strlen.s && gcc ../main.c ft_strlen.o && ./a.out

#include "libasm.h"

int main()
{
	int a, b;
	a = ft_strlen("Hello world.\n");
	b = strlen("Hello world.\n");
	printf("ft_strlen : %d, strlen : %d\n", a, b);
}
