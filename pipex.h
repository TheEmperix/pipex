/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: woberon <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/30 14:23:53 by woberon           #+#    #+#             */
/*   Updated: 2022/06/30 14:23:55 by woberon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include "libft/libft.h"
# include <stdio.h>
# include <unistd.h>
# include <sys/errno.h>
# include <string.h>
# include <fcntl.h>

void	error_cmd(char *cmd);
void	error_file(char *file);
void	error_process(void);
void	check_args(int argc);
void	free_arr(char **arr);
void	check_fd(int *fd1, int *fd2, char **argv);
char	**find_path(char **env);
char	*get_line(char *cmd, char **arr);

#endif
