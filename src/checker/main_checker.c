
#include "../push_swap.h"

int	main(int ac, char **av)
{
	t_stack	*a;
	t_stack	*b;
	char	**actions;

	if (ac == 1)
		exit(42);
	ft_no_numbers(ac, av);
	a = ft_put_in_tab(av, av);
	ft_check(a);
	b = ft_init_b(a->len);
	actions = ft_read_inputs();
	ft_checker(a, b, actions);
	ft_free_all(a, b);
	return (0);
}
