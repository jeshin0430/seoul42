/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iterative_power.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeshin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/05 21:10:38 by jeshin            #+#    #+#             */
/*   Updated: 2020/02/05 22:48:40 by jeshin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_iterative_power(int nb, int power)
{
	int i;
	int res;

	i = 0;
	res = 1;
	if (power == 0)
		return (1);
	if (power < 0)
		return (0);
	while (i < power)
	{
		res *= nb;
		i++;
	}
	return (res);
}
