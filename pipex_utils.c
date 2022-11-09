/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: icarboni <icarboni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/19 18:58:27 by icarboni          #+#    #+#             */
/*   Updated: 2022/11/08 11:32:33 by icarboni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/pipex.h"
#include "./libft/libft.h"

int	ft_strstr(char *str, char *to_find)
{
	int i;
	int j;

	i = 0;
	while (str[i] != '\0')
	{
		j = 0;
		while (str[i + j] != '\0' && str[i + j] == to_find[j])
		{
			if (to_find[j + 1] == '\0')
				return (1);
			++j;
		}
		++i;
	}
	return (0);
}

void	ft_putstr_error(char *s, char *t)
{
	if (!s)
		return ;
	if (t)
	{
		write(2, "-bash: ", 7);
		write(2, t, ft_strlen(t));
		write(2, ": ", 2);
	}
	while (*s)
	{
		write(2, &(*s), 1);
		s++;
	}
	write(2, "\n", 1);
}

char **ft_clean_args(char **args)
{
	int i;
	int j;

	i = 1;
	j = 0;
	while(args[i])
	{
		while(args[i][j])
			j++;
		//printf("%s", args[i]);
		if (args[i][0] == '"' && args[i][j - 1] == '"')
			args[i]++;
			args[i][j - 2] = 0;
		//printf("%s", args[i]);
		i++;
	}
	return (args);
}