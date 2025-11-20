/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yanren <yanren@student.42prague.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 13:53:27 by yanren            #+#    #+#             */
/*   Updated: 2024/11/27 14:34:22 by yanren           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_check(char c, const char *set)
{
	while (*set)
	{
		if (*set == c)
			return (1);
		set++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	i;
	size_t	j;
	size_t	r;
	char	*result;

	if (s1 == NULL || set == NULL)
		return (NULL);
	i = 0;
	while (s1[i] && ft_check(s1[i], set) == 1)
		i++;
	j = ft_strlen(s1);
	while (j > i && ft_check(s1[j - 1], set) == 1)
		j--;
	result = (char *)malloc((j - i + 1) * sizeof(char));
	if (result == NULL)
		return (NULL);
	r = 0;
	while (i < j)
	{
		result[r] = s1[i];
		r++;
		i++;
	}
	result[r] = '\0';
	return (result);
}

// #include <stdio.h>
// #include "ft_strlen.c"
// int main()
// {
// 	char *re;
// 	re = ft_strtrim("aawater", "ar");
// 	printf("Result is %s\n", re);
// 	return (1);
// }