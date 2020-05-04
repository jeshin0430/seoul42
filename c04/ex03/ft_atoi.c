/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeshin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/03 15:02:35 by jeshin            #+#    #+#             */
/*   Updated: 2020/02/05 16:08:11 by jeshin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_is_space(char c)
{
	if ((c >= 9 && c <= 13) || (c == 32))
		return (1);
	return (0);
}

int		ft_is_sign(char c, int *sign)
{
	if (c == '-')
	{
		*sign = *sign * -1;
		return (1);
	}
	else if (c == '+')
		return (1);
	return (0);
}

int		ft_is_numeric(char c, int *num)
{
	if (c >= '0' && c <= '9')
	{
		*num *= 10;
		*num += c - '0';
		return (1);
	}
	return (0);
}

int		ft_atoi(char *str)
{
	int sign;
	int num;

	num = 0;
	sign = 1;
	while ((ft_is_space(*str)))
		str++;
	while ((ft_is_sign(*str, &sign)))
		str++;
	while ((ft_is_numeric(*str, &num)))
		str++;
	return (sign * num);
}


int     main(void)
{
    int num;
    
    num = ft_atoi("1234");
    printf("%d",num);
}
