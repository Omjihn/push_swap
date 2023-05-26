/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_radix.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbricot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/26 16:01:41 by gbricot           #+#    #+#             */
/*   Updated: 2023/05/26 17:09:53 by gbricot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_radix(t_stack *a, t_stack *b)
{
	int		j;
	long int	i;

	i = 1;
	while (b->len != 0 && ft_is_sort(a) == 0)
	{
		while (i <= 2147483648)
		{
			while ()
			if (a->list[j]->nb & i)
			{
				ft_pb(a, b);
				ft_printf("pb\n");
			}

