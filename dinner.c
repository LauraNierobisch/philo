#include "philo.h"

static void	thinking(t_philo *philo)
{
	write_status(THINKING, philo);
}
static void	eat(t_philo *philo)
{
	save_mutex_handle(&philo->first_fork->fork, LOCK);
	write_status(TAKE_FIRST_FORK, philo);
	save_mutex_handle(&philo->second_fork->fork, LOCK);
	write_status(TAKE_SECOND_FORK, philo);
	set_long(&philo->philo_mutex, &philo->last_meal_time, gettime(MILLISECOND));
	philo->meal_counter++;
	write_status(EATING, philo);
	precised_usleep(philo->table->time_to_eat, philo->table);
	if (philo->table->nbr_limit_meals > 0
		&& philo->meal_counter == philo->table->nbr_limit_meals)
	{
		set_bool(&philo->philo_mutex, &philo->full, true);
	}
	save_mutex_handle(&philo->first_fork->fork, UNLOCK);
	save_mutex_handle(&philo->second_fork->fork, UNLOCK);
}

void	*dinner_simulation(void *data)
{
	t_philo	*philo;

	philo = (t_philo *)data;
	// wait_all_threads(philo->table);
	while (!simualtaion_finished(philo->table))
	{
		if (philo->full)
			break ;
		eat(philo);
		write_status(SLEEPING, philo);
		precised_usleep(philo->table->time_to_sleep, philo->table);
		thinking(philo);
	}
	return (NULL);
}

void	dinner_start(t_table *table)
{
	int i;
	i = -1;
	if (0 == table->nbr_limit_meals)
		return ;
	else if (1 == table->philo_nbr)
	{
	}
	else
	{
		while (++i < table->philo_nbr)
			safe_thread_handle(&table->philo[i].thread_id, dinner_simulation,
				&table->philo[i], CREATE);
	}
	table->start_simulation = gettime(MILLISECOND);

	set_bool(&table->table_mutex, &table->all_threads_ready, true);
	i = -1;
	while (++i < table->philo_nbr)
		safe_thread_handle(&table->philo[i].thread_id, NULL, NULL, JOIN);
}