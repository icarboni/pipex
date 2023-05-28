/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: icarboni <icarboni@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 20:13:48 by icarboni          #+#    #+#             */
/*   Updated: 2022/11/15 20:23:38 by icarboni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/pipex.h"
#include "./libft/libft.h"

int	ft_free_parser(char **res, int created)
{
	int	w;

	w = created;
	while (w >= 0)
	{
		free(res[w]);
		res[w] = NULL;
		w--;
	}
	free(res);
	res = 0;
	return (0);
}

int	ft_if_quot(t_parser *p, int *index, char **res)
{
	p->next = ft_find_other(*p, p->i, p->str[p->i]);
	if (p->next > 0)
	{
		p->i++;
		res[p->w] = word_dup_parser(*p, p->i, p->i + p->next);
		if (res[p->w++] == NULL)
			return (ft_free_parser(res, --p->w));
		*index = -1;
		p->i = p->i + p->next + 2;
	}
	return (1);
}

int	ft_find_other(t_parser p, int in, char c)
{
	int	i;

	i = in + 1;
	while (p.str[i] != c && p.str[i])
		i++;
	if (p.str[i] == c)
		return (i - in - 1);
	return (0);
}
