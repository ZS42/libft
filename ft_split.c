/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zsyyida <zsyyida@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/23 09:36:19 by zsyyida           #+#    #+#             */
/*   Updated: 2021/10/24 11:23:52 by zsyyida          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_cntwrd(char const *s, char c)
{
	unsigned int	i;
	int				cnt_wrd;

	i = 0;
	cnt_wrd = 0;
	while (s[i])
	{
		if ((s[i + 1] == c || s[i + 1] == '\0')
			&& (!(s[i] == c || s[i] == '\0')))
		{
			cnt_wrd++;
		}
		i++;
	}
	return (cnt_wrd);
}

static int	ft_wrd_len(char const *s, char c)
{
	int	len;

	len = 0;
	while (*s && *s != c)
	{
		len++;
		s++;
	}
	return (len);
}

static char	*ft_strndup( char const *s, int len)
{
	char	*word;
	int		i;

	i = 0;
	word = (char *)malloc(sizeof(char) * (len + 1));
	if (!word)
		return (NULL);
	while (i < len)
	{
		word[i] = s[i];
		i++;
	}
	word[i] = '\0';
	return (word);
}

static void	ft_free_str(char **s, int i)
{
	if (!s)
	{
		while (i-- != 0)
			free(s[i]);
		free(s);
	}
}

char	**ft_split(char const *s, char c)
{
	int		wrd_len;
	int		wrd_cnt;
	int		i;
	char	**result;

	i = 0;
	if (!s)
		return (NULL);
	wrd_cnt = ft_cntwrd(s, c);
	result = (char **)malloc(sizeof(char *) * (wrd_cnt + 1));
	if (result == NULL)
		return (NULL);
	while (wrd_cnt > i)
	{
		while (*s == c && *s)
			s++;
		wrd_len = ft_wrd_len(s, c);
		result[i] = ft_strndup(s, wrd_len);
		ft_free_str(result, wrd_cnt - 1);
		s = s + wrd_len;
		i++;
	}
	result[i] = NULL;
	return (result);
}
