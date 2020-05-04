/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_non_printable.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeshin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/30 23:43:07 by jeshin            #+#    #+#             */
/*   Updated: 2020/01/31 00:05:54 by jeshin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char ch)
{
	write(1, &ch, 1);
}

void	ft_printhex(int a)
{
	unsigned char *hex;

	hex = "0123456789abcdef";
	if (a > 16)
	{
		ft_printhex(a / 10);
		ft_printhex(a % 10);
	}
	else
		ft_putchar(hex[a]);
}

void	ft_putstr_non_printable(char *str)
{
	while (*str != '\0')
	{
		if ((*str >= 0 && *str < 32) || *str >= 127)
		{
			ft_putchar('\\');
			if (*str > 0 && *str < 16)
				ft_putchar('0');
			ft_printhex((int)*str);
		}
		else
			ft_putchar(*str);
		str++;
		}
}

int	main()
{
	ft_putstr_non_printable("\n");
}
