/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isascii.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yanren <yanren@student.42prague.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/19 11:42:31 by yanren            #+#    #+#             */
/*   Updated: 2024/09/19 11:42:34 by yanren           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isascii(int c)
{
	if (c >= 0 && c <= 127)
		return (1);
	return (0);
}

// #include <stdio.h>
// #include <ctype.h>
// int	main(void)
// {
// 	int	r;
// 	int re;

// 	r = ft_isascii(128);
// 	re = isascii(128);
// 	printf("%d", r);
// 	printf("%c", '\n');
// 	printf("%d", re);
// //	isalpha(r);
// }