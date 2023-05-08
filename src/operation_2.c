/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operation_2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbricot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/08 18:02:18 by gbricot           #+#    #+#             */
/*   Updated: 2023/05/08 19:01:42 by gbricot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_ra(t_stack *a)
{
	int	i;
	int	temp;

	if (!a->len == 0)
		return ;
	temp = a->list[0];
	i = a->len - 1;
	while (i > 0)
	{
		a->list[i - 1] = a->list[i];
		i--;
	}
	a->list[a->len - 1] = temp;
}

void	ft_rb(t_stack *b)
{
	int     i;
	int     temp;

	if (!b->len == 0)
		return ;
	temp = b->list[0];
	i = b->len - 1;
	while (i > 0)
	{
		b->list[i - 1] = b->list[i];
		i--;
	}
	b->list[b->len - 1] = temp;
}

void	ft_rr(t_stack *a, t_stack *b)
{
	ft_ra(a);
	ft_rb(b);
}
