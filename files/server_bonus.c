#include "minitalk.h"

static void	zero(char *str, int *count, int *len)
{
	write(1, str, ft_strlen(str));
	*count = 0;
	*len = 0;
}

static void	itsworking(int signal, siginfo_t *inf, void *text)
{
	static int	count = 0;
	static char	str[1000] = {};
	static char	symbol = 0;
	static int	len = 0;

	count++;
	(void)text;
	if (signal == SIGINT)
		error_case("\n\033[0;32m~*'.+Process finished with exit code 0+.'*~\n", 0);
	else
		symbol = (symbol << 1) | (signal == SIGUSR1);
	if (!(count % 8) && count)
	{
		str[len++] = symbol;
		if (symbol == '\0')
			len = -1;
		if (len < 0)
			kill(inf->si_pid, SIGUSR1);
		symbol = 0;
	}
	if (len == 999 || len < 0)
	{
		zero(str, &count, &len);
		ft_bzero(&str, ft_strlen(str));
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
	while (1)
	{
		if (sigaction(SIGINT, &sigredirect, 0) == -1 || \
		sigaction(SIGUSR1, &sigredirect, 0) == -1 || \
		sigaction(SIGUSR2, &sigredirect, 0) == -1)
			error_case("\033[0;33mSigaction failed\033[0m\n", -2);
	}
}
