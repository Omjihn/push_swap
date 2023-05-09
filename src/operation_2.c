/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operation_2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbricot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/08 18:02:18 by gbricot           #+#    #+#             */
/*   Updated: 2023/05/09 19:21:50 by gbricot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_ra(t_stack *a)
{
	int	i;
	int	temp[2];

	if (a->len == 0)
		return ;
	temp[0] = a->list[0].nb;
	temp[1] = a->list[0].index;
	i = 0;
	while (i < a->len - 1)
	{
		a->list[i].nb = a->list[i + 1].nb;
		a->list[i].index = a->list[i + 1].index;
		i++;
	}
	a->list[a->len - 1].nb = temp[0];
	a->list[a->len - 1].index = temp[1];
}

void	ft_rb(t_stack *b)
{
	int     i;
	int     temp;

	if (b->len == 0)
		return ;
	temp = b->list[0].nb;
	i = 0;
	while (i < b->len - 1)
	{
		b->list[i].nb = b->list[i + 1].nb;
		i++;
	}
	b->list[b->len - 1].nb = temp;
}

void	ft_rr(t_stack *a, t_stack *b)
{
	ft_ra(a);
	ft_rb(b);
}
