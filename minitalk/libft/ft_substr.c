/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yanren <yanren@student.42prague.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/26 15:52:32 by yanren            #+#    #+#             */
/*   Updated: 2024/12/04 13:12:31 by yanren           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*subs;
	size_t	s_len;
	size_t	sub_len;
	size_t	i;

	s_len = ft_strlen(s);
	if (start >= s_len)
		sub_len = 1;
	else if (len > s_len - start)
		sub_len = s_len - start + 1;
	else
		sub_len = len + 1;
	subs = (char *)malloc(sub_len * sizeof(char));
	if (!subs)
		return (NULL);
	i = 0;
	while (i < sub_len - 1 && s[start] != '\0')
	{
		subs[i] = s[start];
		i++;
		start++;
	}
	subs[i] = '\0';
	return (subs);
}

// #include <stdio.h>
// #include "ft_strlen.c"
// #include <malloc.h>
// #include <stdlib.h>
// int	main()
// {
// 	char * re;

// 	re = ft_substr("", 0, 0);
// 	printf("%s\n", re);
// 	printf("expected malloc size %li\n", malloc_usable_size(re));
// 	free(re);
// 	return 0;
// }