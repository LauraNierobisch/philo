#ifndef PHILO_H
# define PHILO_H
#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<stdbool.h>
#include<pthread.h>
#include<sys/time.h>
#include<limits.h>
#include<errno.h>

#define DEBUG_MODE 0

typedef enum e_status
{
    EATING,
    SLEEPING,
    THINKING,
    TAKE_FIRST_FORK,
    TAKE_SECOND_FORK,
    DIED,
}   t_philo_status;


typedef enum e_opcode 
{
    LOCK,
    UNLOCK,
    INIT,
    DESTROY,
    JOIN,
    DETACH,
    CREATE,
} t_opcode;
typedef enum e_time_code
{
    SECOND,
    MILLISECOND,
    MICROSECOND,
}   t_time_code;

typedef pthread_mutex_t t_mtx;

typedef struct s_fork
{
    t_mtx fork;
    int fork_id;
}   t_fork;

typedef struct s_philo;
typedef struct s_philo;

struct s_table
{
    long philo_nbr;
    long time_to_die;
    long time_to_eat;
    long time_to_sleep;
    long nbr_limit_meals;
    long start_simulation;
    bool end_simulation;
    bool all_threads_ready;
    t_mtx table_mutex;
    t_mtx write_mutex;
    t_fork *forks;
    t_philo **philo;
} t_table;

struct s_philo
{
    int id;
    long meal_counter;
    bool full;
    long last_meal_time;
    t_fork  *first_fork;
    t_fork  *second_fork;
    pthread_t thread_id;
    t_mtx philo_mutex;
    t_table *table;
}   t_philo;


void    parse_input(t_table *table, char *argv[]);
void    *save_malloc(size_t bytes);
void    safe_mutex_handle(t_mtx *mutex, t_opcode opcode);
void    safe_thread_handle(pthread_t *thread, void *(*foo)(void*), void *data, t_opcode opcode);
void    data_init(t_table *table);
void set_bool(t_mtx *mutex, bool *dest, bool value);
bool get_bool(t_mtx *mutex, bool *value);
long get_long(t_mtx *mutex, long *value);
void set_long(t_mtx *mutex, long *dest, long value);
bool simualtaion_finished(t_table *table);
void wait_all_threads(t_table *table);
int error_exit(const char *error);
long gettime(t_time_code time_code);
void precised_usleep(long usec, t_table *table);
void write_status(t_philo_status status, t_philo *philo);
#endif