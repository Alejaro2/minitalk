/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alejaro2 <alejaro2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/13 13:41:01 by alejaro2          #+#    #+#             */
/*   Updated: 2025/03/06 12:50:36 by alejaro2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	free_memory(char **result, int i_word)
{
	while (i_word > 0)
		free(result[--i_word]);
	free(result);
}

static int	ft_contador(char const *s, char c)
{
	int	i;
	int	cont;

	i = 0;
	cont = 0;
	while (s[i] != '\0')
	{
		if (s[i] == c)
			i++;
		else
		{
			cont++;
			while (s[i] != c && s[i] != '\0')
				i++;
		}
	}
	return (cont);
}

static char	**new_words(char **result, char const *s, char c)
{
	int	i;
	int	start;
	int	i_word;

	i = 0;
	i_word = 0;
	while (s[i])
	{
		while (s[i] == c)
			i++;
		start = i;
		while (s[i] && s[i] != c)
			i++;
		if (start < i)
		{
			result[i_word] = ft_substr(s, start, i - start);
			if (result[i_word] == NULL)
				return (NULL);
			i_word++;
		}
	}
	result[i_word] = NULL;
	return (result);
}

char	**ft_split(char const *s, char c)
{
	char	**result;
	int		c_words;

	c_words = ft_contador(s, c);
	result = (char **)ft_calloc((c_words + 1), sizeof(char *));
	if (!result)
		return (NULL);
	if (new_words(result, s, c) == NULL)
	{
		free_memory(result, c_words);
		return (NULL);
	}
	return (result);
}

/*int	main(void)
{
	char s[] = "hola como estas bien";
	char c = ' ';
	char **res = ft_split(s, c);
	
	if (res != NULL)
	{
		int i = 0;
		while (res[i])
		{
			printf("%s\n", res[i]);
			i++;
		}
	}
}*/