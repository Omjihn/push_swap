/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operation_3.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbricot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/08 18:49:46 by gbricot           #+#    #+#             */
/*   Updated: 2023/05/09 19:21:09 by gbricot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_rra(t_stack *a)
{
	int	i;
	int	temp;

	if (a->len == 0)
		return ;
	i = a->len - 1;
	temp = a->list[a->len - 1].nb;
	while (i > 0)
	{
		a->list[i].nb = a->list[i - 1].nb;
		i--;
	}
	a->list[0].nb = temp;
}

void	ft_rrb(t_stack *b)
{
        int     i;
        int     temp;

	if (b->len == 0)
		return ;
	i = b->len - 1;
	temp = b->list[b->len - 1].nb;
	while (i > 0)
	{
		b->list[i].nb = b->list[i - 1].nb;
		i--;
	}
	b->list[0].nb = temp;
}

void	ft_rrr(t_stack *a, t_stack *b)
{
	ft_rra(a);
	ft_rrb(b);
}
