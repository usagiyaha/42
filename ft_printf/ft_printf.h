/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yanren <yanren@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 15:59:58 by yanren            #+#    #+#             */
/*   Updated: 2025/02/26 17:35:43 by yanren           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "./libft/libft.h"
# include <stdarg.h>

int			ft_printf(const char *format, ...);
int			put_bytype(const char *str, va_list args);
int			put_char(char c);
int			put_string(char *s);
int			put_hex(unsigned long num, const char c);
int			put_number(int n);
int			put_pointer(unsigned long num);
int			put_unsigned(unsigned int n);

#endif
