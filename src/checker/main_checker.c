/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_checker.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbricot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/14 11:46:28 by gbricot           #+#    #+#             */
/*   Updated: 2023/05/30 20:41:02 by gbricot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	main(int ac, char **av)
{
	t_stack	*a;
	t_stack	*b;
	char	*actions;

	if (ac == 1)
		exit(42);
	ft_no_numbers(ac, av);
	a = ft_put_in_tab(ac, av);
	ft_check(a);
	b = ft_init_b(a->len);
	actions = ft_read_inputs(a);
	ft_exec(a, b, actions);
	if (ft_is_sort(a) == 1)
		ft_printf("OK\n");
	else
		ft_printf("KO\n");
	free(actions);
	ft_free_all(a, b);
	return (0);
}
