/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libasm.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjinichi <tjinichi@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/12 15:18:24 by tjinichi          #+#    #+#             */
/*   Updated: 2021/02/02 02:02:41 by tjinichi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBASM_H
# define LIBASM_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <string.h>
# include <errno.h>
# include <limits.h>
# include <fcntl.h>
# include <math.h>

# define TITLE(x) printf("\033[36m\033[1m-------------%s---------------\033[m\n", x)
# define OK puts("\033[0;32m\033[1m ---> OK\033[0m")
# define NG puts("\033[0;31m\033[1m ---> NG\033[0m")

size_t	ft_strlen(const char *str);
int		ft_strcmp(const char *s1, const char *s2);
char	*ft_strcpy(char *dst, const char *src);
ssize_t	ft_read(int fildes, void *buf, size_t nbyte);
ssize_t	ft_write(int fildes, const void *buf, size_t nbyte);
char	*ft_strdup(const char *s1);

void	test_strlen(char *arg);
void	test_strcmp(char *s1, char *s2);
void	test_strcpy(char s1[10], char *s2);
void	test_read(char *filename);
void	test_write(int fd, char *str);
void	test_strdup(char *str);

#endif
