/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: icarboni <icarboni@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 18:19:09 by icarboni          #+#    #+#             */
/*   Updated: 2022/11/15 20:23:18 by icarboni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/pipex.h"
#include "./libft/libft.h"

void	ft_words_count_parser(t_parser *p, char c)
{
	int	end;
	int	i;

	end = 0;
	i = 0;
	while (p->str[i])
	{
		if (end == 0 && (p->str[i] == '\"' || p->str[i] == '\''))
		{
			p->next = ft_find_other(*p, i, p->str[i]);
			if (p->next > 0)
			{
				i += (p->next + 2);
				p->words++;
			}
		}
		if (p->str[i] != c && end == 0)
		{
			end = 1;
			p->words++;
		}
		else if (p->str[i] == c)
			end = 0;
		i++;
	}
}

char	*word_dup_parser(t_parser p, int start, int finish)
{
	char	*word;
	int		i;

	i = 0;
	word = (char *)malloc((finish - start + 1) * sizeof(char));
	if (word != NULL)
	{
		while (start < finish)
			word[i++] = p.str[start++];
		word[i] = '\0';
		return (word);
	}
	else
		return (NULL);
}

int	ft_exe_parser(t_parser p, char **res)
{
	int		index;

	index = -1;
	while (p.i <= p.len)
	{	
		if ((index < 0) && (p.str[p.i] == '\"' || p.str[p.i] == '\''))
		{
			if (ft_if_quot(&p, &index, res) == 0)
				return (0);
		}
		else if (p.str[p.i] != p.sep && index < 0)
			index = p.i;
		else if ((p.str[p.i] == p.sep | p.i == p.len) && index >= 0)
		{
			res[p.w] = word_dup_parser(p, index, p.i);
			if (res[p.w++] == NULL)
				return (ft_free_parser(res, --p.w));
			index = -1;
		}
		p.i++;
	}
	res[p.w] = 0;
	return (1);
}

char	**ft_parser(char *s, char c)
{
	char		**res;
	t_parser	p;

	p.str = s;
	p.sep = c;
	p.words = 1;
	ft_words_count_parser(&p, c);
	p.len = ft_strlen(s);
	p.i = 0;
	p.w = 0;
	res = (char **)malloc(p.words * sizeof(char *));
	if (!s || !res)
		return (0);
	if (ft_exe_parser(p, res) == 0)
		return (NULL);
	return (res);
}
