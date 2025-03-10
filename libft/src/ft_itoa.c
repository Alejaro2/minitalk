/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alejaro2 <alejaro2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 16:44:26 by alejaro2          #+#    #+#             */
/*   Updated: 2024/10/17 21:33:54 by alejaro2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	count_w(int n)
{
	int	count;

	count = 0;
	if (n == 0)
		return (1);
	if (n < 0)
	{
		n = -n;
		count++;
	}
	while (n != 0)
	{
		n = n / 10;
		count++;
	}
	return (count);
}

char	*ft_itoa(int n)
{
	char	*new;
	int		len;

	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	len = count_w(n);
	new = (char *)malloc(len + 1);
	if (!new)
		return (NULL);
	new[len--] = '\0';
	if (n == 0)
		new[0] = '0';
	if (n < 0)
	{
		new[0] = '-';
		n = -n;
	}
	while (n > 0)
	{
		new[len--] = (n % 10) + '0';
		n = n / 10;
	}
	return (new);
}
