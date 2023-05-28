/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: icarboni <icarboni@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/19 11:54:13 by icarboni          #+#    #+#             */
/*   Updated: 2022/11/15 20:27:32 by icarboni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <sys/types.h>
# include <signal.h>
# include <fcntl.h>
# include <errno.h>
# include <string.h>
# include <sys/wait.h>

typedef struct s_pipex
{
	pid_t	pid1;
	pid_t	pid2;
	int		pip[2];
	int		infile;
	int		outfile;
	char	*cmd_path;
	char	**paths;
	char	**args;
	char	*cmd;
}t_pipex;

typedef struct s_parser
{
	char	*str;
	int		words;
	char	sep;
	int		len;
	int		index;
	int		i;
	int		w;
	int		next;
}t_parser;

//	pipex.c
int		main(int argc, char **argv, char **envp);
void	ft_pipex(t_pipex pipex, char **argv, char **envp);
void	ft_child1(t_pipex pipex, char **argv, char **envp);
void	ft_child2(t_pipex pipex, char **argv, char **envp);
void	ft_execute(t_pipex pipex, char *cmd, char **envp);
// pipex_utils.c
int		ft_strstr(char *str, char *to_find);
void	ft_putstr_error(char *s, char *t);
char	**ft_env_parse(char **envp);
char	*ft_get_path(t_pipex pipex);

// parser.c
char	**ft_parser(char *s, char c);
void	ft_words_count_parser(t_parser *p, char c);
char	*word_dup_parser(t_parser p, int start, int finish);
int		ft_exe_parser(t_parser p, char **res);

// parser_utils.c
int		ft_free_parser(char **res, int created);
int		ft_if_quot(t_parser *p, int *index, char **res);
int		ft_find_other(t_parser p, int in, char c);

#endif
