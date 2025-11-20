/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yanren <yanren@student.42prague.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/28 19:34:56 by yanren            #+#    #+#             */
/*   Updated: 2024/11/28 19:34:57 by yanren           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_striteri(char *s, void (*f)(unsigned int, char*))
{
	unsigned int	i;

	if (s == NULL || f == NULL)
		return ;
	i = 0;
	while (s[i] != '\0')
	{
		f(i, &s[i]);
		i++;
	}
}

// #include <stdio.h>
// void ft_test(unsigned int i, char *c)
// {
// 	*c = *c - i;
// }
// int main()
// {
// 	char s[] = "abcdefg";
// 	ft_striteri(s, ft_test);
// 	printf("%s", s);
// 	return (0);
// }