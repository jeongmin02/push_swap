#include "push_swap.h"
#include <stdlib.h>

static int	count_word(char const *s, char c)
{
	int	cnt;
	int	i;

	cnt = 0;
	i = 0;
	while (s[i])
	{
		while (s[i] && s[i] == c)
			i++;
		if (s[i] == '\0')
			break ;
		while (s[i] && s[i] != c)
			i++;
		cnt++;
	}
	return (cnt);
}

static int	word_len(char const *s, char c, int i)
{
	int	len;

	len = 0;
	while (s[i] && s[i] != c)
	{
		len++;
		i++;
	}
	return (len);
}

static char	*fill_word(char const *s, char c, int i)
{
	int		j;
	char	*word;

	word = (char *)malloc(sizeof(char) * (word_len(s, c, i) + 1));
	if (!word)
		return (NULL);
	j = 0;
	while (s[i] && s[i] != c)
	{
		word[j] = s[i];
		j++;
		i++;
	}
	word[j] = '\0';
	return (word);
}

static void	free_split(char **res, int x)
{
	while (x >= 0)
	{
		free (res[x]);
		x--;
	}
	free(res);
}	

char	**ft_split(char const *s, char c)
{
	char	**res;
	int		x;
	int		i;

	if (!s)
		return (NULL);
	res = (char **)malloc(sizeof(char *) * (count_word(s, c) + 1));
	if (!res)
		return (NULL);
	x = 0;
	i = 0;
	while (x < count_word(s, c))
	{
		while (s[i] && s[i] == c)
			i++;
		res[x] = fill_word(s, c, i);
		if (!res[x])
			free_split(res, x - 1);
		i += word_len(s, c, i);
		x++;
	}
	res[x] = NULL;
	return (res);
}
