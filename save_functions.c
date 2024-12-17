#include <philo.h>

void *save_malloc(size_t bytes)
{
    void *ret;
    ret = malloc(bytes);
    if(NULL == ret)
        {
            printf("malloc Error");
            return(0);
        }
    return(ret);
}
static void handle_mutex_error(int status, t_opcode opcode)
{
    if(0 == status)
        return;
    if(EINVAL == status && (LOCK == opcode || UNLOCK == opcode || DESTROY == opcode))
    {
        printf("the value specified by mutex is invalid");
        return(1);
    }
    else if (EINVAL == status && INIT == opcode)
    {
        printf("the value specified by attr is invalid");
        return(1);
    }
    else if (EDEADLK == status)
    {
        printf("deadlock would occure");
        return(1);
    }
    else if(EPERM == status)
    {
        printf("the current thread  does not hold a lock on mutex");
        return(1);
    }
    else if(ENOMEM == status)
    {
        printf("the process can not alocate enought memory to create another mutex");
        return(1);   
    }
    else if(EBUSY == status)
    {
        printf("mutex is locked");
        return(1);
    }
}
void safe_mutex_handle(t_mtx *mutex, t_opcode opcode)
{
    if(LOCK == opcode)
        handle_mutex_error(pthread_mutex_lock(mutex), opcode);
    else if(UNLOCK == opcode)
        handle_mutex_error(pthread_mutex_unlock(mutex), opcode);
    else if(INIT == opcode)
        handle_mutex_error(pthread_mutex_init(mutex, NULL), opcode);
    else if (DESTROY == opcode)
        handle_mutex_error(pthread_mutex_destroy(mutex), opcode);
    else 
    {
        printf("Wrong opcode for mutex!");
        return(1);
    }
}
