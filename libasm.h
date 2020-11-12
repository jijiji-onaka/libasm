/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libasm.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjinichi <tjinichi@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/12 15:18:24 by tjinichi          #+#    #+#             */
/*   Updated: 2020/11/12 15:32:02 by tjinichi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBASM_H
# define LIBASM_H

#include <stdio.h>
#include <unistd.h>
#include <string.h>

int			ft_strlen(const char *s);
int			ft_strcmp(const char *s1, const char *s2);
char		*ft_strcpy(char *dst, const char *src);
ssize_t		ft_read(int fildes, void *buf, size_t nbyte);
ssize_t		ft_write(int fildes, const void *buf, size_t nbyte);

#endif
