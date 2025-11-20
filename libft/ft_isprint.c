/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isprint.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yanren <yanren@student.42prague.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/19 11:48:22 by yanren            #+#    #+#             */
/*   Updated: 2024/09/19 11:48:23 by yanren           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isprint(int c)
{
	if (c >= 32 && c <= 126)
		return (16384);
	return (0);
}

// #include <stdio.h>
// #include <ctype.h>
// int	main(void)
// {
// 	int	r;
// 	int re;

// 	r = ft_isprint('9');
// 	re = isprint('9');
// 	printf("%d", r);
// 	printf("%c", '\n');
// 	printf("%d", re);
// //	isalpha(r);
// }