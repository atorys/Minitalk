/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atory <atory@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/26 18:42:42 by atory             #+#    #+#             */
/*   Updated: 2021/04/27 23:41:50 by atory            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*nextadr;

	nextadr = *lst;
	while (*lst)
	{
		nextadr = *lst;
		del((*lst)->content);
		*lst = (*lst)->next;
		free(nextadr);
	}
}
