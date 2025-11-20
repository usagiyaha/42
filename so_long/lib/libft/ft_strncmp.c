/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yanren <yanren@student.42prague.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/21 16:18:24 by yanren            #+#    #+#             */
/*   Updated: 2024/11/29 19:24:55 by yanren           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	i = 0;
	if (n == 0)
		return (0);
	while (i < (n - 1) && s1[i] && s2[i] && (s1[i] == s2[i]))
		i++;
	return ((unsigned char)s1[i] - (unsigned char)s2[i]);
}

// #include <stdio.h>
// #include <string.h>
// #include "ft_strlen.c"
// int main()
// {
// 	char d[] = "hello";
// 	char s[] = "-";
// 	int r;
// 	int re;
// 	r = ft_strncmp(d, s, 13);
// 	re = strncmp(d, s, 13);
// 	printf("%i\n", r);
// 	printf("%i\n", re);
// 	return (0);
// }
