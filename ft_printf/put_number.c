/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_number.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yanren <yanren@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 16:01:42 by yanren            #+#    #+#             */
/*   Updated: 2025/03/16 15:10:04 by yanren           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	put_number(int n)
{
	int	count;

	count = 0;
	if (n == -2147483648)
		return (put_string("-2147483648"));
	else if (n < 0)
	{
		count += put_char('-');
		n = n * (-1);
	}
	if (n < 10)
	{
		count += put_char(n + '0');
		return (count);
	}
	return (count + put_number(n / 10) + put_char(n % 10 + '0'));
}

int	put_unsigned(unsigned int n)
{
	if (n < 10)
		return (put_char(n + '0'));
	else
		return (put_unsigned(n / 10) + put_char(n % 10 + '0'));
}
