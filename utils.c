#include "philo.h"

long gettime(t_time_code time_code)
{
    struct timeval tv;
    if (gettimeofday(&tv, NULL))
        error_exit("gettimeofday failed");
    if(SECOND == time_code)
        return (tv.tv_sec +(tv.tv_usec/ 1e6));
    else if(MILLISECOND == time_code)
        return((tv.tv_sec * 1e3) + (tv.tv_usec / 1e3));
    else if(MICROSECOND == time_code)
        return((tv.tv_sec * 1e6) + tv.tv_usec);
    else 
        error_exit("Wrong input to get time!");
    return(1337);
}

void precised_usleep(long usec, t_table *table)
{
    long start;
    long elapsed;
    long rem;
    start = gettime(MICROSECOND);
    while(gettime(MICROSECOND)- start < usec)
    {
        if(simualtaion_finished(table))
            break;
        elapsed = gettime(MICROSECOND) - start;
        rem = usec - elapsed;
        if(rem > 1e3)
            usleep(rem / 2);
        else 
        {
            while(gettime(MICROSECOND) - start > usec);
        }
    }
}

int error_exit(const char *error)
{
    printf("Error:%s \n", error);
    return(1);
}                 