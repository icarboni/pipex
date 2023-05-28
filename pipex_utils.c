/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: icarboni <icarboni@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/19 18:58:27 by icarboni          #+#    #+#             */
/*   Updated: 2022/11/30 17:37:28 by icarboni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/pipex.h"
#include "./libft/libft.h"

int	ft_strstr(char *str, char *to_find)
{
	int	i;
	int	j;

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
		write(2, "- Pipex: ", 9);
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

char	**ft_env_parse(char **envp)
{
	char	*path_from_envp;
	char	**mypaths;
	int		i;

	i = 0;
	while (envp[i] != 0)
	{
		if (ft_strstr(envp[i], "PATH") != '\0')
			path_from_envp = envp[i];
		i++;
	}
	path_from_envp = ft_substr(path_from_envp, 5, ft_strlen(path_from_envp));
	mypaths = ft_split(path_from_envp, ':');
	return (mypaths);
}

char	*ft_get_path(t_pipex pipex)
{
	int		i;
	char	*command;
	char	*command2;

	i = -1;
	while (pipex.paths[++i])
	{
		command = ft_strjoin(pipex.paths[i], "/");
		command2 = ft_strjoin(command, pipex.cmd);
		free(command);
		if (access(command2, 0) == 0)
			return (command2);
		free(command2);
	}
	exit(1);
}
