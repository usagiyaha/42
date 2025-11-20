/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yanren <yanren@student.42prague.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/21 12:17:24 by yanren            #+#    #+#             */
/*   Updated: 2024/09/21 12:17:25 by yanren           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_bzero(void *s, size_t n)
{
	char	*ptr;

	ptr = (char *) s;
	while (n-- > 0)
		*ptr++ = '\0';
}

// #include <stdio.h>
// #include <string.h>

// int main() 
// { 
//     char str[50] = "GeeksForGeeks is for programming geeks."; 
//     printf("\nBefore bzero(): %s\n", str); 
//     // Fill 8 characters starting from str[13] with '.' 
//     //bzero(str + 13, 8*sizeof(char)); 
// 	ft_bzero(str + 13, 8*sizeof(char) );
//     printf("After bzero():  %s", str); 
//     return 0; 
// } 