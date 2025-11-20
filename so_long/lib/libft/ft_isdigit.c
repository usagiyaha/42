/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isdigit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yanren <yanren@student.42prague.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/19 11:02:24 by yanren            #+#    #+#             */
/*   Updated: 2024/09/19 11:02:28 by yanren           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isdigit(int c)
{
	if (c >= '0' && c <= '9')
		return (2048);
	return (0);
}

// #include <stdio.h>
// #include <ctype.h>
// int	main(void)
// {
// 	int	r;
// 	int re;

// 	r = ft_isdigit(8);
// 	re = isdigit(8);
// 	printf("%d", r);
// 	printf("%c", '\n');
// 	printf("%d", re);
// //	isalpha(r);
// }