#include "push_swap.h"
#include <unistd.h>
#include <stdlib.h>

int	ft_isspace(char c)
{
	if (c == ' ' || c == '\n' || c == '\t'
		|| c == '\v' || c == '\f' || c == '\r')
		return (1);
	return (0);
}

int	ft_isdigit(int c)
{
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}

int ft_issign(char c)
{
	if (c == '+' || c == '-')
		return (1);
	return (0);
}

int	ft_atoi(const char *str)
{
	long long	i;
	int			sign;
	int			res;

	i = 0;
	sign = 1;
	res = 0;
	while (ft_isspace(str[i]))
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign *= -1;
		i++;
	}
	while (ft_isdigit(str[i]))
	{
		res = res * 10 + (str[i] - '0');
		i++;
	}
	res = res * sign;
	write(1, &str[i], 1);
	if (str[i] != '\0' || i > 10 || res > 2147483647 || res < -2147483648)
		print_error(1);
	return (res);
}

void	print_error(int num)
{
	if (num == 1)
		write(1, "ERROR\n", 6);
	exit(1);
}