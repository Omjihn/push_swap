/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_checker.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbricot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/14 11:46:28 by gbricot           #+#    #+#             */
/*   Updated: 2023/05/17 13:50:25 by gbricot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static	void	ft_free_actions(char **actions)
{
	int	i;

	i = 0;
	while (actions[i])
	{
		free (actions[i]);
		i++;
	}
	free (actions);
}

int	main(int ac, char **av)
{
	t_stack	*a;
	t_stack	*b;
	char	**actions;

	if (ac == 1)
		exit(42);
	ft_no_numbers(ac, av);
	a = ft_put_in_tab(ac, av);
	ft_check(a);
	b = ft_init_b(a->len);
	actions = ft_read_inputs();
	ft_exec(a, b, actions);
	if (ft_is_sort(a) == 1)
		ft_printf("OK\n");
	else
		ft_printf("KO\n");
	ft_free_actions(actions);
	ft_free_all(a, b);
	return (0);
}
