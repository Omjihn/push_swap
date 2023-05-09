/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_add_index.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbricot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/09 16:59:46 by gbricot           #+#    #+#             */
/*   Updated: 2023/05/09 17:55:07 by gbricot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_add_index(t_stack *a)
{
	int		i;
	int		j;
	int		tmp_i;
	t_nb	*temp;

	j = 0;
	while (j < a->len)
	{
		i = 0;
		while (a->list[i]->index != 0)
			i++;
		temp = a->list[i];
		while (i < a->len - 1)
		{
			if (temp->nb > a->list[i]->nb && a->list[i]->index == 0)
			{
				temp = a->list[i];
				tmp_i = i;
			}
			i++;
		}
		j++;
		a->list[tmp_i] = temp;
		a->list[tmp_i]->index = j;
	}
}
