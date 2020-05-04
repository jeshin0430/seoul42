/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeshin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/05 16:36:56 by jeshin            #+#    #+#             */
/*   Updated: 2020/02/05 17:56:32 by jeshin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

unsigned int	get_strlen(char *str)
{
	int len;

	len = 0;
	while (*str)
	{
		len++;
		str++;
	}
	return (len);
}

int				ft_is_sign(char c, int *sign)
{
	if (c == '-')
	{
		*sign *= -1;
		return (1);
	}
	else if (c == '+')
		return (1);
	return (0);
}

int				check_base(char *base, int base_len)
{
	int i;
	int j;

	if (base_len == 0 || base_len == 1)
		return (0);
	i = 0;
	while (i < base_len - 1)
	{
		j = i + 1;
		while (j < base_len)
		{
			if (base[i] == base[j])
				return (0);
			j++;
		}
		i++;
	}
	while (*base)
	{
		if (*base == '-' || *base == '+' || (*base >= 9 && *base <= 13) ||
		*base == 32)
			return (0);
		base++;
	}
	return (1);
}

int				base_char_to_int(char *c, char *base, int base_len)
{
	int idx;
	int result;

	result = 0;
	while (*c)
	{
		idx = 0;
		while (*(base + idx))
		{
			if (*c == *(base + idx))
				break ;
			else
				idx++;
		}
		if (idx == base_len)
			return (result);
		result *= base_len;
		result += idx;
		c++;
	}
	return (result);
}

int				ft_atoi_base(char *str, char *base)
{
	unsigned int	base_len;
	int				sign;
	int				result;

	base_len = get_strlen(base);
	if (!(check_base(base, base_len)))
		return (0);
	while (*str)
	{
		if ((*str >= 9 && *str <= 13) || *str == 32)
			str++;
		else
			break ;
	}
	sign = 1;
	while (ft_is_sign(*str, &sign))
		str++;
	result = base_char_to_int(str, base, base_len) * sign;
	return (result);
}
