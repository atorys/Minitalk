/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atory <atory@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/21 01:06:26 by atory             #+#    #+#             */
/*   Updated: 2021/04/27 01:06:02 by atory            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	if (ft_strlen(needle) == 0)
		return ((char *)haystack);
	if (ft_strlen(needle) == 1)
		return (ft_memchr(haystack, needle[0], len));
	if (haystack[0] == '\0')
		return (NULL);
	while (ft_strlen(needle) <= len && (char)haystack[i])
	{
		while ((char)needle[j] && (char)haystack[i + j] == (char)needle[j])
			j++;
		if ((char)needle[j] == '\0')
			return ((char *)&haystack[i]);
		i++;
		j = 0;
		len--;
	}
	return (NULL);
}
