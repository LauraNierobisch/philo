<<<<<<< HEAD
#include "philo.h"
=======
#include <philo.h>
>>>>>>> b442413cfd809e113991d976c65aabe501eb5137

static void	assign_forks(t_philo *philo, t_fork *forks, int position)
{
	int	philo_nbr;

	philo_nbr = philo->table->philo_nbr;
	philo->first_fork = &forks[(position + 1) % philo_nbr];
	philo->second_fork = &forks[position];
	if (philo->id % 2)
	{
		philo->first_fork = &forks[position];
		philo->second_fork = &forks[(position + 1) % philo_nbr];
	}
}

static void	philo_init(t_table *table)
{
	int		i;
	t_philo	*philo;

	i = -1;
	while (++i < table->philo_nbr)
	{
<<<<<<< HEAD
		philo = table->philo + i;
=======
		philo = table->philos + i;
>>>>>>> b442413cfd809e113991d976c65aabe501eb5137
		philo->id = i + 1;
		philo->full = false;
		philo->meal_counter = 0;
		philo->table = table;
<<<<<<< HEAD
		save_mutex_handle(&philo->philo_mutex, INIT);
=======
>>>>>>> b442413cfd809e113991d976c65aabe501eb5137
		assign_forks(philo, table->forks, i);
	}
}
void	data_init(t_table *table)
{
	int	i;

	i = -1;
	table->end_simulation = false;
<<<<<<< HEAD
	table->all_threads_ready = false;
	table->philo = save_malloc(sizeof(t_philo) * table->philo_nbr);
	save_mutex_handle(&table->table_mutex, INIT);
	table->forks = save_malloc(sizeof(t_fork) * table->philo_nbr);
	while (++i < table->philo_nbr)
	{
		save_mutex_handle(&table->forks[i].fork, INIT);
=======
	table->philos = safe_malloc(sizeof(t_philo) * table->philo_nbr);
	table->forks = safe_malloc(sizeof(t_fork) * table->philo_nbr);
	while (++i < table->philo_nbr)
	{
		safe_mutex_handle(&table->forks[i].fork, INIT);
>>>>>>> b442413cfd809e113991d976c65aabe501eb5137
		table->forks[i].fork_id = i;
	}
	philo_init(table);
}
