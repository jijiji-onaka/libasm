/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjinichi <tjinichi@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/12 15:15:45 by tjinichi          #+#    #+#             */
/*   Updated: 2021/01/31 23:55:33 by tjinichi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// nasm -f macho64 ft_strlen.s && gcc ../main.c ft_strlen.o && ./a.out

#include "includes/libasm.h"

int output_all(void)
{
	TITLE("strlen");
	test_strlen("42Tokyo");
	test_strlen("");
	TITLE("strcmp");
	test_strcmp("abc", "abc");
	test_strcmp("abc", "ab");
	test_strcmp("ab", "abc");
	test_strcmp("bc", "ac");
	test_strcmp("ac", "bc");
	test_strcmp("", "bc");
	test_strcmp("ab", "");
	test_strcmp("", "");
	char	strcmp_buf[12] = "abcdefg";
	strcmp_buf[3] = 240;
	test_strcmp(strcmp_buf, "abcdefg");

	TITLE("strcpy");
	char strcpy_buf[10] = "abcdefgh";
	test_strcpy(strcpy_buf, "abc");
	test_strcpy(strcpy_buf, "");
	TITLE("read");
	test_read("readfile");
	test_read("");
	TITLE("write");
	test_write(1, "42Tokyo");
	test_write(1, "");
	test_write(-1, "");
	test_write(1, NULL);
	int fd = open("writefile", O_WRONLY);
	ft_write(fd, "hello\n", 6);
	write(fd, "hello\n", 6);
	close(fd);
	write(1, "hello\n", 6);
	ft_write(42, "hello\n", 6);
	write(1, "hello\n", 6);
	TITLE("strdup");
	test_strdup("Jinichiro");
	test_strdup("42Tokyo");
	return (0);
}

int main(int argc, char **argv)
{
	setbuf(stdout, NULL);
	if (argc == 1)
		return (output_all());
	if (strcmp(argv[1], "strlen") == 0)
	{
		TITLE("strlen");
		test_strlen("42Tokyo");
		test_strlen("");
	}
	else if (strcmp(argv[1], "strcmp") == 0)
	{
		TITLE("strcmp");
		test_strcmp("abc", "abc");
		test_strcmp("abc", "ab");
		test_strcmp("ab", "abc");
		test_strcmp("bc", "ac");
		test_strcmp("ac", "bc");
		test_strcmp("", "bc");
		test_strcmp("ab", "");
		test_strcmp("", "");
		char strcmp_buf[12] = "abcdefg";
		strcmp_buf[3] = 240;
		test_strcmp(strcmp_buf, "abcdefg");
	}
	else if (strcmp(argv[1], "strcpy") == 0)
	{
		TITLE("strcpy");
		char	strcpy_buf[10] = "abcdefgh";
		test_strcpy(strcpy_buf, "abc");
		test_strcpy(strcpy_buf, "");
	}

	else if (strcmp(argv[1], "read") == 0)
	{
		TITLE("read");
		test_read("readfile");
		test_read("");
		char	buf[1024];
		ft_read(0, buf, 1023);
	}

	else if (strcmp(argv[1], "write") == 0)
	{
		TITLE("write");
		test_write(1, "42Tokyo");
		test_write(1, "");
		test_write(-1, "");
		test_write(1, NULL);
		int fd = open("writefile", O_WRONLY);
		ft_write(fd, "hello\n", 6);
		write(fd, "hello\n", 6);
	}
	else if (strcmp(argv[1], "strdup") == 0)
	{
		TITLE("strdup");
		test_strdup("Jinichiro");
		test_strdup("42Tokyo");
	}
}
