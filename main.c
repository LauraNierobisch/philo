#include "philo.h"

int	main(int argc, char *argv[])
{
	t_table table;
	if ((argc == 5) || (argc == 6))
	{
		if (parse_input(&table, argv) == 1)
			return (1);
		if(data_init(&table) == 1)
			return(1);
		dinner_start(&table);
		// clean(&table);
	}
	else
	{
		printf("Error: 5 or 6 arguments are needed please!");
		return (1);
	}
	return (0);
}