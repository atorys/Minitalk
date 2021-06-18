#include "minitalk.h"

static void	process_request(int signal)
{
	if (signal == SIGUSR1)
		ft_putstr_fd("\033[0;32mMessage has been send\n", 1);
	exit(0);
}

int	main(int argc, char *argv[])
{
	int		pid;
	char	*target;
	int		i;

	if (argc != 3)
		error_case("\033[0;33mInvalid configuration\033[0m\n", 1);
	if (!valid_pid(argv[1]))
		error_case("\033[0;33mInvalid PID\033[0m\n", 1);
	pid = ft_atoi(argv[1]);
	target = argv[2];
	i = -1;
	signal(SIGUSR1, process_request);
	while (target[++i])
		byte_mask(pid, target[i]);
	byte_mask(pid, '\0');
	sleep(3);
	return (0);
}
