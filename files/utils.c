#include "minitalk.h"

void error_case(char *message, int number)
{
	ft_putstr_fd(message, 2);
	exit(number);
}
