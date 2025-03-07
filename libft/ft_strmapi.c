/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alejaro2 <alejaro2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 19:13:04 by alejaro2          #+#    #+#             */
/*   Updated: 2024/10/17 17:51:26 by alejaro2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	size_t	len;
	char	*new_mem;
	size_t	i;

	len = ft_strlen(s);
	new_mem = (char *)malloc(len + 1);
	if (!new_mem)
		return (NULL);
	new_mem[len] = '\0';
	i = 0;
	while (i < len)
	{
		new_mem[i] = f(i, s[i]);
		i++;
	}
	return (new_mem);
}

/*int	main(void)
{
	char p[] = "hola";
	printf("cambio: %s", ft_strmapi(p, first_toupper));
}*/