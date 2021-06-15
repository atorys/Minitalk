#include "minitalk.h"

static void itsworking(int signal)
{
	if (signal == SIGUSR1)
		ft_putstr_fd("1\n", 1);
	if (signal == SIGUSR2)
		ft_putstr_fd("0\n", 1);
}

int	main(void)
{
	pid_t	id;

	id = getpid();

	ft_putnbr_fd(id, 1);
	ft_putchar_fd('\n', 1);
	signal(SIGUSR1, itsworking);
	signal(SIGUSR2, itsworking);
	while (1) ;
}