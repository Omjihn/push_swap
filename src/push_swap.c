/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbricot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/06 15:26:08 by gbricot           #+#    #+#             */
/*   Updated: 2023/05/31 16:03:16 by gbricot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	ft_sort_three_next(t_stack *a)
{
	if (a->list[0]->index == 3 && a->list[1]->index == 1
		&& a->list[2]->index == 2)
	{
		ft_ra(a);
		ft_printf("ra\n");
	}
	else if (a->list[0]->index == 3 && a->list[1]->index == 2
		&& a->list[2]->index == 1)
	{
		ft_sa(a);
		ft_rra(a);
		ft_printf("sa\nrra\n");
	}
}

void	ft_sort_three(t_stack *a)
{
	if (a->list[0]->index == 1 && a->list[1]->index == 3
		&& a->list[2]->index == 2)
	{
		ft_sa(a);
		ft_ra(a);
		ft_printf("sa\nra\n");
	}
	else if (a->list[0]->index == 2 && a->list[1]->index == 1
		&& a->list[2]->index == 3)
	{
		ft_sa(a);
		ft_printf("sa\n");
	}
	else if (a->list[0]->index == 2 && a->list[1]->index == 3
		&& a->list[2]->index == 1)
	{
		ft_rra(a);
		ft_printf("rra\n");
	}
	else
		ft_sort_three_next(a);
}

void	ft_push_swap(t_stack *a, t_stack *b)
{
	if (ft_is_sort(a) == 0)
		ft_add_index(a);
	else
		return ;
	if (a->list[0]->index == 2 && a->list[1]->index == 1 && a->len == 2)
	{
		ft_sa(a);
		ft_printf("sa\n");
	}
	else if (a->len == 3)
		ft_sort_three(a);
	else if (a->len == 4)
		ft_sort_four(a, b);
	else if (a->len == 5)
		ft_sort_five(a, b);
	else
		ft_radix(a, b);
	ft_free_all(a, b);
}
