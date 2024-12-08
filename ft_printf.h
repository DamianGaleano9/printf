/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmazo-ga <dmazo-ga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 21:39:29 by marvin            #+#    #+#             */
/*   Updated: 2024/12/04 12:30:11 by dmazo-ga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>
# include <stdio.h>
// # include "./libft/libft.h"

int		ft_printf(const char *input, ...);
int		ft_print_poin(unsigned long n);
int		ft_print_string (char const *c);
int		ft_print_int(int n);
int		ft_print_char(char c);
int		ft_print_unsigned(unsigned int n);
int		ft_print_hexa(unsigned long n, char const arg);


#endif