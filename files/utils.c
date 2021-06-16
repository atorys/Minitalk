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
			kill(pid, SIGUSR1);
		else
			kill(pid, SIGUSR2);
		mask /= 2;
		usleep(40);
	}
}
