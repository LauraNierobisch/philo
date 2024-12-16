#ifndef PHILO_H
# define PHILO_H
# include <limits.h>
# include <pthread.h>
# include <stdbool.h>
# include <stdio.h>
# include <stdlib.h>
# include <sys/time.h>
# include <unistd.h>

typedef pthread_mutex_t	t_mtx;

typedef struct s_fork
{
	t_mtx				fork;
	int					fork_id;
}						t_fork;

typedef struct s_philo
{
	int					id;
	long				meal_counter;
	bool				full;
	long				last_meal_time;
	t_fork				*left_fork;
	t_fork				*right_fork;
	pthread_t			thread_id;
}						t_philo;

typedef struct s_table
{
	long				philo_nbr;
	long				time_to_die;
	long				time_to_eat;
	long				time_to_sleep;
	long				nbr_limit_meals;
	long				start_simulation;
	bool				end_simulation;
	t_fork				*forks;
	t_philo				**philos;
}						t_table;

void					parse_input(t_table *table, char *argv[]);

#endif