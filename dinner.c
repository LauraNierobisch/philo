#include "philo.h"

void *dinner_simulation(void *data)
{
    t_philo *philo;
    philo = (t_philo *)data;
    wait_all_threads(philo->table);
    return(NULL);
}

void dinner_start(t_table *table)
{
    int i;
    i = -1;
    if(0== table->nbr_limit_meals)
        return;
    else if(1== table->philo_nbr)
    {

    }
    else 
    {
        while(++i < table->philo_nbr)
            safe_thread_handle(&table->philo[i]->thread_id, dinner_simulation, &table->philo[i], CREATE);
    }
    
    set_bool(&table->table_mutex, &table->all_threads_ready, true);

}