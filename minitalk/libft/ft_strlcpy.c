/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yanren <yanren@student.42prague.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/21 13:58:20 by yanren            #+#    #+#             */
/*   Updated: 2024/11/29 19:05:18 by yanren           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t	sl;

	sl = ft_strlen(src);
	if (size != '\0')
	{
		if (sl >= size)
		{
			ft_memcpy(dst, src, size - 1);
			dst[size - 1] = '\0';
		}
		else
		{
			ft_memcpy(dst, src, sl);
			dst[sl] = '\0';
		}
	}
	return (sl);
}

// #include <stdio.h>
// #include <string.h>
// #include "ft_strlen.c"
// #include "ft_memcpy.c"
// int main()
// {
// 	char d[] = "hello";
// 	char s[] = "world";
// 	int re;

// 	re = ft_strlcpy(d, s, 5);

// 	printf("%i\n", re);
// 	printf("%s", d);

// 	return (0);
// }