/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_stacks.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbricot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/12 13:05:31 by gbricot           #+#    #+#             */
/*   Updated: 2023/05/17 18:30:28 by gbricot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	ft_sort_a_2(t_stack *a, t_stack *b, int index, int i)
{
	while (a->len > 0)
	{
		i = 0;
		while (a->list[i]->index != index)
			i++;
		if (i > a->len / 2)
		{
			while (a->list[0]->index != index)
			{	
				ft_rra(a);
				ft_printf("rra\n");
			}
		}
		else
		{
			while (a->list[0]->index != index)
			{
				ft_ra(a);
				ft_printf("ra\n");
			}
		}
		ft_pb(a, b);
		ft_printf("pb\n");
		index++;
	}
}

void	ft_sort_a(t_stack *a, t_stack *b)
{
	int	temp;
	int	index;

	temp = a->len;
	index = 1 + b->len;
	ft_sort_a_2(a, b, index, 0);
	while (temp > 0)
	{
		ft_pa(a, b);
		ft_printf("pa\n");
		temp--;
	}
}

void	ft_sort_b(t_stack *b, t_stack *a, int index, int i)
{
	while (b->len > 0)
	{
		i = 0;
		while (b->list[i]->index != index)
			i++;
		if (i > b->len / 2)
		{
			while (b->list[0]->index != index)
			{
				ft_rrb(b);
				ft_printf("rrb\n");
			}
		}
		else
		{
			while (b->list[0]->index != index)
			{
				ft_rb(b);
				ft_printf("rb\n");
			}
		}
		ft_pa(a, b);
		ft_printf("pa\n");
		index--;
	}
}

void	ft_sort_stacks(t_stack *a, t_stack *b)
{
	if (ft_is_sort(a) == 0)
		ft_sort_a(a, b);
	ft_sort_b(b, a, b->len, 0);
}
