/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yanren <yanren@student.42prague.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/28 18:38:39 by yanren            #+#    #+#             */
/*   Updated: 2024/11/28 18:39:33 by yanren           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_digits(int n)
{
	int	c;

	c = 0;
	if (n < 0)
	{
		n = (-1) * n;
		c++;
	}
	while (n > 0)
	{
		n = n / 10;
		c++;
	}
	return (c);
}

static char	*ft_to_str(char *s, int n)
{
	int	digit;

	digit = ft_digits(n);
	s[digit] = '\0';
	if (n < 0)
	{
		*s = '-';
		n = (-1) * n;
	}
	while (n > 0)
	{
		s[--digit] = (n % 10) + 48;
		n = n / 10;
	}
	return (s);
}

char	*ft_itoa(int n)
{
	char	*s;
	int		d;

	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	if (n == 0)
		return (ft_strdup("0"));
	d = ft_digits(n);
	s = (char *)malloc((d + 1) * sizeof(char));
	if (s == NULL)
		return (NULL);
	return (ft_to_str(s, n));
}

// #include <stdio.h>
// #include "ft_strdup.c"
// #include "ft_strlen.c"
// int	main(void)
// {
// 	char *re;
// 	re = ft_itoa(-2147483648);
// 	printf("%s", re);
// }