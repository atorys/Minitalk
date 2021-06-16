#include "minitalk.h"

static void	itsworking(int signal, siginfo_t *inf, void *text)
{
	static int	count = 0;
	static char	str[1000];
	static int	symbol = 0;

	count++;
	(void)text;
	if (signal == SIGINT)
		error_case("\n\033[0;37m~*'.+Process finished with exit code 0+.'*~\n", 0);
	else
		symbol = (symbol << 1) | (signal == SIGUSR1);
	if (!(count % 8) && count)
	{
		str[count / 8 - 1] = symbol;
		symbol = 0;
	}
	if (count % 8000 == 0 || (str[count / 8 - 1] == '\0' && ft_strlen(str) > 0))
	{
		write(1, str, ft_strlen(str));
		if (str[count / 8 - 1] == '\0')
		{
			kill(inf->si_pid, SIGUSR1);
			ft_putchar_fd('\n', 1);
			ft_putnbr_fd(inf->si_pid, 1);
		}
		ft_memset(&str, '\0', 1000);
		count = 0;
	}
}

int	main(void)
{
	struct sigaction	sigredirect;
	sigset_t			my_signals;
	char				*pid;

	pid = ft_itoa(getpid());
	write(1, "\033[0;37mProcess id: {\033[1;32m", 27);
	write(1, pid, ft_strlen(pid));
	free(pid);
	write(1, "\033[0;37m}\033[0m\n", 13);
	ft_memset(&sigredirect, '\0', sizeof(sigredirect));
	sigredirect.sa_sigaction = itsworking;
	sigemptyset(&my_signals);
	sigaddset(&my_signals, SIGINT);
	sigaddset(&my_signals, SIGUSR1);
	sigaddset(&my_signals, SIGUSR2);
	sigredirect.sa_mask = my_signals;
	if (sigaction(SIGINT, &sigredirect, 0) == -1 || \
		sigaction(SIGUSR1, &sigredirect, 0) == -1 || \
		sigaction(SIGUSR2, &sigredirect, 0) == -1)
		error_case("\033[0;33mSigaction failed\033[0m\n", -2);
	while (1)
		;
}
