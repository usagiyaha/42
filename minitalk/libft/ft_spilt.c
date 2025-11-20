/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_spilt.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yanren <yanren@student.42prague.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 20:55:47 by yanren            #+#    #+#             */
/*   Updated: 2024/12/02 20:08:02 by yanren           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_number_word(char const *s, char c)
{
	int	number;
	int	cword;

	number = 0;
	cword = 0;
	while (*s)
	{
		if (*s != c && cword == 0)
		{
			number++;
			cword = 1;
		}
		else if (*s == c)
		{
			cword = 0;
		}
		s++;
	}
	return (number);
}

static char	*ft_word(char const *s, char c)
{
	char	*word;
	int		i;

	i = 0;
	while (s[i] && s[i] != c)
		i++;
	word = (char *)malloc((i + 1) * sizeof(char));
	if (word == NULL)
		return (NULL);
	ft_strlcpy(word, s, i + 1);
	return (word);
}

static void	ft_free(char **s, int n)
{
	while (s[n] != NULL && n >= 0)
	{
		free(s[n]);
		n--;
	}
	free(s);
	s = NULL;
}

char	**ft_split(char const *s, char c)
{
	int		i;
	int		len;
	int		word_number;
	char	**words;

	word_number = ft_number_word (s, c);
	words = (char **)malloc((word_number + 1) * sizeof(char *));
	if (s == NULL || words == NULL)
		return (NULL);
	i = 0;
	len = 0;
	while (s[len] && word_number > 0)
	{
		while (s[len] == c)
			len++;
		if (!s[len])
			break ;
		words[i] = ft_word(s + len, c);
		if (words[i] == NULL)
			ft_free(words, i);
		len = len + ft_strlen(words[i]);
		i++;
	}
	words[i] = NULL;
	return (words);
}

// #include <stdio.h>
// #include "ft_strlen.c"
// #include "ft_strlcpy.c"
// #include "ft_memcpy.c"

// int main()
// {
// 	char s[]= "olol";
// 	char c = ' ';
// 	char **result = ft_split(s, c);
// 	if (result == NULL)
// 	{
// 		printf("Result is NULL\n");
// 		return 0;
// 	}
// 	for (int i =0; result[i]; i++)
// 	{
// 		printf("The word is %s\n", result[i]);
// 		free(result[i]);
// 	}
// 	printf("The s is %s\n", s);
// 	free(result);
// }