/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atory <atory@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/20 21:47:02 by atory             #+#    #+#             */
/*   Updated: 2021/04/27 18:10:20 by atory            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	unsigned char	*srccpy;
	unsigned char	*destcpy;

	srccpy = (unsigned char *)src;
	destcpy = (unsigned char *)dest;
	if (n == 0 || destcpy == srccpy)
		return (dest);
	while (n > 0)
	{
		*destcpy = *srccpy;
		destcpy++;
		srccpy++;
		n--;
	}
	return (dest);
}
