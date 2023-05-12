/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split_stack.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbricot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/12 12:23:37 by gbricot           #+#    #+#             */
/*   Updated: 2023/05/12 13:03:16 by gbricot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_split_stack_2(t_stack *a, t_stack *b, int index, int i)
{
	if (a->list[0]->index <= (a->len + b->len) / 2 + i)
	{
		ft_pb(a, b);
		ft_printf("pb\n");
		return (index + 1);
	}
	else if (a->list[1]->index <= (a->len + b->len) / 2 + i)
	{
		ft_sa(a);
		ft_pb(a, b);
		ft_printf("sa\npb\n");
		return (index + 1);
	}
	else if (a->list[a->len - 1]->index <= (a->len + b->len) / 2 + i)
	{
		ft_rra(a);
		ft_pb(a, b);
		ft_printf("rra\npb\n");
		return (index + 1);
	}
	else
	{
		ft_ra(a);
		return (ft_printf("ra\n"), index);
	}
}

void	ft_split_stack(t_stack *a, t_stack *b)
{
	int	index;
	int	i;

	index = 1;
	i = 0;
	if (a->len & 1)
		i = 1;
	while (index <= (a->len + b->len) / 2 + i)
	{
		index = ft_split_stack_2(a, b, index, i);
	}
}
