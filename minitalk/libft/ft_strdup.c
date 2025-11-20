/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yanren <yanren@student.42prague.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/26 15:05:25 by yanren            #+#    #+#             */
/*   Updated: 2024/11/29 18:49:26 by yanren           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	char	*ds;
	size_t	n;
	size_t	i;

	n = ft_strlen(s);
	ds = (char *)malloc((n + 1) * sizeof(char));
	if (ds == NULL)
		return (NULL);
	i = 0;
	while (i <= n)
	{
		ds[i] = s[i];
		i++;
	}
	return (ds);
}

// #include <stdio.h>
// #include <string.h>
// int	main()
// {
// 	char * re;
// 	char * r;

// 	re = strdup("string");
// 	r = ft_strdup("string");
// 	printf("%s", re);
// 	printf("%s", r);
// }