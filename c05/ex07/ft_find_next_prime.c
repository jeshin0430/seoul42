/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_find_next_prime.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeshin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/06 16:39:39 by jeshin            #+#    #+#             */
/*   Updated: 2020/02/06 16:59:23 by jeshin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_sqrt(int nb)
{
	long long res;

	if (nb < 1)
		return (-1);
	res = 2;
	while (res * res <= (long long)nb)
	{
		if (res * res == (long long)nb)
			return (-1);
		res++;
	}
	return (res + 1);
}

int		ft_is_prime(int nb)
{
	long long sqrt;
	long long i;

	if (nb <= 1)
		return (0);
	if (nb <= 3)
		return (1);
	sqrt = ft_sqrt(nb);
	if (sqrt < 0)
		return (0);
	i = 2;
	while (i <= sqrt)
	{
		if (nb % i == 0)
			return (0);
		i++;
	}
	return (1);
}

int		ft_find_next_prime(int nb)
{
	long long i;

	if (nb < 2)
		return (2);
	i = nb;
	while (1)
	{
		if (ft_is_prime(i))
			return (i);
		i++;
	}
}
