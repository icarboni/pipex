/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: icarboni <icarboni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/19 11:54:13 by icarboni          #+#    #+#             */
/*   Updated: 2022/11/08 11:37:38 by icarboni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
#define PIPEX_H

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <signal.h>
#include <fcntl.h>
#include <errno.h>
#include <string.h>

void	pipex(int f1, int f2, char **argv, char **envp);
void	ft_child_function(int f1, char **argv, int pip[], char **envp);
void	ft_father_function(int f2, char **argv, int pip[], char **envp);
int		ft_strstr(char *str, char *to_find);
void	ft_putstr_error(char *s, char *t);
char    **ft_clean_args(char **args);
void	ft_execute(char *cmd, char **envp);

#endif