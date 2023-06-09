/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbricot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/04 13:24:49 by gbricot           #+#    #+#             */
/*   Updated: 2023/05/31 16:04:54 by gbricot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include "../printf/ft_printf.h"

# define BUFFER_SIZE 256
# define MSG_NB "Error please enter only numbers\n"
# define MSG_CHK "Error wrong operator\n"
# define MSG_OF "Error wrong input check if your integers does not overflow\n"

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
int		ft_atoi(const char *nptr, t_stack *a);

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
int		ft_add_one(t_stack *a, int index);
int		ft_pre_atoi(const char *nptr, t_stack *a);
int		ft_split_stack_2(t_stack *a, t_stack *b, int index, int i);

void	ft_check(t_stack *a);
void	ft_no_numbers(int ac, char **av);
void	ft_free_all(t_stack *a, t_stack *b);
void	ft_add_index(t_stack *a);
void	ft_init_list(t_stack *stack, int len);
void	ft_push_swap(t_stack *a, t_stack *b);
void	ft_sort_three(t_stack *a);
void	ft_sort_four(t_stack *a, t_stack *b);
void	ft_sort_five(t_stack *a, t_stack *b);
void	ft_radix(t_stack *a, t_stack *b);

t_stack	*ft_split_int(char *av);
t_stack	*ft_put_in_tab(int ac, char **av);
t_stack	*ft_init_b(int len);

/*		 CHECKER 		*/
void	ft_exec(t_stack *a, t_stack *b, char *actions);
void	ft_error_checker(t_stack *a, t_stack *b, char *actions);

char	*ft_read_inputs(t_stack *a);

#endif
