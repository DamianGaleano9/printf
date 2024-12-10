/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_hexa.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmazo-ga <dmazo-ga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 10:31:43 by dmazo-ga          #+#    #+#             */
/*   Updated: 2024/12/09 18:50:39 by dmazo-ga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_hexa(unsigned long n, char const arg)
{
	int		len;

	len = 0;
	if (n >= 16)
		len += ft_print_hexa (n / 16, arg);
	if ((n % 16) <= 9)
		len += ft_print_char ((n % 16) + '0');
	else if (arg == 'x' && (n % 16) > 9 && (n % 16) < 16)
		len += ft_print_char ((n % 16) - 10 + 'a');
	else if (arg == 'X' && (n % 16) > 9 && (n % 16) < 16)
		len += ft_print_char ((n % 16) - 10 + 'A');
	return (len);
}
// int main(void)
// {
// 	int rlen1;
// 	int rlen2;
// 	//  Test 6: Hex mayusculas
//     rlen1 = ft_printf("\033[0;33mTest HEX: %X\n\033[0m", 255);
//     rlen2 = printf("\033[0;32mTest HEX: %X\n\033[0m", 255);
//     printf("\033[0;33mft_printf devolvió: %d\n\033[0m", rlen1);
//     printf("\033[0;32mprintf devolvió: %d\n\033[0m", rlen2);
//     printf("\n\n");

// 	    // Test 4: Hex minusculas
//     rlen1 = ft_printf("\033[0;33mTest hex: %x\n\033[0m", 25555555);
//     rlen2 = printf("\033[0;32mTest hex: %x\n\033[0m", 25555555);
//     printf("\033[0;33mft_printf devolvió: %d\n\033[0m", rlen1);
//     printf("\033[0;32mprintf devolvió: %d\n\033[0m", rlen2);
//     printf("\n\n");
// 	return (0);
// }

/* int main() {

    // Caso 1: valor 0
    printf("Hexadecimal de 0: ");
    ft_print_hexa(0, 'a');  // Imprime '0' en minúsculas
    printf("\n");

    // Caso 2: valor positivo pequeño
    printf("Hexadecimal de 42 : ");
    ft_print_hexa(42, 'a');  // Debería imprimir '2a'
    printf("\n");

    // Caso 3: valor grande
    printf("Hexadecimal de 255: ");
    ft_print_hexa(255, 'a');  // Debería imprimir 'ff'
    printf("\n");

    // Caso 4: valor con letras en mayúsculas
    printf("Hexadecimal de 255 con mayúsculas: ");
    ft_print_hexa(255, 'A');  // Debería imprimir 'FF'
    printf("\n");

    // Caso 5: valor con letras en minúsculas
    printf("Hexadecimal de 255 con minúsculas: ");
    ft_print_hexa(255, 'a');  // Debería imprimir 'ff'
    printf("\n");

    return 0;
} */