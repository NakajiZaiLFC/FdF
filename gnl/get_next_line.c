/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snakajim <snakajim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/19 11:01:12 by snakajim          #+#    #+#             */
/*   Updated: 2025/01/02 12:04:51 by snakajim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/get_next_line.h"

char	*str_free(t_string ret);

char	*get_next_line(int fd)
{
	t_string	ret;
	int			c;

	ret = (t_string){NULL, 0, 0};
	while (1)
	{
		c = ft_getc(fd);
		if (c == -2)
			return (str_free(ret));
		if (c == EOF)
			break ;
		c = ft_putc(&ret, c);
		if (c == -1)
			return (str_free(ret));
		if (c == '\n')
			break ;
	}
	if (ret.len > 0)
		c = ft_putc(&ret, '\0');
	if (c == -1)
		return (str_free(ret));
	return (ret.str);
}

char	*str_free(t_string ret)
{
	free(ret.str);
	return (NULL);
}
