/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yanren <yanren@student.42prague.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/28 20:29:37 by yanren            #+#    #+#             */
/*   Updated: 2024/12/04 17:24:19 by yanren           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	if (n == -2147483648)
		ft_putstr_fd("-2147483648", fd);
	else if (n < 0)
	{
		ft_putchar_fd('-', fd);
		ft_putnbr_fd((-1) * n, fd);
	}
	else if (n < 10)
	{
		n = n + '0';
		ft_putchar_fd(n, fd);
	}
	else
	{
		ft_putnbr_fd(n / 10, fd);
		ft_putnbr_fd(n % 10, fd);
	}
}

// #include <stdio.h>
// #include "ft_strlen.c"
// #include "ft_putchar_fd.c"
// #include "ft_putstr_fd.c"
// int main(void)
// {
// 	int num[5] = {0, -34343, 343424, -2147483648, 2147483647};
// 	for (int i = 0; i < 5; i++)
// 	{
// 		ft_putnbr_fd(num[i], 1);
// 		write (1, "\n", 1);
// 	}
// 	return 0;
// }