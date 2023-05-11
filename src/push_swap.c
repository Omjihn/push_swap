/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbricot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/06 15:26:08 by gbricot           #+#    #+#             */
/*   Updated: 2023/05/11 19:10:15 by gbricot          ###   ########.fr       */
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
		if (a->list[i]->nb > a->list[i + 1]->nb)
			return (0);
		i++;
	}
	return (1);
}



void	ft_split_stack(t_stack *a, t_stack *b)
{
	int	index;

	index = 1;
	while (index <= (a->len + b->len) / 2)
	{
		if (a->list[0]->index > (a->len + b->len) / 2)
		{
			ft_pb(a, b);
			index++;
			ft_printf("pb\n");
		}
		else if (a->list[1]->index > (a->len + b->len) / 2)
		{
			ft_sa(a);
			ft_pb(a, b);
			index++;
			ft_printf("sa\npb\n");
		}
		else if (a->list[a->len - 1]->index > (a->len + b->len) / 2)
		{
			ft_rra(a);
			ft_pb(a, b);			
			index++;
			ft_printf("rra\npb\n");
		}
		else
		{
			ft_ra(a);
			ft_printf("ra\n");
		}
	}
}

void	ft_push_swap(t_stack *a, t_stack *b)
{
	int	i;

	if (ft_is_sort(a, b) == 0)
		ft_add_index(a);
	else
		return ;
	i = 0;
	while (i < a->len)
	{
		ft_printf("nb: %d - index: %d\n", a->list[i]->nb, a->list[i]->index);
		i++;
	}
	ft_split_stack(a, b);
	i = 0;
	ft_printf("Stack a:\n");
	while (i < a->len)
        {
                ft_printf("nb: %d - index: %d\n", a->list[i]->nb, a->list[i]->index);
                i++;
        }
	i = 0;
	ft_printf("Stack b:\n");
	while (i < b->len)
        {
                ft_printf("nb: %d - index: %d\n", b->list[i]->nb, b->list[i]->index);
                i++;
        }
	while(ft_is_sort(a, b) == 0)
	{
		ft_free_all(a, b);
	}
}
	//while (ft_is_sort(a, b) == 0)


/*
 *
 * ___________ Works for 3 numbers only |D  |\
					   B| |
					|D  |/
while (ft_is_sort(a, b) == 0)
        {
                if (a->list[0] > a->list[1])
                {
                        ft_sa(a);
                        ft_printf("sa\n");
                }
                else if (a->list[a->len - 1] < a->list[a->len - 2])
                {
                        ft_rra(a);
                        ft_printf("ra\n");
                }
        }
*/
/*
//_________________________________TEST_______________________________\\
	
	int	i;
	ft_printf("Is sort ? %d\n", ft_is_sort(a, b));
	ft_printf("______init______\n");
	i = 0; //debug
        while (i < a->len + b->len) //debug
        {
		ft_printf("%d		%d\n%d		%d\n\n", a->list[i]->nb, b->list[i]->nb, a->list[i]->index, b->list[i]->index);
                i++; //debug
        }
	ft_printf("\na		b\n-		-\n");
	ft_sa(a);
	ft_printf("_______sa_______\n");
	i = 0; //debug
        while (i < a->len + b->len) //debug
        {
		ft_printf("%d		%d\n%d		%d\n\n", a->list[i]->nb, b->list[i]->nb, a->list[i]->index, b->list[i]->index);
                i++; //debug
        }
	ft_printf("\na		b\n-		-\n");
	ft_rrr(a, b);
	ft_printf("_______rrr_______\n");
	i = 0; //debug
        while (i < a->len + b->len) //debug
        {
		ft_printf("%d		%d\n%d		%d\n\n", a->list[i]->nb, b->list[i]->nb, a->list[i]->index, b->list[i]->index);
                i++; //debug
        }
	ft_printf("\na		b\n-		-\n");
	ft_ss(a, b);
        ft_printf("_______ss_______\n");
        i = 0; //debug
        while (i < a->len + b->len) //debug
        {
                ft_printf("%d		%d\n%d		%d\n\n", a->list[i]->nb, b->list[i]->nb, a->list[i]->index, b->list[i]->index); //debug
                i++; //debug
        }
        ft_printf("\na		b\n-		-\n");
}
*/
