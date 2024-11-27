/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmazo-ga <dmazo-ga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 19:03:05 by dmazo-ga          #+#    #+#             */
/*   Updated: 2024/11/27 16:23:40 by dmazo-ga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	check_arg(const char *input, va_list args)
{
	int	i;

	i = 0;
	if (*input == 'c')
		i += print_char(va_arg(args, int));
	else if (*input == 's')
		i += print_string(va_arg(args, char *));
	else if (*input == 'p')
		i += print_pointer((unsigned long long)va_arg(args, void *), 16);
	else if (*input == 'd' || *input == 'i')
		i += print_int(va_arg(args, int));
	else if (*input == 'u')
		i += print_unsigned(va_arg(args, unsigned int));
	else if (*input == 'x')
		i += print_hex(va_arg(args, unsigned int), 16);
	else if (*input == 'X')
		i += print_hex(va_arg(args, unsigned int), 16);
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
				i += check_arg(input, args);
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
int main(void)
{
    int n = 42;
    unsigned int un = -42;
    char c = 'a';
    char *s = "a";
    char *ptr = "Test";
    int plen1 = 0, plen2 = 0;
    int slen1 = 0, slen2 = 0;
    //---------------------------------------------------------------------//
    // Test Pointer:
    plen1 = ft_printf("%p \n\033[0m", s);
    plen2 = printf("%p \n\033[0m", s);
    printf("\033[0;32mprintf devolvió: %d\n\033[0m", plen2);
    printf("\033[0;33mft_printf devolvió: %d\n\033[0m", plen1);
    //---------------------------------------------------------------------//

    
    // len1 = ft_printf("\033[0;32mTest Mix: %c %s %d %i %u %x %X %p %%\n\033[0m", c, s, n, n, un, n, n, s);
    // rlen2 = printf("\033[0;32mTest Mix: %c %s %d %i %u %x %X %p %%\n\033[0m", c, s, n, n, un, n, n, s);

    
    // printf("\n\n");
    // // Test 2: Char
    // rlen1 = ft_printf("\033[0;33mTest char: %c\n\033[0m", 'A');
    // rlen2 = printf("\033[0;32mTest char: %c\n\033[0m", 'A');
    // printf("\033[0;33mft_printf devolvió: %d\n\033[0m", rlen1);
    // printf("\033[0;32mprintf devolvió: %d\n\033[0m", rlen2);
    // printf("\n\n");
    // // Test 3: String
    // rlen1 = ft_printf("\033[0;33mTest string: %s\n\033[0m", "mundo");
    // rlen2 = printf("\033[0;32mTest string: %s\n\033[0m", "mundo");
    // printf("\033[0;33mft_printf devolvió: %d\n\033[0m", rlen1);
    // printf("\033[0;32mprintf devolvió: %d\n\033[0m", rlen2);
    // printf("\n\n");
    // // Test 4: Hex minusculas
    // rlen1 = ft_printf("\033[0;33mTest hex: %x\n\033[0m", 25555555);
    // rlen2 = printf("\033[0;32mTest hex: %x\n\033[0m", 25555555);
    // printf("\033[0;33mft_printf devolvió: %d\n\033[0m", rlen1);
    // printf("\033[0;32mprintf devolvió: %d\n\033[0m", rlen2);
    // printf("\n\n");
    // // Test 5: Puntero
    // rlen1 = ft_printf("\033[0;33mTest ptr: %p\n\033[0m", ptr);
    // rlen2 = printf("\033[0;32mTest ptr: %p\n\033[0m", ptr);
    // printf("\033[0;33mft_printf devolvió: %d\n\033[0m", rlen1);
    // printf("\033[0;32mprintf devolvió: %d\n\033[0m", rlen2);
    // printf("\n\n");
    // // Test 6: Hex mayusculas
    // rlen1 = ft_printf("\033[0;33mTest HEX: %X\n\033[0m", 255);
    // rlen2 = printf("\033[0;32mTest HEX: %X\n\033[0m", 255);
    // printf("\033[0;33mft_printf devolvió: %d\n\033[0m", rlen1);
    // printf("\033[0;32mprintf devolvió: %d\n\033[0m", rlen2);
    // printf("\n\n");
    // // Test 7: Decimal
    // rlen1 = ft_printf("\033[0;33mTest dec: %d\n\033[0m", 777);
    // rlen2 = printf("\033[0;32mTest dec: %d\n\033[0m", 777);
    // printf("\033[0;33mft_printf devolvió: %d\n\033[0m", rlen1);
    // printf("\033[0;32mprintf devolvió: %d\n\033[0m", rlen2);
    // printf("\n\n");
    // // Test 8: Int
    // rlen1 = ft_printf("\033[0;33mTest int: %i\n\033[0m", 777);
    // rlen2 = printf("\033[0;32mTest int: %i\n\033[0m", 777);
    // printf("\033[0;33mft_printf devolvió: %d\n\033[0m", rlen1);
    // printf("\033[0;32mprintf devolvió: %d\n\033[0m", rlen2);
    // printf("\n\n");
    // // Test 9: Unsigned int
    // rlen1 = ft_printf("\033[0;33mTest uns: %u\n\033[0m", -0);
    // rlen2 = printf("\033[0;32mTest uns: %u\n\033[0m", -0);
    // printf("\033[0;33mft_printf devolvió: %d\n\033[0m", rlen1);
    // printf("\033[0;32mprintf devolvió: %d\n\033[0m", rlen2);
    // printf("\n\n");
    // // Test 10: Porcentaje
    // rlen1 = ft_printf("\033[0;33mTest porcentaje: %%\n\033[0m");
    // rlen2 = printf("\033[0;32mTest porcentaje: %%\n\033[0m");
    // printf("\033[0;33mft_printf devolvió: %d\n\033[0m", rlen1);
    // printf("\033[0;32mprintf devolvió: %d\n\033[0m", rlen2);
    // printf("\n\n");
    // // Test 11: Locura
    // rlen1 = ft_printf("\033[0;33mTest locura: %%%c%%%s%%%d%%%i%%%u%%%x%%%X%%%% %%%c%%%s%%%d%%%i%%%u%%%x%%%X%%%% %%%c%%%s%%%d%%%i%%%u%%%x%%%X%%%% %c%%\n\033[0m", 'A', "42", 42, 42 ,42 , 42, 42, 'B', "-42", -42, -42 ,-42 ,-42, 42, 'C', "0", 0, 0 ,0 ,0, 42, 0);
    // rlen2 = printf   ("\033[0;32mtest locura: %%%c%%%s%%%d%%%i%%%u%%%x%%%X%%%% %%%c%%%s%%%d%%%i%%%u%%%x%%%X%%%% %%%c%%%s%%%d%%%i%%%u%%%x%%%X%%%% %c%%\n\033[0m", 'A', "42", 42, 42 ,42 , 42, 42, 'B', "-42", -42, -42 ,-42 ,-42, 42, 'C', "0", 0, 0 ,0 ,0, 42, 0);
    // printf("\033[0;33mft_printf devolvió: %d\n\033[0m", rlen1);
    // printf("\033[0;32mprintf devolvió: %d\n\033[0m", rlen2);
    // printf("\n\n");
    // rlen1 = ft_printf("\033[0;33mTest locura:%c%s%d%i%u%x\n\033[0m", 'B', "-42", -42, -42 ,-42 ,-42);
    // rlen2 = printf   ("\033[0;32mtest locura:%c%s%d%i%u%x\n\033[0m", 'B', "-42", -42, -42 ,-42 ,-42);
    // printf("\033[0;33mft_printf devolvió: %d\n\033[0m", rlen1);
    // printf("\033[0;32mprintf devolvió: %d\n\033[0m", rlen2);
    // printf("\n\n");
    return 0;
}