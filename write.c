#include "philo.h"

void write_status(t_philo_status status, t_philo *philo)
{
    long elapsed;
    elapsed = gettime(MILLISECOND) - philo->table->start_simulation;
    if(philo->full)
        return;
    safe_mutex_handle(&philo->table->write_mutex, LOCK);
    // if(debug)
    //     write_status_debug(status,philo, elapsed);
    // else{
    if((TAKE_FIRST_FORK == status || TAKE_SECOND_FORK == status) && !simualtaion_finished(philo->table))
        printf(" %d has taken a fork \n", elapsed, philo->id);
    else if(EATING == status && !simualtaion_finished(philo->table))
        printf(" %d is eating \n ", elapsed, philo ->id);
    else if(SLEEPING == status && !simualtaion_finished(philo->table))
        printf(" %d is sleeping \n ", elapsed, philo ->id);
     else if(THINKING == status && !simualtaion_finished(philo->table))
        printf(" %d is thinking \n ", elapsed, philo ->id);
     else if(DIED == status)
        printf(" %d died \n ", elapsed, philo ->id);
    // }
    safe_mutex_handle(&philo->table->write_mutex, UNLOCK);
}