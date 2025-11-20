/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yanren <yanren@student.42prague.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/26 16:15:55 by yanren            #+#    #+#             */
/*   Updated: 2024/12/04 13:22:32 by yanren           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*new;
	size_t	n;
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	if (s1 == NULL || s2 == NULL)
		return (NULL);
	n = ft_strlen(s1) + ft_strlen(s2) + 1;
	new = (char *)malloc(n * sizeof(char));
	if (!new)
		return (NULL);
	while (s1[i] != '\0')
	{
		new[j++] = s1[i++];
	}
	i = 0;
	while (s2[i] != '\0')
	{
		new[j++] = s2[i++];
	}
	new[j] = '\0';
	return (new);
}

// #include <stdlib.h>
// #include <stdio.h>
// #include "ft_strlen.c"
// int	main()
// {
// 	char *re;
// 	re = ft_strjoin("j", "ok");
// 	printf("%s", re);
// }