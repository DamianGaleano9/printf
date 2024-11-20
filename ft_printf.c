/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmazo-ga <dmazo-ga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 19:03:05 by dmazo-ga          #+#    #+#             */
/*   Updated: 2024/11/18 19:59:34 by dmazo-ga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	check_arg(const char *input, void *arg)
{
	int	i;

	i = 0;
	if (*input == 'c')
		i += print_char((int)arg);
	else if (*input == 's')
		i += print_string((char *)arg);
	else if (*input == 'p')
		i += print_pointer((unsigned long)arg, 87);
	else if (*input == 'd')
		i += print_int((int)arg);
	else if (*input == 'i')
		i += print_int((int)arg);
	else if (*input == 'u')
		i += print_unsigned((unsigned int)arg);
	else if (*input == 'x')
		i += print_hex((unsigned int)arg, 87);
	else if (*input == 'X')
		i += print_hex((unsigned int)arg, 55);
	return (i);
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
			if (ft_strchr("cspdiuxX", *input))
				i += check_arg(input, va_arg(args, void *));
			else if (*input == '%')
				i += print_char('%');
		}
		else
			i = i + print_char(*input);
		input++;
	}
	va_end (args);
	return (i);
}

// int main() {
//     // Prueba con un carácter
//     char c = 'A';
//     ft_printf("Prueba 1: %c\n", c);

//     // Prueba con una cadena
//     char *str = "Hola, mundo!";
//     ft_printf("Prueba 2: %s\n", str);

//     // Prueba con un número entero
//     int d = 42;
//     ft_printf("Prueba 3: %d\n", d);

//     // Prueba con un número entero negativo
//     int neg = -42;
//     ft_printf("Prueba 4: %d\n", neg);

//     // Prueba con un número sin signo
//     unsigned int u = 42;
//     ft_printf("Prueba 5: %u\n", u);

//     // Prueba con un número en hexadecimal (minúsculas)
//     unsigned int x = 255;
//     ft_printf("Prueba 6: %x\n", x);

//     // Prueba con un número en hexadecimal (mayúsculas)
//     unsigned int X = 255;
//     ft_printf("Prueba 7: %X\n", X);

//     // Prueba con un puntero
//     int *ptr = &d;
//     ft_printf("Prueba 8: %p\n", ptr);

//     // Prueba con un porcentaje
//     ft_printf("Prueba 9: %%\n");

// 	ft_printf(NULL);

//     return 0;
// }
