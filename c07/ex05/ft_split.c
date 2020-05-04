/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeshin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/09 23:51:58 by jeshin            #+#    #+#             */
/*   Updated: 2020/02/09 23:53:31 by jeshin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int		ft_charset_check(char ***strss, char *str, char *charset)
{
	int		len;
	int		i;

	if (!(*charset))
	{
		len = 0;
		i = 0;
		while (str[len])
			len++;
		*strss = (char **)malloc(sizeof(char **) * 2);
		**strss = malloc(sizeof(char) * (len + 1));
		while (i < len)
		{
			(**strss)[i] = str[i];
			i++;
		}
		(**strss)[i] = '\0';
		(*strss)[1] = NULL;
		return (1);
	}
	return (0);
}

int		ft_ischarset(char c, char *charset)
{
	int		i;

	i = 0;
	while (charset[i])
		if (c == charset[i++])
			return (1);
	return (0);
}

int		ft_word_count(char *str, char *charset)
{
	int	count;
	int	check_word;

	count = 0;
	check_word = 0;
	if (!str)
		return (0);
	while (*str && ft_ischarset(*str, charset))
		str++;
	while (*str)
	{
		if (!ft_ischarset(*str, charset))
		{
			if (check_word == 0)
			{
				count++;
				check_word = -1;
			}
		}
		else if (check_word == -1)
			check_word = 0;
		str++;
	}
	return (count);
}

int		ft_checklen(char *str, char *charset)
{
	int len;

	len = 0;
	while (*str && !ft_ischarset(*str, charset))
	{
		str++;
		len++;
	}
	return (len);
}

char	**ft_split(char *str, char *charset)
{
	char	**strs;
	int		count;
	int		len;
	int		i;
	int		j;

	if (ft_charset_check(&strs, str, charset))
		return (strs);
	count = ft_word_count(str, charset);
	strs = malloc(sizeof(char *) * (count + 1));
	i = 0;
	while (0 < count--)
	{
		j = 0;
		while (ft_ischarset(*str, charset))
			str++;
		len = ft_checklen(str, charset);
		strs[i] = malloc(sizeof(char *) * (len + 1));
		while (!ft_ischarset(*str, charset))
			strs[i][j++] = *(str++);
		strs[i][j] = '\0';
		i++;
	}
	strs[i] = 0;
	return (strs);
}
