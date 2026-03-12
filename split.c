/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchakir <mchakir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/14 21:38:16 by mchakir           #+#    #+#             */
/*   Updated: 2026/03/12 03:05:04 by mchakir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* #include "push_swap.h"

static int	count_words(char *str, char separator)
{
	int		count;
	bool	inside_word;

	count = 0;
	while (*str)
	{
		inside_word = false;
		while (*str == separator && *str)
			++str;
		while (*str != separator && *str)
		{
			if (!inside_word)
			{
				++count;
				inside_word = true;
			}
			++str;
		}
	}
	return (count);
}

static char	*get_next_word(char *str, char separator)
{
	static int	cursor = 0;
	char		*next_str;
	int			len;
	int			i;

	len = 0;
	i = 0;
	while (str[cursor] == separator)
		++cursor;
	while ((str[cursor + len] != separator) && str[cursor + len])
		++len;
	next_str = malloc((size_t)len * sizeof(char) + 1);
	if (NULL == next_str)
		return (NULL);
	while ((str[cursor] != separator) && str[cursor])
		next_str[i++] = str[cursor++];
	next_str[i] = '\0';
	return (next_str);
}

char	**ft_split(char *str, char separator)
{
	int		words_number;
	char	**vector_strings;
	int		i;

	i = 0;
	words_number = count_words(str, separator);
	if (!words_number)
		return (NULL);
	vector_strings = malloc(sizeof(char *) * (size_t)(words_number + 2));
	if (NULL == vector_strings)
		return (NULL);
	while (words_number-- >= 0)
	{
		if (0 == i)
		{
			vector_strings[i] = malloc(sizeof(char));
			if (NULL == vector_strings[i])
				return (NULL);
			vector_strings[i++][0] = '\0';
			continue ;
		}
		vector_strings[i++] = get_next_word(str, separator);
	}
	vector_strings[i] = NULL;
	return (vector_strings);
}
 */


#include "push_swap.h"
size_t ft_strlen(const char *s)
{
   int i;

   i = 0;
   while (*s++)
	   i++;
   return (i);
}

static size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
   size_t	i;

   i = 0;
   if (size == 0)
	   return (ft_strlen(src));
   while (i < size - 1 && src[i])
   {
	   dst[i] = src[i];
	   i++;
   }
   if (size > 0)
	   dst[i] = '\0';
   return (ft_strlen(src));
}

static char	**mem_free(char **poof)
{
	int	i;

	i = 0;
	if (!poof)
		return (NULL);
	while (poof[i])
	{
		free(poof[i]);
		i++;
	}
	free(poof);
	return (NULL);
}

static size_t	count_words(const char *str, char sep)
{
	int	i;
	int	words;

	i = 0;
	words = 0;
	while (str[i])
	{
		while (str[i] && (str[i] == sep))
			i++;
		if (str[i])
			words++;
		while (str[i] && !(str[i] == sep))
			i++;
	}
	return (words);
}

static void	locate_words(char **cursor, size_t *word_len, char sep)
{
	size_t	i;

	*cursor += *word_len;
	*word_len = 0;
	i = 0;
	while (**cursor && **cursor == sep)
		(*cursor)++;
	while ((*cursor)[i])
	{
		if ((*cursor)[i] == sep)
			return ;
		(*word_len)++;
		i++;
	}
}

void	free_split(char **args)
{
	int	i;

	if (!args)
		return ;
	i = 0;
	while (args[i])
	{
		free(args[i]);
		i++;
	}
	free(args);
}

char	**ft_split(const char *str, char sep)
{
	char	**result;
	char	*cursor;
	size_t	word_len;
	size_t	i;

	if (!str)
		return (NULL);
	result = malloc(sizeof(char *) * (count_words(str, sep) + 1));
	if (!result)
		return (NULL);
	i = 0;
	cursor = (char *)str;
	word_len = 0;
	while (i < count_words(str, sep))
	{
		locate_words(&cursor, &word_len, sep);
		result[i] = malloc(sizeof(char) * (word_len + 1));
		if (!result[i])
			return (mem_free(result));
		ft_strlcpy(result[i], cursor, word_len + 1);
		i++;
	}
	result[i] = NULL;
	return (result);
}

