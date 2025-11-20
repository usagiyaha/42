/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yanren <yanren@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/24 17:54:55 by yanren            #+#    #+#             */
/*   Updated: 2024/06/24 17:56:19 by yanren           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_strcmp(char *s1, char *s2)
{
	int	i;

	i = 0;
	while (s1[i] == s2[i] && s1[i] && s2[i])
		i++;
	if (s1[i] != s2[i])
		return (s1[i] - s2[i]);
	else
		return (0);
}

// #include <stdio.h>

// int	main(int argc, char* argv[])
// {
// 	if (argc == 3)
// 	{
// 		int re;
// 		re = ft_strcmp(argv[1], argv[2]);
// 		printf("%d", re);
// 	}
// 	return (0);
// }
