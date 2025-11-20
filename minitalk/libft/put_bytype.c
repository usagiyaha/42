/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_bytype.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yanren <yanren@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 16:13:29 by yanren            #+#    #+#             */
/*   Updated: 2025/06/24 16:50:59 by yanren           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	put_bytype(const char *str, va_list args)
{
	if (*str == 'c')
		return (put_char(va_arg(args, int)));
	if (*str == 's')
		return (put_string(va_arg(args, char *)));
	if (*str == 'p')
		return (put_pointer(va_arg(args, unsigned long)));
	if (*str == 'd' || *str == 'i')
		return (put_number(va_arg(args, int)));
	if (*str == 'u')
		return (put_unsigned(va_arg(args, unsigned int)));
	if (*str == 'x' || *str == 'X')
		return (put_hex(va_arg(args, unsigned int), *str));
	if (*str == '%')
		return (put_char('%'));
	return (put_char('%') + put_char(*str));
}
