/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush04.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsibilev <nsibilev@student.42prague.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/09 18:13:51 by nsibilev          #+#    #+#             */
/*   Updated: 2024/06/09 18:13:57 by nsibilev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_putchar(char c);

void	print_line(int x, int l, int m, int r)
{
	int	a;

	a = 1;
	while (a <= x)
	{
		if (a == 1)
		{
			ft_putchar(l);
		}
		else if (a == x)
		{
			ft_putchar(r);
		}
		else
		{
			ft_putchar(m);
		}
		a++;
	}
}

void	rush(int x, int y)
{
	int	b;

	b = 1;
	while (b <= y)
	{
		if (b == 1)
		{
			print_line(x, 'A', 'B', 'C');
		}
		else if (b == y && y > 1)
		{
			print_line(x, 'C', 'B', 'A');
		}
		else
		{
			print_line(x, 'B', ' ', 'B');
		}
		ft_putchar('\n');
		b++;
	}
}
