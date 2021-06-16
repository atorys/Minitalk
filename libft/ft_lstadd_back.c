/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atory <atory@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/26 18:41:31 by atory             #+#    #+#             */
/*   Updated: 2021/05/02 00:03:17 by atory            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*flag;

	if (*lst == NULL)
	{
		*lst = new;
		return ;
	}
	flag = (*lst);
	while (flag->next != NULL)
		flag = flag->next;
	flag->next = new;
}
