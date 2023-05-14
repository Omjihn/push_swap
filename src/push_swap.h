/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbricot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/04 13:24:49 by gbricot           #+#    #+#             */
/*   Updated: 2023/05/14 15:44:53 by gbricot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include "../printf/ft_printf.h"

# define MSG_NB "Error please enter only numbers\n"
# define MSG_CHK "Error wrong input '%s' is not an operator\n"

typedef struct s_nb
{
	int	index;
	int	nb;
}			t_nb;

typedef struct s_stack
{
	int		len;
	t_nb	**list;
}			t_stack;

/*		UTILITIES		*/
int		ft_atoi(const char *nptr);

void	*ft_memcpy(void *dest, const void *src, size_t n);
void	*ft_calloc(size_t nmemb, size_t size);

char	**ft_split(char const *s);

/*		OPERATORS		*/
void	ft_sa(t_stack *a);
void	ft_sb(t_stack *b);
void	ft_ss(t_stack *a, t_stack *b);
void	ft_pa(t_stack *a, t_stack *b);
void	ft_pb(t_stack *a, t_stack *b);
void	ft_ra(t_stack *a);
void	ft_rb(t_stack *b);
void	ft_rr(t_stack *a, t_stack *b);
void	ft_rra(t_stack *a);
void	ft_rrb(t_stack *b);
void	ft_rrr(t_stack *a, t_stack *b);

/*		PUSH_SWAP		*/
int		ft_is_sort(t_stack *stack);
int		ft_is_sort_rev(t_stack *stack);
int		ft_add_one(t_stack *a, int index);
int		ft_split_stack_2(t_stack *a, t_stack *b, int index, int i);

void	ft_check(t_stack *a);
void	ft_no_numbers(int ac, char **av);
void	ft_free_all(t_stack *a, t_stack *b);
void	ft_add_index(t_stack *a);
void	ft_init_list(t_stack *stack, int len);
void	ft_push_swap(t_stack *a, t_stack *b);
void	ft_split_stack(t_stack *a, t_stack *b);
void	ft_sort_stacks(t_stack *a, t_stack *b);
void	ft_sort_a(t_stack *a);
void	ft_sort_b(t_stack *b);

t_stack	*ft_split_int(char *av);
t_stack	*ft_put_in_tab(int ac, char **av);
t_stack	*ft_init_b(int len);

/*		 CHECKER 		*/
void	ft_exec(t_stack *a, t_stack *b, char **actions);
void	ft_error_checker(t_stack *a, t_stack *b, char **actions, int i);

char	**ft_read_inputs(void);


#endif
