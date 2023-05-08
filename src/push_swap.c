/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbricot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/06 15:26:08 by gbricot           #+#    #+#             */
/*   Updated: 2023/05/08 19:25:44 by gbricot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_is_sort(t_stack *a, t_stack *b)
{
	int	i;

	if (b->len != 0)
		return (0);
	i = 0;
	while (i < a->len - 1)
	{
		if (a->list[i] > a->list[i + 1])
			return (0);
		i++;
	}
	return (1);
}



void	ft_push_swap(t_stack *a, t_stack *b)
{
	int	i;
	
	ft_printf("Is sort ? %d\n", ft_is_sort(a, b));
	ft_printf("______init______\n");
	i = 0; //debug
        while (i < a->len) //debug
        {
		ft_printf("%d		%d\n", a->list[i], b->list[i]);
                i++; //debug
        }
	ft_printf("\na		b\n-		-\n");
	ft_sa(a);
	ft_printf("_______sa_______\n");
	i = 0; //debug
        while (i < a->len) //debug
        {
                ft_printf("%d		%d\n", a->list[i], b->list[i]); //debug
                i++; //debug
        }
	ft_printf("\na		b\n-		-\n");
	ft_pb(a, b);
	ft_printf("_______pb_______\n");
	i = 0; //debug
        while (i < a->len + b->len) //debug
        {
                ft_printf("%d		%d\n", a->list[i], b->list[i]); //debug
                i++; //debug
        }
	ft_printf("\na		b\n-		-\n");
}
