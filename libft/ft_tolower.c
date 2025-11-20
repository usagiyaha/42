/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tolower.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yanren <yanren@student.42prague.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/21 15:55:21 by yanren            #+#    #+#             */
/*   Updated: 2024/11/29 17:37:57 by yanren           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_tolower(int c)
{
	if (c >= 'A' && c <= 'Z')
	{
		c = c + 32;
	}
	return (c);
}

// #include <ctype.h>
// #include <stdio.h>
// int main()
// {
// 	int r;
// 	int re;
// 	r = ft_tolower('A');
// 	re = tolower('A');
// 	printf("%c\n", r);
// 	printf("%c", re);
// }
