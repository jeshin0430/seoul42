/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_prime.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeshin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/06 14:43:05 by jeshin            #+#    #+#             */
/*   Updated: 2020/02/06 16:39:11 by jeshin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_sqrt(int nb)
{
	long long res;

	if (nb < 0)
		return (0);
	res = 1;
	while (res * res <= (long long)nb)
	{
		if (res * res == (long long)nb)
			return (res);
		res++;
	}
	return (res);
}

int		ft_is_prime(int nb)
{
	int i;

	i = 1;
	if (nb <= 1)
		return (0);
	if (nb == 2)
		return (1);
	while (++i <= ft_sqrt(nb))
	{
		if (nb % i == 0)
			return (0);
	}
	return (1);
}
