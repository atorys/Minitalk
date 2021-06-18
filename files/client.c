#include "minitalk.h"

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
	while (target[++i])
		byte_mask(pid, target[i]);
	byte_mask(pid, '\0');
}
