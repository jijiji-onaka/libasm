/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_read.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjinichi <tjinichi@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/30 15:16:23 by tjinichi          #+#    #+#             */
/*   Updated: 2021/01/30 17:16:04 by tjinichi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libasm.h"

void	test_read(char *filename)
{
	int		fd;
	char	buf[150];
	int		i;
	ssize_t	rc;

	i = -1;
	while (++i < 150)
		buf[i] = '\0';
	if (filename[0] == '\0')
		fd = -1;
	else if ((fd = open(filename, O_RDONLY)) == -1)
	{
		perror("test_read : first open");
		exit(1);
	}
	errno = 0;
	rc = ft_read(fd, buf, 127);
	puts("ft_read");
	printf("[%s]\n", buf);
	printf("return_value:[%ld]\nstrerror:[%s]\nerrno:[%d]\n", rc, strerror(errno), errno);
	close(fd);

	i = -1;
	while (++i < 150)
		buf[i] = '\0';
	if (filename[0] == '\0')
		fd = -1;
	else if ((fd = open(filename, O_RDONLY)) == -1)
	{
		perror("test_read : second open");
		exit(1);
	}
	errno = 0;
	rc = read(fd, buf, 127);
	puts("\nread");
	printf("[%s]\n", buf);
	printf("return_value:[%ld]\nstrerror:[%s]\nerrno:[%d]\n\n", rc, strerror(errno), errno);
	close(fd);
}
