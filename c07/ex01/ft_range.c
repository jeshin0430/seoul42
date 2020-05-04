/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeshin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/09 16:37:07 by jeshin            #+#    #+#             */
/*   Updated: 2020/02/09 22:50:28 by jeshin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int		*ft_range(int min, int max)
{
	int		i;
	int		*str;

	if (min >= max)
		return (NULL);
	str = (int*)malloc(sizeof(int) * (max - min));
	i = 0;
	while (min < max)
	{
		str[i] = min;
		i++;
		min++;
	}
	return (str);
}
