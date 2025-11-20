/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_toupper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yanren <yanren@student.42prague.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/21 15:54:21 by yanren            #+#    #+#             */
/*   Updated: 2024/11/29 17:39:15 by yanren           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_toupper(int c)
{
	if (c >= 'a' && c <= 'z')
	{
		c = c - 32;
	}
	return (c);
}

// #include <ctype.h>
// #include <stdio.h>
// int main()
// {
// 	int r;
// 	int re;
// 	r = ft_toupper('a');
// 	re = toupper('a');
// 	printf("%c\n", r);
// 	printf("%c", re);
// }