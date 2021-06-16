/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atory <atory@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/21 23:59:44 by atory             #+#    #+#             */
/*   Updated: 2021/04/27 18:10:49 by atory            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char			*result;
	unsigned int	i;

	if (!s1 || !s2)
		return (NULL);
	i = 0;
	result = malloc(sizeof(int) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (result)
	{
		while (*s1)
		{
			result[i] = (char)*s1;
			s1++;
			i++;
		}
		while (*s2)
		{
			result[i] = (char)*s2;
			s2++;
			i++;
		}
		result[i] = '\0';
		return (result);
	}
	return (NULL);
}
