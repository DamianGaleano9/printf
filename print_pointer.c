/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_pointer.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmazo-ga <dmazo-ga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 09:48:54 by damian            #+#    #+#             */
/*   Updated: 2024/11/26 19:05:18 by dmazo-ga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char	*new_string(unsigned long val, int *strlen)
{
	int					i;
	unsigned long		tmp;
	char				*str;

	i = 0;
	tmp = val;
	while (tmp != 0)
	{
		tmp = tmp / 16;
		i++;
	}
	str = calloc(i + 1, sizeof(char));
	*strlen = i;
	return (str);
}

int	print_pointer(unsigned long val, int asc)
{
	unsigned long		tempointer;
	char				*print_str;
	int					i;
	int					*len_str;

	len_str = &i;
	tempointer = val;
	print_str = new_string(val, len_str);
	if (!print_str)
			return (0); i--;
	while (tempointer != 0 && i-- >= 0)
	{
		if ((tempointer % 16) < 10)
			print_str[i + 1] = (tempointer % 16) + '0';
		else
			print_str[i + 1] = (tempointer % 16) -10 + 'a';
		tempointer = tempointer / 16;
	}
	i = ft_strlen(print_str);
	i = i + print_string("0x");
	ft_putstr_fd(print_str, 1);
	free(print_str);
	if (val == 0)
		i += print_char('0');
	return (i);
}

// int main(void)
// {
//     void *ptr = (void*)0x12345678;

//     // Test 5: Puntero
//     int rlen1 = ft_printf("\033[0;33mTest ptr: %p\n\033[0m", ptr);  // Llamada a ft_printf
//     int rlen2 = printf("\033[0;32mTest ptr: %p\n\033[0m", ptr);      // Llamada a printf

//     printf("\033[0;33mft_printf devolvió: %d\n\033[0m", rlen1);      // Resultado de ft_printf
//     printf("\033[0;32mprintf devolvió: %d\n\033[0m", rlen2);        // Resultado de printf
//     printf("\n\n");

//     return 0;
// }


// int main(void)
// {
//     unsigned long test_val_1 = 0x1A3F;
//     unsigned long test_val_2 = 0;
//     unsigned long test_val_3 = 0xFFFFFFFFFFFFFF;
//     unsigned long test_val_4 = 0xABCDEF;
// 	unsigned long num = 99;
// 	unsigned long num1 = 9;
// 	unsigned long num2 = 109;
// 	unsigned long num3 = 9999;


//     // Prueba 1: Valor hexadecimal común
//     printf("Test 1: ");
//     int len1 = print_pointer(test_val_1, 'a');  // 'a' para minúsculas
//     printf(" (Length: %d)\n", len1);

//     // Prueba 2: Valor 0
//     printf("Test 2: ");
//     int len2 = print_pointer(test_val_2, 'a');  // 0 debe dar "0x0"
//     printf(" (Length: %d)\n", len2);

//     // Prueba 3: Valor hexadecimal grande
//     printf("Test 3: ");
//     int len3 = print_pointer(test_val_3, 'a');  // un valor grande
//     printf(" (Length: %d)\n", len3);

//     // Prueba 4: Otro valor hexadecimal
//     printf("Test 4: ");
//     int len4 = print_pointer(test_val_4, 'a');  // 'a' para minúsculas
//     printf(" (Length: %d)\n", len4);

//     // Prueba con 'A' para mayúsculas
//     printf("Test 5: ");
//     int len5 = print_pointer(test_val_1, 'A');  // 'A' para mayúsculas
//     printf(" (Length: %d)\n", len5);

// 	int result = print_pointer(num, 'a');
// 	printf("mi num is : %lu\n", num);

// 	int result1 = print_pointer(num1, 'a');
// 	printf("mi num is : %lu\n", num1);

// 	int result2 = print_pointer(num2, 'a');
// 	printf("mi num is : %lu\n", num2);

// 	int result3 = print_pointer(num3, 'a');
// 	printf("mi num is : %lu\n", num3);

//     return 0;
// }

