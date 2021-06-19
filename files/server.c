#include "minitalk.h"

static void	zero(char *str, int *count, int *len)
{
	write(1, str, ft_strlen(str));
	*count = 0;
	*len = 0;
}

static void	itsworking(int signal)
{
	static int	count = 0;
	static char	str[1000] = {};
	static char	symbol = 0;
	static int	len = 0;

	usleep(15);
	count++;
	if (signal == SIGINT)
		error_case("\n\033[0;32m~*'.+Process finished with exit code 0+.'*~\n", 0);
	else
		symbol = (symbol << 1) | (signal == SIGUSR1);
	if (!(count % 8) && count)
	{
		if (symbol == '\0')
			len = -1;
		else
			str[len++] = symbol;
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

	write(1, "\033[0;37mProcess id: {\033[1;32m", 27);
	ft_putnbr_fd(getpid(), 1);
	write(1, "\033[0;37m}\033[0m\n", 13);
	ft_memset(&sigredirect, '\0', sizeof(sigredirect));
	sigredirect.sa_handler = itsworking;
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
