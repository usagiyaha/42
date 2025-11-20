/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yanren <yanren@student.42prague.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/21 13:35:41 by yanren            #+#    #+#             */
/*   Updated: 2024/09/21 13:36:19 by yanren           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	char	*ptrd;
	char	*ptrs;

	if (!src && !dest)
		return (NULL);
	ptrd = (char *)dest;
	ptrs = (char *)src;
	if (ptrd > ptrs)
	{
		while (n-- > 0)
			ptrd[n] = ptrs[n];
	}
	else
	{
		while (n-- > 0)
			*ptrd++ = *ptrs++;
	}
	return (dest);
}

// #include <stdio.h>
// #include <string.h>

// int main ()
// {
//    const char src[50] = "Tutorialspoint";
//    char dest[50];
//    strcpy(dest,"Heloooo!!Iamfromearth");
//    printf("Before memmove dest = %s\n", dest);
//    ft_memmove(dest, src, strlen(src) + 1);
//    printf("After memmove dest = %s\n", dest);
//    return(0);
// }
