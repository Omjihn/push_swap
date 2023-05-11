/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_all.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbricot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/06 15:34:16 by gbricot           #+#    #+#             */
/*   Updated: 2023/05/11 19:05:25 by gbricot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_free_all(t_stack *a, t_stack *b)
{
	int	i;

	i = 0;
	while (i < a->len)
	{
		free (a->list[i]);
		i++;
	}
	free(a->list);
	free (a);
	if (b)
	{
		free (b->list);
		free (b);
	}
	exit (42);
}
