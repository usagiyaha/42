/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_non_printable.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yanren <yanren@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/20 12:54:41 by yanren            #+#    #+#             */
/*   Updated: 2024/06/20 13:29:02 by yanren           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putstr_non_printable(char *str)
{
	char	*hex;
	int		i;
	char	bs;

	hex = "0123456789abcdef";
	i = 0;
	bs = '\\';
	while (str[i])
	{
		if (str[i] >= 32 && str[i] <= 126)
			write(1, &str[i], 1);
		else
		{
			write(1, &bs, 1);
			write(1, &(hex[str[i] / 16]), 1);
			write(1, &(hex[str[i] % 16]), 1);
		}
		i++;
	}
}

/*
#include <stdio.h>

int	main(int argc, char *argv[])
{
	char str[] = "Coucou\ntu vas bien ?";
	ft_putstr_non_printable(str);
}
*/
