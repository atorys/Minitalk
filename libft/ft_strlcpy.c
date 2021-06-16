/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atory <atory@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/20 23:02:19 by atory             #+#    #+#             */
/*   Updated: 2021/04/27 17:57:14 by atory            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dest, const char *src, size_t destsize)
{
	size_t	i;

	if (!src)
		return (0);
	i = 0;
	if (destsize > 0)
	{
		while (i < destsize - 1 && src[i])
		{
			dest[i] = (char)src[i];
			i++;
		}
		dest[i] = '\0';
	}
	return (ft_strlen(src));
}
