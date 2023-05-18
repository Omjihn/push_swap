/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbricot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/06 15:26:08 by gbricot           #+#    #+#             */
/*   Updated: 2023/05/18 14:19:35 by gbricot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_push_swap(t_stack *a, t_stack *b)
{
	if (ft_is_sort(a) == 0)
		ft_add_index(a);
	else
		return ;
	if (a->list[0]->index == 2 && a->list[1]->index == 1)
	{
		ft_sa(a);
		ft_printf("sa\n");
		ft_free_all(a, b);
	}
	ft_split_stack(a, b);
	ft_sort_stacks(a, b);
	ft_free_all(a, b);
}
