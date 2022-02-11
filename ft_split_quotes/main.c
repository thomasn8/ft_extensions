/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnanchen <thomasnanchen@hotmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/31 18:58:56 by tnanchen          #+#    #+#             */
/*   Updated: 2022/01/31 19:25:43 by tnanchen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
#define RED "\033[0;31m"
#define YEL "\033[0;33m"
#define BLU "\033[0;34m"
#define WHI "\033[0m"

static char	*word_dup(const char *str, int word_n, int start, int end)
{
	char	*word;
	int		i;

	i = 0;
	if (start == end && !word_n)
		return (NULL);
	word = malloc((end - start + 1) * sizeof(char));
	while (start < end)
		word[i++] = str[start++];
	word[i] = 0;
	return (word);
}

static int	quotes(char a, char *quote)
{
	if (*quote == '0' && (a == '\'' || a == '\"'))
		*quote = a;
	else if (*quote != '0' && a == *quote)
		*quote = '0';
	return (1);
}

static int	words_count(const char *str, char c)
{
	int		i;
	int		limiter;
	char	quote;

	i = 0;
	limiter = 0;
	quote = '0';
	while (*str)
	{
		quotes(*str, &quote);
		if (*str != c && limiter == 0)
		{
			limiter = 1;
			i++;
		}
		else if (*str == c && quote == '0')
			limiter = 0;
		str++;
	}
	return (i);
}

static char	**words_split(char **tab, char const *s, char c)
{
	int		i;
	int		start;
	int		end;
	int		word;
	char	quote;

	i = 0;
	start = 0;
	end = 0;
	word = 0;
	quote = '0';
	while (s[i])
	{
		while (s[i] == c && quotes(s[i], &quote) && quote == '0')
			i++;
		start = i;
		while (s[i] && ((s[i] != c && quotes(s[i], &quote)) || quote != '0'))
			i++;
		end = i;
		if (!s[i] && start == end && word > 0)
			return (tab);
		tab[word] = word_dup(s, word, start, end);
		word++;
	}
	return (tab);
}

char	**ft_split_quotes(char const *s, char c)
{
	char	**tab;
	size_t	words;

	if (!s)
		return (0);
	words = words_count(s, c);
	tab = malloc((words + 1) * sizeof(char *));
	if (!tab)
		return (0);
	if (!(words_split(tab, s, c)))
	{
		free(tab);
		return (NULL);
	}
	tab[words] = NULL;
	return (tab);
}

int	main(int ac, char **av)
{
	char	**str_split;
	int		i;
	
	if (ac == 3)
	{
		str_split = ft_split_quotes(av[ac - 2], *av[ac-1]);
		i = -1;
		while (str_split[++i])
			printf("string %d: %s\n", i + 1, str_split[i]);
	}
	else
	{
		printf("usage: 	 ./a.out string_to_split delimiter\n");
		printf("example:%s ./a.out %s'a string with quotes|to split in 3 (not in 4)|using \"|\" like delimiter'%s '|'%s\n", YEL, BLU, RED, WHI);
	}
	return (0);
}
