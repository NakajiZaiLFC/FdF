/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_unsigned.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snakajim <snakajim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/14 15:03:06 by snakajim          #+#    #+#             */
/*   Updated: 2024/07/14 18:46:47 by snakajim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf_unsigned(unsigned int num)
{
	int	len;

	len = 0;
	if (num > 9)
		len += ft_printf_unsigned(num / 10);
	ft_printf_char(((num % 10) + '0'));
	return (len + 1);
}
