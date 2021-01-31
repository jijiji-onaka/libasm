#include "includes/libasm_bonus.h"

int		ft_atoi_base(char *str, char *base)
{
	int	charset[255];

	if (str == NULL || base == NULL)
		return (0);
	int i = 0;
	while (i < 256)
		charset[i++] = 0;
	while (*str && (*str == '\t' || *str == '\n' || *str == '\v' ||
			*str == '\f' || *str == '\r' || *str == ' '))
		str++;
	int	len = 0;
	while (*base)
	{
		if (charset[*base] != 0)
			return (0);
		charset[*base] += len + 1;
		if (*base == '-' || *base == '+' || *base == ' ')
			return (0);
		base++;
		len++;
	}
	if (len < 2)
		return (0);
	int	ret = 0;
	while (*str)
	{
		ret *= len;
		ret += charset[*str] - 1;
		str++;
	}
	return (ret);
}
