/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snakajim <snakajim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/01 15:48:32 by snakajim          #+#    #+#             */
/*   Updated: 2025/01/02 12:59:34 by snakajim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

int	ft_strlncmp(char *s1, char *s2, int n)
{
	int		s1_len;
	char	*s1_tmp;
	int		i;

	i = 0;
	s1_tmp = (char *)malloc(sizeof(char) * (n + 1));
	if (!s1_tmp)
		return (-1);
	s1_len = ft_strlen(s1);
	while (i < 4)
	{
		s1_tmp[i] = s1[s1_len - n + i];
		i++;
	}
	if (ft_strncmp(s1_tmp, s2, n) == 0)
		return (free(s1_tmp), 0);
	else
		return (free(s1_tmp), -1);
}

int	ft_atoi_base(char *str, int base)
{
	int	i;
	int	res;
	int	sign;

	i = 0;
	res = 0;
	sign = 1;
	if (str[i] == '-')
	{
		sign = -1;
		i++;
	}
	while (str[i])
	{
		if (str[i] >= '0' && str[i] <= '9')
			res = res * base + str[i] - '0';
		else if (str[i] >= 'A' && str[i] <= 'F')
			res = res * base + str[i] - 'A' + 10;
		else if (str[i] >= 'a' && str[i] <= 'f')
			res = res * base + str[i] - 'a' + 10;
		i++;
	}
	return (res * sign);
}
