/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeshin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/01 22:59:46 by jeshin            #+#    #+#             */
/*   Updated: 2020/02/12 23:13:28 by jeshin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strstr(char *str, char *to_find)
{
	int index;
	int index2;

	index = 0;
	index2 = 0;
	while (*(to_find + index))
		index++;
	if (index == 0)
		return (str);
	while (*str)
	{
		if (*str == *to_find)
		{
			while (index2 < index)
			{
				if (*(str + index2) != *(to_find + index2))
					break ;
				index2++;
			}
			if (index2 == index)
				return (str);
		}
		str++;
	}
	return (0);
}
