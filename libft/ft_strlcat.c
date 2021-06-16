/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atory <atory@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/21 00:17:55 by atory             #+#    #+#             */
/*   Updated: 2021/04/27 17:24:50 by atory            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t size)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = ft_strlen(dest);
	if (ft_strlen(dest) >= size)
		return (ft_strlen(src) + size);
	if (size > 0)
	{
		while (i < size - j - 1 && src[i] != '\0')
		{
			dest[i + j] = (char)src[i];
			i++;
		}
		dest[i + j] = '\0';
		if (src[i] != '\0' && i >= size - j - 1)
			return (ft_strlen(dest) + ft_strlen(src) - i);
	}
	return (j + ft_strlen(src));
}
