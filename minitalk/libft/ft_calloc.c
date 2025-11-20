/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yanren <yanren@student.42prague.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/26 14:42:06 by yanren            #+#    #+#             */
/*   Updated: 2024/09/26 14:43:17 by yanren           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	unsigned char	*temp;
	size_t			i;

	i = 0;
	temp = malloc(nmemb * size);
	if (temp == NULL)
		return (NULL);
	while (i < nmemb * size)
	{
		temp[i] = 0;
		i++;
	}
	return (temp);
}

// #include <stdio.h>
// int main()
// {

//     // This pointer will hold the
//     // base address of the block created
//     int *ptr, *ptr1;
//     int n;

//     // Get the number of elements for the array
//     n = 5;
//     printf("Enter number of elements: %d\n", n);

//     // Dynamically allocate memory using malloc()
//     ptr = (int*)calloc(n , sizeof(int));

//     // Dynamically allocate memory using calloc()
//     ptr1 = (int*)ft_calloc(n, sizeof(int));

//     // Check if the memory has been successfully
//     // allocated by malloc or not
//     if (ptr == NULL || ptr1 == NULL) {
//         printf("Memory not allocated.\n");
//         exit(0);
//     }
//     else {

//         // Memory has been successfully allocated
//         printf("Memory successfully allocated using ft_calloc.\n");
//     }

//     return 0;
// }
