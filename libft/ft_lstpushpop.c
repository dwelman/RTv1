/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstpushpop.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daviwel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/21 08:00:23 by daviwel           #+#    #+#             */
/*   Updated: 2016/06/23 11:48:54 by daviwel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstpushpop(t_list **a, t_list **b)
{
	t_list	*temp;

	temp = ft_lstpop(a);
	if (temp != NULL)
		ft_lstpush(b, temp);
}
