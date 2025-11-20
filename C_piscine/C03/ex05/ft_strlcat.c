/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yanren <yanren@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/24 13:07:33 by yanren            #+#    #+#             */
/*   Updated: 2024/06/24 13:07:33 by yanren           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

unsigned int	ft_strlcat(char *dest, char *src, unsigned int size)
{
	unsigned int	si;
	unsigned int	dj;
	unsigned int	n;
	unsigned int	dl;

	si = 0;
	dj = 0;
	n = 0;
	while (src[si])
		si++;
	while (dest[dj])
		dj++;
	dl = dj;
	if (size == 0 || size <= dl)
		return (si + size);
	while (src[n] && n < size - dl - 1)
	{
		dest[dj] = src[n];
		dj++;
		n++;
	}
	dest[dj] = '\0';
	return (dl + si);
}

// #include <stdio.h>

// int main(void)
// {
// 	char des[] = "decent";
// 	char sr[] = "happy";
//     printf("%d\n", ft_strlcat(des, sr, 23));
// 	printf("%s", des);
// }
