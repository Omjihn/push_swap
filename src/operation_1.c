/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operation_1.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbricot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 16:53:08 by gbricot           #+#    #+#             */
/*   Updated: 2023/05/09 19:23:26 by gbricot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_sa(t_stack *a)
{
	int	temp;

	if (a->len == 1)
		return ;
	temp = a->list[0].nb;
	a->list[0].nb = a->list[1].nb;
	a->list[1].nb = temp;
	temp = a->list[0].index;
	a->list[0].index = a->list[1].index;
	a->list[1].index = temp;
}

void	ft_sb(t_stack *b)
{
	int	temp;

	if (b->len == 1)
		return ;
	temp = b->list[0].nb;
	b->list[0].nb = b->list[1].nb;
	b->list[1].nb = temp;
	temp = b->list[0].index;
	b->list[0].index = b->list[1].index;
	b->list[1].index = temp;
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
	i = a->len - 1;
	while (i >= 0)
	{
		a->list[i + 1].nb = a->list[i].nb;
		a->list[i + 1].index = a->list[i].index;
		i--;
	}
	a->list[0].nb = b->list[0].nb;
	a->list[0].index = b->list[0].index;
	i = 0;
	while (i < b->len - 1)
	{
		b->list[i].nb = b->list[i + 1].nb;
		b->list[i].index = b->list[i + 1].index;
		i++;
	}
	b->list[b->len - 1].nb = 0;
	b->list[b->len - 1].index = 0;
	b->len--;
	a->len++;
}

void	ft_pb(t_stack *a, t_stack *b)
{
	int	i;

	if (a->len == 0)
		return ;
	i = b->len - 1;
	while (i >= 0)
	{
		b->list[i + 1].nb = b->list[i].nb;
		b->list[i + 1].index = b->list[i].index;
		i--;
	}
	b->list[0].nb = a->list[0].nb;
	b->list[0].index = a->list[0].index;
	i = 0;
	while (i < a->len - 1)
	{
		a->list[i].nb = a->list[i + 1].nb;
		i++;
	}
	a->list[a->len - 1].nb = 0;
	a->list[a->len - 1].index = 0;
	a->len--;
	b->len++;
}
