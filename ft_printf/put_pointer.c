/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_pointer.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yanren <yanren@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 16:10:19 by yanren            #+#    #+#             */
/*   Updated: 2025/02/26 17:38:16 by yanren           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	put_pointer(unsigned long num)
{
	int	count;

	if (num == 0)
		return (put_string("(nil)"));
	count = 0;
	count += put_string("0x");
	count += put_hex(num, 'x');
	return (count);
}
