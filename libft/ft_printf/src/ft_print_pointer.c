/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_pointer.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alejaro2 <alejaro2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 17:33:08 by alejaro2          #+#    #+#             */
/*   Updated: 2024/11/26 19:32:53 by alejaro2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_pointer(void *c)
{
	int		count;
	size_t	n;

	count = 0;
	if (c == 0)
		count += ft_print_str("(nil)");
	else
	{
		count += ft_print_str("0x");
		n = (size_t)c;
		count += ft_print_hexadecimal(n, 'x');
	}
	return (count);
}
