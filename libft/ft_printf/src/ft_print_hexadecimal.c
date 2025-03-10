/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_hexadecimal.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alejaro2 <alejaro2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 17:32:54 by alejaro2          #+#    #+#             */
/*   Updated: 2025/03/10 09:42:28 by alejaro2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_hexadecimal(size_t n, char c)
{
	int		count;
	char	*base;

	base = "0123456789abcdef";
	count = 0;
	if (c == 'X')
		base = "0123456789ABCDEF";
	if (n >= 16)
		count += ft_print_hexadecimal((n / 16), c);
	count += ft_print_char(base[n % 16]);
	return (count);
}
