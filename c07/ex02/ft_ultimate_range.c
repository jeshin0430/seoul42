/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ultimate_range.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeshin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/09 17:11:52 by jeshin            #+#    #+#             */
/*   Updated: 2020/02/10 19:24:10 by jeshin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int		ft_ultimate_range(int **range, int min, int max)
{
	int		i;
	int		len;
	int		*str;

	i = 0;
	len = max - min;
	if (min >= max)
		return (0);
	if (!(str = (int*)malloc(sizeof(int) * len)))
		return (-1);
	while (i < len)
	{
		str[i] = min + i;
		i++;
	}
	*range = str;
	return (i);
}
