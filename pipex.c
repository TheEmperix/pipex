/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: woberon <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/30 14:23:45 by woberon           #+#    #+#             */
/*   Updated: 2022/06/30 14:24:21 by woberon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	child1_process(int *pipe_fd, char **argv, char **env, int fd1)
{
	char	**cmd;
	char	**path;
	char	*line;

	dup2(fd1, 0);
	dup2(pipe_fd[1], 1);
	cmd = ft_split(argv[2], ' ');
	path = find_path(env);
	line = get_line(cmd[0], path);
	close(fd1);
	close(pipe_fd[0]);
	close(pipe_fd[1]);
	execve(line, cmd, env);
}

void	child2_process(int *pipe_fd, char **argv, char **env, int fd2)
{
	char	**cmd;
	char	**path;
	char	*line;

	dup2(pipe_fd[0], 0);
	dup2(fd2, 1);
	cmd = ft_split(argv[3], ' ');
	path = find_path(env);
	line = get_line(cmd[0], path);
	close(fd2);
	close(pipe_fd[1]);
	close(pipe_fd[0]);
	execve(line, cmd, env);
}

void	pipex(char **argv, char **env)
{
	int		fd1;
	int		fd2;
	pid_t	pid;
	int		pipe_fd[2];

	check_fd(&fd1, &fd2, argv);
	if (pipe(pipe_fd) == -1)
		error_process();
	pid = fork();
	if (pid == -1)
		error_process();
	if (pid == 0)
		child1_process(pipe_fd, argv, env, fd1);
	pid = fork();
	if (pid == -1)
		error_process();
	if (pid == 0)
		child2_process(pipe_fd, argv, env, fd2);
	close(fd1);
	close(fd2);
	close(pipe_fd[0]);
	close(pipe_fd[1]);
	wait(0);
	wait(0);
}

int	main(int argc, char **argv, char **env)
{
	check_args(argc);
	pipex(argv, env);
	return (0);
}
