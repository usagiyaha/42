/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yanren <yanren@student.42prague.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/21 16:57:21 by yanren            #+#    #+#             */
/*   Updated: 2024/12/02 20:50:44 by yanren           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*str;
	unsigned char	cc;
	size_t			i;

	str = (unsigned char *)s;
	cc = (unsigned char)c;
	i = 0;
	while (i < n)
	{
		if (str[i] == cc)
			return ((void *)&str[i]);
		i++;
	}
	return (NULL);
}

// #include <stdio.h>
// #include <string.h>
// int main()
// {
// 	char *s = "/|\x12\xff\x09\0\x42\042\0\42|\\";
// 	char *r = (char *)ft_memchr(s, '\0', 12);
// 	char *ro = (char *)memchr(s, '\0', 12);
// 	printf("found at position: %li\n", r-s);
// 	printf("found at position: %li\n", ro-s);
// }