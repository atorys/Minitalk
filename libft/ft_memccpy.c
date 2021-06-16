/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atory <atory@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/20 22:06:34 by atory             #+#    #+#             */
/*   Updated: 2021/04/27 18:10:05 by atory            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dest, const void *src, int c, size_t n)
{
	unsigned char	*srccpy;
	unsigned char	*destcpy;
	unsigned char	a;
	size_t			i;

	srccpy = (unsigned char *)src;
	destcpy = (unsigned char *)dest;
	a = (unsigned char)c;
	i = 0;
	while (n > 0)
	{
		destcpy[i] = srccpy[i];
		if (srccpy[i] == a)
		{
			destcpy[i] = srccpy[i];
			return ((void *)&destcpy[i + 1]);
		}
		i++;
		n--;
	}
	return (NULL);
}
