#include "philo.h"

long gettim(t_time_code time_code)
{
    struct timeval tv;
    if (gettimeofday(&tv, NULL))
        error_exit("gettimeofday failed");
    
}

int error_exit(const char *error)
{
    printf("Error:%s \n", error);
    return(1);
}                 