/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operation_2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbricot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/08 18:02:18 by gbricot           #+#    #+#             */
/*   Updated: 2023/05/16 16:47:13 by gbricot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_ra(t_stack *a)
{
	int		i;
	t_nb	*temp;

	if (a->len == 0)
		return ;
	temp = a->list[0];
	i = 0;
	while (i < a->len - 1)
	{
		a->list[i] = a->list[i + 1];
		i++;
	}
	a->list[a->len - 1] = temp;
}

void	ft_rb(t_stack *b)
{
	int		i;
	t_nb	*temp;

	if (b->len == 0)
		return ;
	temp = b->list[0];
	i = 0;
	while (i < b->len - 1)
	{
		b->list[i] = b->list[i + 1];
		i++;
	}
	b->list[b->len - 1] = temp;
}

void	ft_rr(t_stack *a, t_stack *b)
{
	ft_ra(a);
	ft_rb(b);
}
