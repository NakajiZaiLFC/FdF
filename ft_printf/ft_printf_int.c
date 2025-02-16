/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_int.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snakajim <snakajim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/14 14:05:26 by snakajim          #+#    #+#             */
/*   Updated: 2024/07/15 11:23:49 by snakajim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf_int(int num)
{
	char	*char_num;
	size_t	i;

	i = 0;
	char_num = ft_itoa(num);
	if (!char_num)
		return (0);
	while (char_num[i])
		ft_printf_char(char_num[i++]);
	free(char_num);
	return (i);
}
