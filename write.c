#include "philo.h"

void	write_status(t_philo_status status, t_philo *philo)
{
	long elapsed;
	elapsed = gettime(MILLISECOND) - philo->table->start_simulation;
	if (philo->full)
		return ;
	save_mutex_handle(&philo->table->write_mutex, LOCK);
	// if(debug)
	//     write_status_debug(status,philo, elapsed);
	// else{
	if ((TAKE_FIRST_FORK == status || TAKE_SECOND_FORK == status)
		&& !simualtaion_finished(philo->table))
		printf(" %ld has taken a fork %d \n", elapsed, philo->id);
	else if (EATING == status && !simualtaion_finished(philo->table))
		printf(" %ld is eating %d \n ", elapsed, philo->id);
	else if (SLEEPING == status && !simualtaion_finished(philo->table))
		printf(" %ld is sleeping %d\n ", elapsed, philo->id);
	else if (THINKING == status && !simualtaion_finished(philo->table))
		printf(" %ld is thinking %d \n ", elapsed, philo->id);
	else if (DIED == status)
		printf(" %ld died %d \n ", elapsed, philo->id);
	// }
	save_mutex_handle(&philo->table->write_mutex, UNLOCK);
}