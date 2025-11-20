/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yanren <yanren@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/17 12:45:36 by yanren            #+#    #+#             */
/*   Updated: 2025/07/31 11:53:39 by yanren           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	found_newline(t_list *list)
{
	int	i;

	if (list == NULL)
		return (0);
	while (list)
	{
		i = 0;
		while (list->str[i] && i < BUFFER_SIZE)
		{
			if (list->str[i] == '\n')
				return (1);
			i++;
		}
		list = list->next;
	}
	return (0);
}

void	create_list(t_list **list, int fd)
{
	int		char_read_num;
	char	*read_buffer;

	while (found_newline(*list) == 0)
	{
		read_buffer = malloc(BUFFER_SIZE + 1);
		if (!read_buffer)
			return ;
		char_read_num = read(fd, read_buffer, BUFFER_SIZE);
		if (char_read_num == 0)
		{
			free(read_buffer);
			return ;
		}
		if (char_read_num < 0)
		{
			free(read_buffer);
			dealloc(list, NULL, NULL);
			return ;
		}
		read_buffer[char_read_num] = '\0';
		append(list, read_buffer);
	}
}

char	*get_str_in_line(t_list *list)
{
	int		str_len;
	char	*line_to_print;

	if (list == NULL)
		return (NULL);
	str_len = len_to_newline(list);
	line_to_print = malloc(str_len + 1);
	if (line_to_print == NULL)
		return (NULL);
	copy_str(list, line_to_print);
	return (line_to_print);
}

void	ready_list(t_list **list)
{
	t_list	*last_node;
	t_list	*new_start_node;
	char	*buf;
	int		i;
	int		k;

	i = 0;
	k = 0;
	last_node = find_last_node(*list);
	buf = malloc(BUFFER_SIZE + 1);
	new_start_node = malloc(sizeof(t_list));
	if (buf == NULL || new_start_node == NULL)
		return ;
	if (found_newline(last_node) == 1)
	{
		while (last_node->str[i] != '\n')
			i++;
		while (last_node->str[++i])
			buf[k++] = last_node->str[i];
	}
	buf[k] = '\0';
	new_start_node->str = buf;
	new_start_node->next = NULL;
	dealloc(list, new_start_node, buf);
}

char	*get_next_line(int fd)
{
	static t_list	*list = NULL;
	char			*next_line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	create_list(&list, fd);
	if (list == NULL)
		return (NULL);
	next_line = get_str_in_line(list);
	ready_list(&list);
	return (next_line);
}
