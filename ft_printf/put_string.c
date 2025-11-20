/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_string.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yanren <yanren@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 16:37:02 by yanren            #+#    #+#             */
/*   Updated: 2025/03/16 13:13:23 by yanren           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	put_string(char *s)
{
	if (!s)
	{
		write (1, "(null)", 6);
		return (6);
	}
	return (write (1, s, ft_strlen(s)));
}

// #include <stdio.h>

// int main()
// {
// 	int re;

// 	re = put_string("happytime");
// 	//printf("%i", re);
// 	return 0;
// }