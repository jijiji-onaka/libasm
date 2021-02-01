/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_read.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjinichi <tjinichi@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/30 15:16:23 by tjinichi          #+#    #+#             */
/*   Updated: 2021/02/02 02:16:30 by tjinichi         ###   ########.fr       */
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
	char	*error_messsage;
	int	errno_dup;
	errno = 0;
	rc = ft_read(fd, buf, 127);
	error_messsage = strerror(errno);
	errno_dup = errno;
	puts("\033[1mft_read\033[0m");
	printf("[%s]\n", buf);
	printf("return_value:[%ld]\nstrerror:[%s]\nerrno:[%d]\n", rc, error_messsage, errno);
	close(fd);

	char	buf1[150];
	i = -1;
	while (++i < 150)
		buf1[i] = '\0';
	if (filename[0] == '\0')
		fd = -1;
	else if ((fd = open(filename, O_RDONLY)) == -1)
	{
		perror("test_read : second open");
		exit(1);
	}
	char	*error_messsage1;
	int	errno_dup1;
	errno = 0;
	ssize_t	rc1;
	rc1 = read(fd, buf1, 127);
	error_messsage1 = strerror(errno);
	errno_dup1 = errno;
	puts("\033[1mread\033[0m");
	printf("[%s]\n", buf1);
	printf("return_value:[%ld]\nstrerror:[%s]\nerrno:[%d]\n", rc1, error_messsage1, errno);
	if (strcmp(buf, buf1) == 0 && rc == rc1 && strcmp(error_messsage1, error_messsage) == 0 && errno_dup == errno_dup1)
		OK;
	else
		NG;
	close(fd);
}
