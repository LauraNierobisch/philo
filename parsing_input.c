#include "philo.h"

static bool	is_space(char c)
{
	if ((c >= 9 && c <= 13) || c == 32)
	{
		return (true);
	}
	return (false);
}

static bool	is_digit(char c)
{
	if (c >= '0' && c <= '9')
		return (true);
	return (false);
}

static const char	*valid_input(const char *str)
{
	int			len;
	const char	*num;

	len = 0;
	while (is_space(*str))
		++str;
	if (*str == '+')
		++str;
	else if (*str == '-')
	{
		printf("ERROR: Please only positive numbers!\n");
		return (NULL);
	}
	if (!is_digit(*str))
	{
		printf("ERROR: Please only numbers!\n");
		return (NULL);
	}
	num = str;
	while (is_digit(*str++))
		++len;
	if (len > 10)
	{
		printf("ERROR: Please only numbers under MAX_INT\n");
		return (NULL);
	}
	return (num);
}

static long	ft_atol(const char *str)
{
	long	num;

	num = 0;
	str = valid_input(str);
	if (!str)
		return (-1);
	while (is_digit(*str))
		num = (num * 10) + (*str++ - '0');
	if (num > INT_MAX)
	{
		printf("ERROR: Please only numbers under MAX_INT\n");
		return (-1);
	}
	return (num);
}

void	parse_input(t_table *table, char *argv[])
{
	table->philo_nbr = ft_atol(argv[1]);
	table->time_to_die = ft_atol(argv[2]) * 1000;
	table->time_to_eat = ft_atol(argv[3]) * 1000;
	table->time_to_sleep = ft_atol(argv[4]) * 1000;
	printf("table->philo_nbr %li\n", table->philo_nbr);
	printf("table->time_to_die %li\n", table->time_to_die);
	printf("table->time_to_eat %li\n", table->time_to_eat);
	printf("table->time_to_sleep %li\n", table->time_to_sleep);
	if (table->time_to_die < 60000 || table->time_to_eat < 60000
		|| table->time_to_sleep < 60000)
	{
		printf("ERROR: please use Timestamps > 60ms!\n");
		return ;
	}
	if (argv[5])
	{
		table->nbr_limit_meals = ft_atol(argv[5]);
	}
	else
		table->nbr_limit_meals = -1;
}
