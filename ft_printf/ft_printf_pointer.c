/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_pointer.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snakajim <snakajim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/14 17:08:19 by snakajim          #+#    #+#             */
/*   Updated: 2024/07/14 18:46:17 by snakajim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_printf_pointer_hex(uintptr_t n)
{
	char	*hex_digit;
	int		count;

	count = 0;
	hex_digit = HEX;
	if (n >= 16)
		count += ft_printf_pointer_hex(n / 16);
	ft_printf_char(hex_digit[n % 16]);
	return (count + 1);
}

int	ft_printf_pointer(void *ptr)
{
	int			count;
	uintptr_t	ptr_n;

	count = 2;
	ptr_n = (uintptr_t)ptr;
	write(1, "0x", 2);
	count += ft_printf_pointer_hex(ptr_n);
	return (count);
}
