/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_radix.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbricot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/26 16:01:41 by gbricot           #+#    #+#             */
/*   Updated: 2023/05/31 17:01:45 by gbricot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	ft_nb_bit(t_stack *a, unsigned long int bit)
{
	int	total;
	int	i;

	i = 0;
	total = 0;
	while (i < a->len)
	{
		if (!(a->list[i]->index & bit))
			total++;
		i++;
	}
	return (total);
}

static void	ft_send_resend(t_stack *a, t_stack *b, unsigned long int bit,
		int max_nb)
{
	int	i;

	i = 0;
	while (i < max_nb)
	{
		if (!(a->list[0]->index & bit))
		{
			ft_pb(a, b);
			ft_printf("pb\n");
		}
		else
		{
			ft_ra(a);
			ft_printf("ra\n");
		}
		i++;
	}
	while (b->len > 0)
	{
		ft_pa(a, b);
		ft_printf("pa\n");
	}
}

void	ft_radix(t_stack *a, t_stack *b)
{
	unsigned long int	bit;

	bit = 1;
	while (ft_is_sort(a) == 0)
	{
		if (ft_nb_bit(a, bit) > 0)
			ft_send_resend(a, b, bit, a->len);
		bit *= 2;
	}
}
