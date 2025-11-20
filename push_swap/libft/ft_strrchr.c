/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yanren <yanren@student.42prague.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/21 16:14:09 by yanren            #+#    #+#             */
/*   Updated: 2024/12/04 12:06:36 by yanren           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	const char	*p;

	p = NULL;
	while (*s)
	{
		if (*s == (char)c)
			p = s;
		s++;
	}
	if (*s == (char)c)
		return ((char *)s);
	return ((char *)p);
}

// #include <stdio.h>
// #include <string.h>
// #include "ft_strlen.c"
// int main()
// {
// 	char s[] = "";
// 	char *r = ft_strrchr(s, 'x');
// 	char *re = strrchr(s, 'x');
// 	printf("%s\n", r);
// 	printf("%li\n", r - s);
// 	printf("%s\n", re);
// 	printf("%li\n", re - s);
// 	return 0;
// }