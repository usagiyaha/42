/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yanren <yanren@student.42prague.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/21 14:00:35 by yanren            #+#    #+#             */
/*   Updated: 2024/09/21 14:00:35 by yanren           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t size)
{
	size_t	dlen;
	size_t	slen;
	size_t	clen;

	dlen = ft_strlen(dest);
	slen = ft_strlen(src);
	if (dlen >= size)
		return (size + slen);
	clen = size - dlen - 1;
	if (clen > slen)
		clen = slen;
	ft_memcpy(dest + dlen, src, clen);
	dest[dlen + clen] = '\0';
	return (dlen + slen);
}

// #include <stdio.h>
// #include <string.h>
// #include "ft_strlen.c"
// int main()
// {
// 	char d[] = "hello";
// 	char s[] = "world";
// 	int re;

// 	re = ft_strlcat(d, s, 3);

// 	printf("%i\n", re);

// 	return (0);
// }