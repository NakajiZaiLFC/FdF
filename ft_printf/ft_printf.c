/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nassy <nassy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/14 12:24:06 by snakajim          #+#    #+#             */
/*   Updated: 2024/08/20 08:05:08 by nassy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	print_formatted(const char specifier, va_list *ap)
{
	int	count;

	count = 0;
	if (specifier == 'c')
		count += ft_printf_char(va_arg(*ap, int));
	else if (specifier == 's')
		count += ft_printf_string(va_arg(*ap, char *));
	else if (specifier == 'p')
		count += ft_printf_pointer(va_arg(*ap, void *));
	else if (specifier == 'd')
		count += ft_printf_int(va_arg(*ap, int));
	else if (specifier == 'i')
		count += ft_printf_int(va_arg(*ap, int));
	else if (specifier == 'u')
		count += ft_printf_unsigned(va_arg(*ap, unsigned int));
	else if (specifier == 'x')
		count += ft_printf_hex(va_arg(*ap, unsigned int), ft_tolower);
	else if (specifier == 'X')
		count += ft_printf_hex(va_arg(*ap, unsigned int), ft_toupper);
	else
		count += ft_printf_char(specifier);
	return (count);
}

int	ft_printf(const char *str, ...)
{
	va_list	ap;
	int		count;

	count = 0;
	va_start(ap, str);
	while (*str)
	{
		if (*str == '%' && *(str + 1))
		{
			count += print_formatted(*(str + 1), &ap);
			str++;
		}
		else
			count += ft_printf_char(*str);
		str++;
	}
	va_end(ap);
	return (count);
}
//apをポインタとして渡せるように修正しろ