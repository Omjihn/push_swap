/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_add_index.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbricot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/09 16:59:46 by gbricot           #+#    #+#             */
/*   Updated: 2023/05/16 16:50:26 by gbricot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_add_one(t_stack *a, int index)
{
	int		i;
	t_nb	*res;

	i = 0;
	while (a->list[i]->index > 0)
		i++;
	res = a->list[i];
	while (i < a->len)
	{
		if (res->nb > a->list[i]->nb && a->list[i]->index == 0)
			res = a->list[i];
		i++;
	}
	res->index = index;
	return (index + 1);
}

void	ft_add_index(t_stack *a)
{
	int	i;
	int	index;

	i = 0;
	index = 1;
	while (i < a->len)
	{
		index = ft_add_one(a, index);
		i++;
	}
}
