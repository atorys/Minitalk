#include "minitalk.h"

void	error_case(char *message, int number)
{
	ft_putstr_fd(message, 2);
	exit(number);
}

void	byte_mask(int pid, char byte)
{
	int	mask;

	mask = 128;
	while (mask > 0)
	{
		if (mask & byte)
		{
			if (kill(pid, SIGUSR1) < 0)
				error_case("\033[0;33mFailed to send a signal.\033[0m\n", -42);
		}
		else
		{
			if (kill(pid, SIGUSR2) < 0)
				error_case("\033[0;33mFailed to send a signal.\033[0m\n", -42);
		}
		mask /= 2;
		usleep(120);
	}
}

int	valid_pid(char *pid)
{
	int	i;

	i = ft_atoi(pid);
	if (i <= 0 || i >= 99999)
		return (0);
	i = -1;
	while (pid[++i])
	{
		if (!(ft_isdigit(pid[i])))
			return (0);
	}
	return (1);
}
