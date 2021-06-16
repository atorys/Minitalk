/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atory <atory@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/26 18:37:58 by atory             #+#    #+#             */
/*   Updated: 2021/04/27 18:37:10 by atory            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void *content)
{
	t_list	*newelem;

	newelem = NULL;
	newelem = malloc(sizeof(t_list));
	if (newelem)
	{
		newelem->content = content;
		newelem->next = NULL;
		return (newelem);
	}
	return (NULL);
}
