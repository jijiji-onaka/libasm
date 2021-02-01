/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_write.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjinichi <tjinichi@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/30 15:47:04 by tjinichi          #+#    #+#             */
/*   Updated: 2021/02/02 02:18:14 by tjinichi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libasm.h"

void	test_write(int fd, char *str)
{
	ssize_t	rc;

	printf("ft_write\n[");
	errno = 0;
	if (str == NULL)
		rc = ft_write(fd, str, 1);
	else
		rc = ft_write(fd, str, strlen(str));
	printf("]\n");
	printf("return_value:[%ld]\nstrerror:[%s]\nerrno:[%d]\n", rc, strerror(errno), errno);
	printf("write\n[");
	errno = 0;
	if (str == NULL)
		rc = write(fd, str, 1);
	else
		rc = write(fd, str, strlen(str));
	printf("]\n");
	printf("return_value:[%ld]\nstrerror:[%s]\nerrno:[%d]\n", rc, strerror(errno), errno);
}
