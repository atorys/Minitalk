#include "minitalk.h"

static void error_case(char *message, int number)
{
	ft_putstr_fd(message, 2);
	exit(number);
}

int	main(int argc, char *argv[])
{
	int	pid;

	if (argc != 3)
		error_case("Invalid configuration", 1);
	pid = ft_atoi(argv[1]);
	ft_putnbr_fd(pid,1);
	kill(pid, SIGUSR1);
	usleep(1);
	kill(pid, SIGUSR1);
	usleep(1);
	kill(pid, SIGUSR2);
	usleep(1);
	kill(pid, SIGUSR2);
}