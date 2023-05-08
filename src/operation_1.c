/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operation_1.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbricot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 16:53:08 by gbricot           #+#    #+#             */
/*   Updated: 2023/05/08 18:44:45 by gbricot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_sa(t_stack *a)
{
	int	temp;

	temp = a->list[0];
	a->list[0] = a->list[1];
	a->list[1] = temp;
}

void	ft_sb(t_stack *b)
{
	int	temp;

	temp = b->list[0];
	b->list[0] = b->list[1];
	b->list[1] = temp;
}

void	ft_ss(t_stack *a, t_stack *b)
{
	ft_sa(a);
	ft_sb(b);
}

void	ft_pa(t_stack *a, t_stack *b)
{
	int 	i;

	if (b->len == 0)
		return ;
	i = a->len;
	while (i > 0)
	{
		a->list[i - 1] = a->list[i];
		i--;
	}
	a->list[0] = b->list[0];
	i = b->len;
	while (i > 0)
	{
		b->list[i - 1] = b->list[i];
		i--;
	}
	b->len--;
	a->len++;
}

void	ft_pb(t_stack *a, t_stack *b)
{
	int	i;

	if (a->len == 0)
		return ;
	i = b->len;
	while (i > 0)
	{
		b->list[i - 1] = b->list[i];
		i--;
	}
	b->list[0] = a->list[0];
	i = b->len;
	while (i > 0)
	{
		a->list[i - 1] = a->list[i];
		i--;
	}
	a->len--;
	b->len++;
}
