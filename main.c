#include "philo.h"

int main(int argc, char *argv[])
{
	t_table table;
	if((argc == 5)|| (argc == 6))
	{
		parse_input(&table,argv);
		data_init(&table);
		//dinner_start(&table);
		//clean(&table);
	}
	else 
	{
		printf("Error: 5 or 6 arguments are needed please!");
		return(1);
	}
	return(0);
}