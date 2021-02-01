/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_atoi_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjinichi <tjinichi@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/31 22:59:47 by tjinichi          #+#    #+#             */
/*   Updated: 2021/02/02 02:54:14 by tjinichi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libasm_bonus.h"

static int	TEST(char *s1, char *s2)
{
	if (s1 == NULL && s2 == NULL)
		printf("ft_atoi_base(NULL, NULL)");
	else if (s1 == NULL)
		printf("ft_atoi_base(NULL, \"%s\")", s2);
	else if (s2 == NULL)
		printf("ft_atoi_base(\"%s\", NULL)", s1);
	else
		printf("ft_atoi_base(\"%s\", \"%s\")", s1, s2);
	int	a = ft_atoi_base(s1, s2);
	printf(" Got : [%d]", a);
	return (a);
}

void		test_atoi_base(void)
{
	STATUS("[ERROR CASE]");
	if (TEST("aaa", NULL) == 0)
		OK;
	else
		NG;
	if (TEST(NULL, "123456+7890") == 0)
		OK;
	else
		NG;
	if (TEST(NULL, NULL) == 0)
		OK;
	else
		NG;
	if (TEST("1", "123456+7890") == 0)
		OK;
	else
		NG;
	if (TEST("2", "123456-7890") == 0)
		OK;
	else
		NG;
	if (TEST("12", "123456 7890") == 0)
		OK;
	else
		NG;
	if (TEST("12", "") == 0)
		OK;
	else
		NG;
	if (TEST("12", "") == 0)
		OK;
	else
		NG;
	if (TEST("10", "011") == 0)
		OK;
	else
		NG;
	if (TEST("10", "012222221") == 0)
		OK;
	else
		NG;

	STATUS("[NORMAL CASE]");
	if (TEST("", "123") == 0)
		OK;
	else
		NG;
	if (TEST("   128", "2134567890") == 107)
		OK;
	else
		NG;
	if (TEST("   a128", "a2134567890") == 261)
		OK;
	else
		NG;
	if (TEST("yo", "01234567") == 0)
		OK;
	else
		NG;
	if (TEST("-yo", "01234567") == 0)
		OK;
	else
		NG;

	puts("\n\n\033[4mBinary number\033[0m");
	if (TEST("011", "01") == 3)
		OK;
	else
		NG;
	if (TEST("-++10101Tokyo", "01") == -21)
		OK;
	else
		NG;
	if (TEST("-+-+10101Tokyo", "01") == 21)
		OK;
	else
		NG;

	puts("\n\033[4mOctal number\033[0m");
	if (TEST(" -+-644Tokyo", "01234567") == 420)
		OK;
	else
		NG;
	if (TEST(" -+--644Tokyo", "01234567") == -420)
		OK;
	else
		NG;
	if (TEST(" -+--700Tokyo", "01234567") == -448)
		OK;
	else
		NG;

	puts("\n\033[4mDecimal number\033[0m");
	if (TEST("2147483647", "0123456789") == 2147483647)
		OK;
	else
		NG;
	if (TEST("-2147483648", "0123456789") == -2147483648)
		OK;
	else
		NG;
	if (TEST("10", "0123456789") == 10)
		OK;
	else
		NG;

	puts("\n\033[4mHexadecimal number\033[0m");
	if (TEST("  -+++-+--ff\aaaa", "0123456789abcdef") == 255)
		OK;
	else
		NG;
}
