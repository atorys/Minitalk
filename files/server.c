#include "minitalk.h"

static void itsworking(int signal)
{
	if (signal == SIGUSR1)
		ft_putstr_fd("1\n", 1);
	if (signal == SIGUSR2)
		ft_putstr_fd("0\n", 1);
	if (signal == SIGINT)
	{
		write(1, "\n\033[1m\033[32m~*'.+ Process end with exit code 0 +.'*~\n", 51);
		exit(0);
	}
}

int	main(void)
{
	struct sigaction	sigredirect;
	pid_t				id;
	sigset_t			my_signals;
	char 				buff[1000 + 1];

	id = getpid();

	write(1, ft_strjoin("Process id: {\033[1m\033[32m", ft_itoa(id)), ft_strlen(ft_itoa(id)) + 22);
	write(1, "\033[0m}\n", 6);

	ft_memset(&sigredirect, '\0', sizeof(sigredirect));
	sigredirect.sa_handler = itsworking;

	sigemptyset(&my_signals);
	sigaddset(&my_signals, SIGINT);
	sigaddset(&my_signals, SIGUSR1);
	sigaddset(&my_signals, SIGUSR2);

	sigredirect.sa_mask = my_signals;
	if (sigaction(SIGINT, &sigredirect, 0) == -1 || \
		sigaction(SIGUSR1, &sigredirect, 0) == -1 || \
		sigaction(SIGUSR2, &sigredirect, 0) == -1)
		error_case("Sigaction failed", -2);
	while (1) ;
}