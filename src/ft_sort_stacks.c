/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_stacks.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbricot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/12 13:05:31 by gbricot           #+#    #+#             */
/*   Updated: 2023/05/16 17:06:53 by gbricot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_sort_a(t_stack *a)
{
	int	i;
	int	j;

	while (ft_is_sort(a) == 0)
	{
		i = 0;
                while (i < a->len - 2)
                {
                        if (a->list[i]->index == 1 &&
                                        a->list[i + 1]->index == a->len)
                        {
                                if (i > ((a->len - 1) / 2))
                                {
                                        while (i < a->len)
                                        {
                                                ft_rra(a);
                                                ft_printf("rra\n");
                                                i++;
                                        }
                                }
                                else
                                {
                                        while (i > 0)
                                        {
                                                ft_ra(a);
                                                ft_printf("ra\n");
                                                i--;
                                        }
                                }
                                if (ft_is_sort(a) == 1)
                                        return ;
                        }
                        i++;
                }
                i = 0;
                while (a->list[i]->index < a->list[i + 1]->index && i < a->len - 1)
                        i++;
                j = i;
                while (j > 0)
                {
                        ft_ra(a);
                        ft_printf("ra\n");
                        j--;
                }
                ft_sa(a);
                ft_printf("sa\n");
                while (i > 0)
                {
                        ft_rra(a);
                        ft_printf("rra\n");
                        i--;
                }
	}
}

void	ft_sort_b(t_stack *b)
{
	int	i;
	int	j;

	while (ft_is_sort_rev(b) == 0)
	{
		i = 0;
		while (i < b->len - 2)
		{
			if (b->list[i]->index == 1 &&
					b->list[i + 1]->index == b->len)
			{
				if (i > ((b->len - 1) / 2))
				{
					while (i < b->len)
					{
						ft_rrb(b);
						ft_printf("rrb\n");
						i++;
					}
				}
				else
				{
					while (i > 0)
					{
						ft_rb(b);
						ft_printf("rb\n");
						i--;
					}
				}
				if (ft_is_sort_rev(b) == 1)
					return ;
			}
			i++;
		}
		i = 0;
		while (b->list[i]->index > b->list[i + 1]->index && i < b->len - 1)
			i++;
		j = i;
		while (j > 0)
		{
			ft_rb(b);
			ft_printf("rb\n");
			j--;
		}
		ft_sb(b);
		ft_printf("sb\n");
		while (i > 0)
		{
			ft_rrb(b);
			ft_printf("rrb\n");
			i--;
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
