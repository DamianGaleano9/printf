/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_hex.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmazo-ga <dmazo-ga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 11:38:43 by marvin            #+#    #+#             */
/*   Updated: 2024/11/28 16:24:09 by dmazo-ga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char	*new_string(unsigned int val, int *strlen)
{
	int					i;
	unsigned int		tmp;
	char				*str;

	i = 0;
	tmp = val;
	   if (val == 0)
    {
        *strlen = 1;
        str = calloc(2, sizeof(char));
        if (!str) return NULL;
        str[0] = '0';
        str[1] = '\0';
        return str;
    }

	while (tmp != 0)
	{
		tmp = tmp / 16;
		i++;
	}
	str = calloc(i + 1, sizeof(char));
	if (!str) return (NULL);
	*strlen = i;
	return (str);
}

int	print_hex(unsigned int val, int asci)
{
	unsigned int	tmp_hexa;
	char			*hex_str;
	int				i;
	int				*len_str;
	char			base_char;

	i = 0;
	len_str = &i;
	tmp_hexa = val;
	hex_str = new_string(val, len_str);
	if (!hex_str) return (0);
	if (asci == 'a')
		base_char = 'a';
	else 
		base_char = 'A';
	i = *len_str - 1;
	while (tmp_hexa != 0)
	{
		if ((tmp_hexa % 16) < 10)
			hex_str[i] = tmp_hexa % 16 + '0';
		else
			hex_str[i] = (tmp_hexa % 16 - 10) + base_char;
		tmp_hexa = tmp_hexa / 16;
		i--;
	}
	ft_putstr_fd(hex_str, 1);
	i = ft_strlen(hex_str);
	free(hex_str);
	return i;
}
// int main(void)
// {
// 	int rlen1;
// 	int rlen2;
// 	 // Test 6: Hex mayusculas
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


// int main() {

//     Caso 1: valor 0
//     printf("Hexadecimal de 0: ");
//     print_hex(0, 'a');  // Imprime '0' en minúsculas
//     printf("\n");

//     Caso 2: valor positivo pequeño
//     printf("Hexadecimal de 42 : ");
//     print_hex(42, 'a');  // Debería imprimir '2a'
//     printf("\n");

//     Caso 3: valor grande
//     printf("Hexadecimal de 255: ");
//     print_hex(255, 'a');  // Debería imprimir 'ff'
//     printf("\n");

//     Caso 4: valor con letras en mayúsculas
//     printf("Hexadecimal de 255 con mayúsculas: ");
//     print_hex(255, 'A');  // Debería imprimir 'FF'
//     printf("\n");

//     Caso 5: valor con letras en minúsculas
//     printf("Hexadecimal de 255 con minúsculas: ");
//     print_hex(255, 'a');  // Debería imprimir 'ff'
//     printf("\n");

//     return 0;
// }
