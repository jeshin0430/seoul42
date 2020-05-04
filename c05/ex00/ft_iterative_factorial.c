/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iterative_factorial.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeshin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/05 18:04:30 by jeshin            #+#    #+#             */
/*   Updated: 2020/02/05 20:08:12 by jeshin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_iterative_factorial(int nb)
{
	int res;
	int i;

	res = 1;
	i = nb;
	while (i > 0)
	{
		res *= i;
		i--;
	}
	if (nb > 0)
		return (res);
	if (nb == 0)
		return (1);
	else
		return (0);
}
