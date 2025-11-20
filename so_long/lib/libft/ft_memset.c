/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yanren <yanren@student.42prague.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/21 12:03:57 by yanren            #+#    #+#             */
/*   Updated: 2024/09/21 12:06:15 by yanren           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *s, int c, size_t n)
{
	char	*ptr;

	ptr = (char *) s;
	while (n-- > 0)
		*ptr++ = c;
	return (s);
}

// #include <stdio.h>
// #include <string.h>

// int main() 
// { 
//     char str[50] = "GeeksForGeeks is for programming geeks."; 
//     printf("\nBefore memset(): %s\n", str); 
//     // Fill 8 characters starting from str[13] with '.' 
//     //memset(str + 13, '.', 8*sizeof(char)); 
// 	ft_memset(str + 13, '.', 8*sizeof(char) );
//     printf("After memset():  %s", str); 
//     return 0; 
// } 