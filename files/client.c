#include "minitalk.h"

void byte_mask(int pid, char byte)
{
	int mask;

	mask = 1;
	while (mask <= 128)
	{
		if (mask & byte)
			kill(pid, SIGUSR1);
		else
			kill(pid, SIGUSR2);
		mask *= 2;
		usleep(1);
	}
}

int	main(int argc, char *argv[])
{
	int		pid;
	char	*target;
	int		i;

	if (argc != 3)
		error_case("Invalid configuration", 1);
	pid = ft_atoi(argv[1]);
	target = argv[2];
	i = -1;
	while (target[++i])
	{
		byte_mask(pid, target[i]);
	}
}