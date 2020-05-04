/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_recursive_factorial.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeshin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/05 20:10:42 by jeshin            #+#    #+#             */
/*   Updated: 2020/02/05 21:10:25 by jeshin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_recursive_factorial(int nb)
{
	if (nb > 0)
	{
		if (nb == 1)
			return (1);
		return (nb * ft_recursive_factorial(nb - 1));
	}
	if (nb == 0)
		return (1);
	return (0);
}
