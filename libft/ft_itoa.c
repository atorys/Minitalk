/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atory <atory@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/22 16:22:55 by atory             #+#    #+#             */
/*   Updated: 2021/04/27 18:09:50 by atory            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_len(long n)
{
	int	len;

	len = 0;
	if (n <= 0)
	{
		len++;
		n = -1 * n;
	}
	while (n > 0)
	{
		len++;
		n = n / 10;
	}
	return (len);
}

static void	ft_addtostr(char *str, long n)
{
	int		flag;

	flag = 1;
	str[ft_len(n)] = '\0';
	if (n < 0)
	{
		str[0] = '-';
		n = n * -1;
		flag = 0;
	}
	if (n == 0)
		str[ft_len(n) - flag] = n % 10 + '0';
	while (n != 0)
	{
		str[ft_len(n) - flag] = n % 10 + '0';
		n = n / 10;
	}
}

char	*ft_itoa(int n)
{
	char	*str;

	str = malloc(sizeof(char) * ft_len((long)n) + 1);
	if (str)
	{
		ft_addtostr(str, (long)n);
		return (str);
	}
	return (NULL);
}
