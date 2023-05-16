/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbricot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/06 15:26:08 by gbricot           #+#    #+#             */
/*   Updated: 2023/05/16 17:05:06 by gbricot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_push_swap(t_stack *a, t_stack *b)
{
	if (ft_is_sort(a) == 0)
		ft_add_index(a);
	else
		return ;
	ft_split_stack(a, b);
	ft_sort_stacks(a, b);
	while (b->len > 0)
	{
		ft_pa(a, b);
		ft_printf("pa\n");
	}
	ft_free_all(a, b);
}
