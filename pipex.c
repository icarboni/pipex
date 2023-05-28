/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: icarboni <icarboni@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/18 20:12:59 by icarboni          #+#    #+#             */
/*   Updated: 2022/11/15 20:29:02 by icarboni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/pipex.h"
#include "./libft/libft.h"

void	ft_execute(t_pipex pipex, char *full_cmd, char **envp)
{
	int		d;

	pipex.args = ft_parser(full_cmd, ' ');
	pipex.cmd = pipex.args[0];
	pipex.paths = ft_env_parse(envp);
	pipex.cmd_path = ft_get_path(pipex);
	if (pipex.cmd_path == NULL)
		exit(EXIT_FAILURE);
	d = execve(pipex.cmd_path, pipex.args, envp);
	if (d == -1)
	{
		ft_putstr_error(strerror(errno), "execve");
		exit(1);
	}
}

void	ft_child1(t_pipex pipex, char **argv, char **envp)
{
	int		d;

	d = dup2(pipex.infile, STDIN_FILENO);
	if (d < 0)
		exit(1);
	d = dup2(pipex.pip[1], STDOUT_FILENO);
	if (d < 0)
		exit(1);
	close(pipex.pip[0]);
	ft_execute(pipex, argv[2], envp);
	close(pipex.infile);
}

void	ft_child2(t_pipex pipex, char **argv, char **envp)
{
	int		d;
	int		status;

	waitpid(-1, &status, 0);
	d = dup2(pipex.outfile, STDOUT_FILENO);
	if (d < 0)
		exit(1);
	d = dup2(pipex.pip[0], STDIN_FILENO);
	if (d < 0)
		exit(1);
	close(pipex.pip[1]);
	ft_execute(pipex, argv[3], envp);
	close(pipex.outfile);
}

void	ft_pipex(t_pipex pipex, char **argv, char **envp)
{
	pipe(pipex.pip);
	pipex.pid1 = fork();
	if (pipex.pid1 < 0)
		exit(1);
	if (pipex.pid1 == 0)
		ft_child1(pipex, argv, envp);
	pipex.pid2 = fork();
	if (pipex.pid2 < 0)
		exit(1);
	if (pipex.pid2 == 0)
		ft_child2(pipex, argv, envp);
}

int	main(int argc, char **argv, char **envp)
{
	t_pipex	pipex;

	if (argc < 5)
	{
		printf("Wrong number of arguments.");
		exit(1);
	}
	else
	{
		pipex.infile = open(argv[1], O_RDONLY);
		if (pipex.infile < 0)
		{
			ft_putstr_error(strerror(errno), argv[1]);
			exit(127);
		}
		pipex.outfile = open(argv[argc - 1], O_CREAT | O_RDWR | O_TRUNC, 0644);
		if (pipex.outfile < 0)
		{
			ft_putstr_error(strerror(errno), argv[argc - 1]);
			exit(127);
		}
		else
			ft_pipex(pipex, argv, envp);
	}
	return (0);
}
