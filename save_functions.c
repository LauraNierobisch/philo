#include "philo.h"

void	*save_malloc(size_t bytes)
{
	void	*ret;

	ret = malloc(bytes);
	if (NULL == ret)
	{
		error_exit("malloc Error");
	}
	return (ret);
}
static int	handle_mutex_error(int status, t_opcode opcode)
{
	if (0 == status)
		return(1) ;
	if (EINVAL == status && (LOCK == opcode || UNLOCK == opcode
			|| DESTROY == opcode))
	{
		error_exit("the value specified by mutex is invalid");
		return(1);
	}
	else if (EINVAL == status && INIT == opcode)
	{
		error_exit("the value specified by attr is invalid");
		return (1);
	}
	else if (EDEADLK == status)
	{
		error_exit("deadlock would occure");
		return (1);
	}
	else if (EPERM == status)
	{
		error_exit("the current thread  does not hold a lock on mutex");
		return (1);
	}
	else if (ENOMEM == status)
	{
		error_exit("the process can not alocate enought memory to create another mutex");
		return (1);
	}
	else if (EBUSY == status)
	{
		error_exit("mutex is locked");
		return (1);
	}
	return(0);
}
int	save_mutex_handle(t_mtx *mutex, t_opcode opcode)
{
	if (LOCK == opcode)
	{
		if(handle_mutex_error(pthread_mutex_lock(mutex), opcode) == 1)
			return(1);
	}
	else if (UNLOCK == opcode)
	{
		if(handle_mutex_error(pthread_mutex_unlock(mutex), opcode) == 1)
			return(1);
	}
	else if (INIT == opcode)
{
		if(handle_mutex_error(pthread_mutex_init(mutex, NULL), opcode) == 1)
			return(1);
}
	else if (DESTROY == opcode)
	{
		if(handle_mutex_error(pthread_mutex_destroy(mutex), opcode) == 1)
			return(1);
	}
	else
	{
		error_exit("Wrong opcode for mutex!");
		return(1);
	}
	return(0);
}
static void	handle_thread_error(int status, t_opcode opcode)
{
	if (0 == status)
		return ;
	if (EAGAIN == status)
		error_exit("Error no resurce to build another thread");
	else if (EPERM == status)
		error_exit("Tthe caller does not have appropriate permission");
	else if (EINVAL == status && CREATE == opcode)
		error_exit("The value specified by attr is invalid");
	else if (EINVAL == status && (JOIN == opcode || DETACH == opcode))
		error_exit("The value speciefied by the thread is not joinable");
	else if (ESRCH == status)
		error_exit("no thread could be found corresponding to that to the ID thread");
	else if (EDEADLK == status)
		error_exit("Error deadlock was detected");
}
void	safe_thread_handle(pthread_t *thread, void *(*foo)(void *), void *data,
		t_opcode opcode)
{
	if (CREATE == opcode)
		handle_thread_error(pthread_create(thread, NULL, foo, data), opcode);
	else if (JOIN == opcode)
		handle_thread_error(pthread_join(*thread, NULL), opcode);
	else if (DETACH == opcode)
		handle_thread_error(pthread_detach(*thread), opcode);
	else
	{
		error_exit("Wrong opcode for thread_handle");
	}
}