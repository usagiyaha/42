/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yanren <yanren@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/17 12:58:42 by yanren            #+#    #+#             */
/*   Updated: 2025/04/06 16:29:24 by yanren           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 10
# endif

# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>

typedef struct s_list
{
	char			*str;
	struct s_list	*next;
}	t_list;

t_list	*find_last_node(t_list *list);
void	append(t_list **list, char *buf);
int		len_to_newline(t_list *list);
void	copy_str(t_list *list, char *s);
void	dealloc(t_list **list, t_list *clean_node, char *buf);
int		found_newline(t_list *list);
void	create_list(t_list **list, int fd);
char	*get_str_in_line(t_list *list);
void	ready_list(t_list **list);
char	*get_next_line(int fd);

#endif