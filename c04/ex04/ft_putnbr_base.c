/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeshin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/03 17:54:14 by jeshin            #+#    #+#             */
/*   Updated: 2020/02/05 17:59:14 by jeshin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

int		check_base(char *base)
{
	int i;
	int z;

	i = 0;
	z = 0;
	if (base[0] == '\0' || base[1] == '\0')
		return (0);
	while (base[i] != '\0')
	{
		z = i + 1;
		if (base[i] == '+' || base[i] == '-')
			return (0);
		if (base[i] < 32 || base[i] > 126)
			return (0);
		while (base[z] != '\0')
		{
			if (base[i] == base[z])
				return (0);
			z++;
		}
		i++;
	}
	return (1);
}

int		ft_strlen(char *str)
{
	if (*str)
		return (1 + ft_strlen(str + 1));
	return (0);
}

void	ft_putnbr_base(int nbr, char *base)
{
	int		s;
	int		nbrf[100];
	int		i;
	long	lnbr;

	lnbr = (long)nbr;
	i = 0;
	s = ft_strlen(base);
	if (check_base(base))
	{
		if (lnbr == 0)
			ft_putchar('0');
		if (lnbr < 0)
		{
			lnbr = -lnbr;
			ft_putchar('-');
		}
		while (lnbr)
		{
			nbrf[i++] = lnbr % s;
			lnbr = lnbr / s;
		}
		while (--i >= 0)
			ft_putchar(base[nbrf[i]]);
	}
}

int     main()
{
    ft_putnbr_base(1234, "0123456789");
}
