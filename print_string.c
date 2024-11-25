/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_string.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmazo-ga <dmazo-ga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 11:45:25 by marvin            #+#    #+#             */
/*   Updated: 2024/11/25 19:15:13 by dmazo-ga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_string(char *s)
{
	if (!s)
	{
		ft_putstr_fd("(null)", 1);
		return (6);
	}
	int len = ft_strlen(s);
	ft_putstr_fd(s, 1);
	return (len);
}
// int main(void)
// {
// 	int len = ("damian");
// 	printf("longitud de cadena %d\n", len);
// 	return(0);
// }