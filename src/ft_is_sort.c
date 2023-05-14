/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbricot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/14 15:51:44 by gbricot           #+#    #+#             */
/*   Updated: 2023/05/14 15:54:05 by gbricot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_is_sort(t_stack *stack)
{
	int	i;

	i = 0;
	while (i < stack->len - 1)
	{
		if (stack->list[i]->nb > stack->list[i + 1]->nb)
			return (0);
		i++;
	}
	return (1);
}

int	ft_is_sort_rev(t_stack *stack)
{
	int	i;

	i = 0;
	while (i < stack->len - 1)
	{
		if (stack->list[i]->nb < stack->list[i + 1]->nb)
			return (0);
		i++;
	}
	return (1);
}
