/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operation.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbricot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 16:53:08 by gbricot           #+#    #+#             */
/*   Updated: 2023/05/03 17:26:24 by gbricot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_sa(int *a)
{
	int	temp;

	temp = a[0];
	a[0] = a[1];
	a[1] = temp;
}

void	ft_sb(int *b)
{
	int	temp;

	temp = b[0];
	b[0] = b[1];
	b[1] = temp;
}

void	ft_ss(int *a, int *b)
{
	ft_sa(a);
	ft_sb(b);
}

void	ft_pa(int *a, int *b)
{
	int 	i;
	int	temp;

	if (!*b)
		return ;

		
