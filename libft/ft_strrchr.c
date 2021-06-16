/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atory <atory@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/21 00:59:57 by atory             #+#    #+#             */
/*   Updated: 2021/04/27 18:05:38 by atory            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	size_t	i;
	char	*temp;

	temp = NULL;
	i = ft_strlen(s);
	if ((char)c == '\0' && s[ft_strlen(s)] == (char)c)
		return ((char *)s + i);
	while (*s)
	{
		if (*s == (char)c)
		{
			temp = (char *)s;
		}
		s++;
	}
	return (temp);
}
