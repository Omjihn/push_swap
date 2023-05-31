/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_stacks.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbricot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/12 13:05:31 by gbricot           #+#    #+#             */
/*   Updated: 2023/05/31 16:59:32 by gbricot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	ft_sort_three_of_five_next(t_stack *a)
{
	if (a->list[0]->index == 5 && a->list[1]->index == 3
		&& a->list[2]->index == 4)
	{
		ft_ra(a);
		ft_printf("ra\n");
	}
	else if (a->list[0]->index == 5 && a->list[1]->index == 4
		&& a->list[2]->index == 3)
	{
		ft_sa(a);
		ft_rra(a);
		ft_printf("sa\nrra\n");
	}
}

static void	ft_sort_three_of_five(t_stack *a)
{
	if (a->list[0]->index == 3 && a->list[1]->index == 5
		&& a->list[2]->index == 4)
	{
		ft_sa(a);
		ft_ra(a);
		ft_printf("sa\nra\n");
	}
	else if (a->list[0]->index == 4 && a->list[1]->index == 3
		&& a->list[2]->index == 5)
	{
		ft_sa(a);
		ft_printf("sa\n");
	}
	else if (a->list[0]->index == 4 && a->list[1]->index == 5
		&& a->list[2]->index == 3)
	{
		ft_rra(a);
		ft_printf("rra\n");
	}
	else
		ft_sort_three_of_five_next(a);
}

static void	ft_sort_and_send_b(t_stack *a, t_stack *b)
{
	if (b->list[0]->index == 1)
	{
		ft_sb(b);
		ft_printf("sb\n");
	}
	while (b->len > 0)
	{
		ft_pa(a, b);
		ft_printf("pa\n");
	}
}

void	ft_sort_four(t_stack *a, t_stack *b)
{
	while (a->len > 2)
	{
		if (a->list[0]->index <= 2)
		{
			ft_pb(a, b);
			ft_printf("pb\n");
		}
		else
		{
			ft_ra(a);
			ft_printf("ra\n");
		}
	}
	if (a->list[0]->index == 4)
	{
		ft_sa(a);
		ft_printf("sa\n");
	}
	ft_sort_and_send_b(a, b);
}

void	ft_sort_five(t_stack *a, t_stack *b)
{
	while (a->len > 3)
	{
		if (a->list[0]->index <= 2)
		{
			ft_pb(a, b);
			ft_printf("pb\n");
		}
		else
		{
			ft_ra(a);
			ft_printf("ra\n");
		}
	}
	ft_sort_three_of_five(a);
	ft_sort_and_send_b(a, b);
}
