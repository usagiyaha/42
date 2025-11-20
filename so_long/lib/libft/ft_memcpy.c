/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yanren <yanren@student.42prague.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/21 12:42:39 by yanren            #+#    #+#             */
/*   Updated: 2024/09/21 12:46:09 by yanren           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	char	*ptrd;
	char	*ptrs;

	ptrd = (char *) dest;
	ptrs = (char *) src;
	if (!ptrd && !ptrs)
		return (NULL);
	while (n-- > 0)
	{
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
//    printf("Before memcpy dest = %s\n", dest);
//    ft_memcpy(dest, src, strlen(src) + 1);
//    printf("After memcpy dest = %s\n", dest);
//    return(0);
// }