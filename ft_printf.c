/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmazo-ga <dmazo-ga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 19:03:05 by dmazo-ga          #+#    #+#             */
/*   Updated: 2024/12/10 18:41:12 by dmazo-ga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	check_arg(const char *input, va_list args)
{
	int	i;

	i = 0;
	if (*input == 'c')
		i += ft_print_char(va_arg(args, int));
	else if (*input == 's')
		i += ft_print_string(va_arg(args, char *));
	else if (*input == 'p')
		i += ft_print_poin(va_arg(args, unsigned long));
	else if (*input == 'd' || *input == 'i')
		i += ft_print_int(va_arg(args, int));
	else if (*input == 'u')
		i += ft_print_unsigned(va_arg(args, unsigned int));
	else if (*input == 'x')
		i += ft_print_hexa(va_arg(args, unsigned int), *input);
	else if (*input == 'X')
		i += ft_print_hexa(va_arg(args, unsigned int), *input);
	else if (*input == '%')
		i += ft_print_char('%');
	return (i);
}

static int	valid_format(char c)
{
	const char	*formats = "cspdiuxX";

	while (*formats)
	{
		if (*formats == c)
			return (1);
		formats++;
	}
	return (0);
}

int	ft_printf(const char *input, ...)
{
	va_list			args;
	unsigned int	i;

	i = 0;
	va_start(args, input);
	while (*input != '\0')
	{
		if (*input == '%')
		{
			input++;
			if (valid_format(*input))
				i += check_arg(input, args);
			else if (*input == '%')
				i += ft_print_char('%');
		}
		else
			i = i + ft_print_char(*input);
		input++;
	}
	va_end (args);
	return (i);
}
