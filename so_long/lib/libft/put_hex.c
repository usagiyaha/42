/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_hex.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yanren <yanren@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 16:12:03 by yanren            #+#    #+#             */
/*   Updated: 2025/06/24 16:56:34 by yanren           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	put_hex(unsigned long num, const char c)
{
	char	*base;
	char	buffer[16];
	int		count;
	int		i;

	i = 0;
	count = 0;
	if (num == 0)
		return (put_char('0'));
	if (c == 'x')
		base = "0123456789abcdef";
	else
		base = "0123456789ABCDEF";
	while (num > 0 && i < 16)
	{
		buffer[i] = base[num % 16];
		num = num / 16;
		i++;
	}
	while (--i >= 0)
		count += put_char(buffer[i]);
	return (count);
}
