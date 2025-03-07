/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alejaro2 <alejaro2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/11 17:58:56 by alejaro2          #+#    #+#             */
/*   Updated: 2024/10/16 21:35:10 by alejaro2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	size_t	str_len;
	char	*new;

	str_len = ft_strlen(s);
	if (!s || start >= str_len)
		return (ft_strdup(""));
	if (len > str_len - start)
		len = str_len - start;
	new = malloc(len + 1);
	if (!new)
		return (NULL);
	i = 0;
	while (i < len)
	{
		new[i] = s[start];
		i++;
		start++;
	}
	new[i] = '\0';
	return (new);
}

/*int main(void)
{
	char salu[] = "hola buenos dias";
	int d = 5;
	printf("substring: %s", ft_substr(salu, d, 17));
}*/