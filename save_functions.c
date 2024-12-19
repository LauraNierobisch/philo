#include <philo.h>

void *save_malloc(size_t bytes)
{
    void *ret;
    ret = malloc(bytes);
    if(NULL == ret)
        {
            printf("malloc Error");
            return;
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
        return;
    }
    else if (EINVAL == status && INIT == opcode)
    {
        printf("the value specified by attr is invalid");
        return;
    }
    else if (EDEADLK == status)
    {
        printf("deadlock would occure");
        return;
    }
    else if(EPERM == status)
    {
        printf("the current thread  does not hold a lock on mutex");
        return;
    }
    else if(ENOMEM == status)
    {
        printf("the process can not alocate enought memory to create another mutex");
        return;   
    }
    else if(EBUSY == status)
    {
        printf("mutex is locked");
        return;
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
static void handle_thread_error(int status, t_opcode opcode)
{
    if(0 == status)
        return;
    if(EAGAIN == status)
        error_exit("Error no resurce to build another thread");
    else if(EPERM == status)
        error_exit("Tthe caller does not have appropriate permission");
    else if(EINVAL == status && CREATE == opcode)
        error_exit("The value specified by attr is invalid");
    else if(EINVAL == status && (JOIN == opcode || DETACH == opcode))
        error_exit("The value speciefied by the thread is not joinable");
    else if (ESRCH == status)
        error_exit("no thread could be found corresponding to that to the ID thread");
    else if(EDEADLK == status)
        error_exit("Error deadlock was detected");

}
void safe_thread_handle(pthread_t *thread, void *(*foo)(void*), void *data, t_opcode opcode)
{
    if(CREATE == opcode)
        handle_thread_error(pthread_create(thread,NULL, foo, data),opcode);
    else if(JOIN == opcode)
        handle_thread_error(pthread_join(*thread, NULL),opcode);
    else if(DETACH == opcode)
        handle_thread_error(pthread_detach(*thread), opcode);
    else 
    {
        error_exit("Wrong opcode for thread_handle");
    }
}