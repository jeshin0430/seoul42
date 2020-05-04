/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeshin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/10 19:30:35 by jeshin            #+#    #+#             */
/*   Updated: 2020/02/10 19:31:05 by jeshin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char	*ft_convert_base(char *nbr, char *base_from, char *base_to);

int		find_size(int nb, int size_base)
{
	int	size_nb;

	size_nb = 1;
	if (nb < 0)
		size_nb++;
	while (nb / size_base)
	{
		size_nb++;
		nb = nb / size_base;
	}
	size_nb++;
	return (size_nb);
}

char	*itoa_base(long nb, char *base, int size_base)
{
	int		l;
	int		div;
	char	*nbr_base;

	nbr_base = (char *)malloc(find_size(nb, size_base) * sizeof(char));
	l = 0;
	if (nb < 0)
	{
		nbr_base[0] = '-';
		l++;
		nb = -nb;
	}
	div = 1;
	while (nb / div >= size_base)
		div *= size_base;
	while (div)
	{
		nbr_base[l] = base[nb / div];
		l++;
		nb = nb % div;
		div = div / size_base;
	}
	nbr_base[l] = '\0';
	return (nbr_base);
}
