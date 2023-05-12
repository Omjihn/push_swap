/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_stacks.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbricot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/12 13:05:31 by gbricot           #+#    #+#             */
/*   Updated: 2023/05/12 16:24:42 by gbricot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_sort_a(t_stack *a)
{
//	int	i;

	while (ft_is_sort(a) == 0)
	{
		if (a->list[0]->index > a->list[1]->index)
		{
			ft_sa(a);
			ft_printf("sa\n");
		}
//		else if (a->list[1]->index > a->list[2]->index)
//		{
//			ft_ra(a);
//			ft_sa(a);
//			ft_printf("ra\nsa\n");
//		}
		else if (a->list[a->len - 1]->index > a->list[0]->index)
		{
			ft_rra(a);
			ft_sa(a);
			ft_ra(a);
			ft_printf("rra\nsa\nra\n");
		}
		else
		{
			ft_ra(a);
			ft_printf("ra\n");
		}
		/*sleep(1);
		i = 0;
        	ft_printf("Stack a:\n");
	        while (i < a->len)
        	{
                	ft_printf("nb: %d - index: %d\n", a->list[i]->nb, a->list[i]->index);
		i++;
        	}*/
	}
}

void	ft_sort_b(t_stack *b)
{
	while (ft_is_sort_rev(b) == 0)
	{
		if (b->list[0]->index < b->list[1]->index)
		{
			ft_sb(b);
			ft_printf("sb\n");
		}
		else if (b->list[b->len - 1]->index < b->list[0]->index)
		{
			ft_rrb(b);
			ft_sb(b);
			ft_printf("rrb\nsb\n");
		}
		else
		{
			ft_rrb(b);
			ft_printf("rrb\n");
		}
	}
}

void	ft_sort_stacks(t_stack *a, t_stack *b)
{
//	if (ft_is_sort(a) == 0 && ft_is_sort(b) == 0)
//		ft_sort_both(a, b);

	if (ft_is_sort(a) == 0)
		ft_sort_a(a);
	if (ft_is_sort_rev(b) == 0)
		ft_sort_b(b);
}
