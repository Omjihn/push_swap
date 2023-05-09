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
	int	i;
	int	j;
	int	temp[2];

	j = 0;
	while (j < a->len)
	{
		i = 0;
		temp[0] = a->list[0].nb;
		temp[1] = 1;
		while (i < a->len - 1)
		{
			if (temp[0] < a->list[i].nb && a->list[i].index == 0)
			{
				temp[0] = a->list[i].nb;
				temp[1] = i + 1;
			}
			i++;
		}
		j++;
		a->list[temp[1]].index = j;
	}
}
