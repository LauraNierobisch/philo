#include "philo.h"

void wait_all_threads(t_table *table)
{
    while (!get_bool(&table->table_mutex, &tabel->all_threads_ready))
    {}

}

bool all_threads_running()
{
	
}