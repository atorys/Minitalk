/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atory <atory@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/23 00:26:22 by atory             #+#    #+#             */
/*   Updated: 2021/04/27 18:08:46 by atory            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *str)
{
	long	digit;
	int		flag;

	digit = 0;
	flag = 1;
	while (*str == ' ' || *str == '\v' || *str == '\t' ||\
	 *str == '\f' || *str == '\r' || *str == '\n')
		str++;
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			flag = -1;
		str++;
	}
	while (*str >= '0' && *str <= '9' && *str)
	{
		if (digit * flag > 2147483647)
			return (-1);
		if (digit * flag < -2147483648)
			return (0);
		digit = (digit * 10) + (*str - '0');
		str++;
	}
	return (flag * (int)digit);
}
