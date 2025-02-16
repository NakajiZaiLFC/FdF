/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_hex.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snakajim <snakajim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/14 16:39:27 by snakajim          #+#    #+#             */
/*   Updated: 2024/07/15 11:55:55 by snakajim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf_hex(unsigned int hex, int (*up_or_low)(int))
{
	char	*hex_digit;
	int		count;

	count = 0;
	hex_digit = HEX;
	if (hex >= 16)
		count += ft_printf_hex((hex / 16), up_or_low);
	ft_printf_char(up_or_low(hex_digit[hex % 16]));
	return (count + 1);
}
