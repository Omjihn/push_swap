/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbricot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 16:40:50 by gbricot           #+#    #+#             */
/*   Updated: 2023/05/13 15:58:20 by gbricot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int ac, char **av)
{
	t_stack	*a;
	t_stack	*b;

	if (ac == 1)
		exit (42);
	ft_no_numbers(ac, av);
	a = ft_put_in_tab(ac ,av);
	ft_check(a);
	b = ft_init_b(a->len);
	ft_push_swap(a, b);
	ft_free_all(a, b);
	return (0);
}
