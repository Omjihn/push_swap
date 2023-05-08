/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operation_3.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbricot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/08 18:49:46 by gbricot           #+#    #+#             */
/*   Updated: 2023/05/08 18:58:20 by gbricot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_rra(t_stack *a)
{
	int	i;
	int	temp;

	if (a->len == 0)
		return ;
	i = 0;
	temp = a->list[a->len - 1];
	while (i <= a->len - 1)
	{
		a->list[i + 1] = a->list[i];
		i++;
	}
	a->list[0] = temp;
}

void	ft_rrb(t_stack *b)
{
        int     i;
        int     temp;

	if (b->len == 0)
		return ;
	i = 0;
	temp = b->list[b->len - 1];
	while (i <= b->len - 1)
	{
		b->list[i + 1] = b->list[i];
		i++;
	}
	b->list[0] = temp;
}

void	ft_rrr(t_stack *a, t_stack *b)
{
	ft_rra(a);
	ft_rrb(b);
}
