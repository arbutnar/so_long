/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirpipe.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arbutnar <arbutnar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/22 23:55:52 by arbutnar          #+#    #+#             */
/*   Updated: 2023/03/22 23:55:56 by arbutnar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "executor.h"
#define HEREDOC_MSG	"\033[1;97m> \033[0m"

void	add(t_command *cmd, int *stdin_cpy, int *stdout_cpy)
{
	while (*cmd->red && cmd->red_type)
	{
		ft_chooseredir(cmd, stdin_cpy, stdout_cpy);
		cmd->red++;
		cmd->red_type++;
	}
}

int	ft_redir(t_command *cmd, int *stdin_cpy, int *stdout_cpy)
{
	char	**redreset;
	int		*typereset;

	redreset = cmd->red;
	typereset = cmd->red_type;
	if (ft_findpath(cmd, 0) == NULL)
	{
		ft_printf("minishell: command not found\n");
		return (0);
	}
	add(cmd, stdin_cpy, stdout_cpy);
	if (cmd->red_error != 1)
		ft_execv(cmd, &cmd->shell->exit_status);
	else
		ft_putstr_fd("minishell: infile: No such file or directory\n",
			STDERR_FILENO);
	if (cmd->red_type[0] != REDIN)
		dup2(*stdout_cpy, STDOUT_FILENO);
	dup2(*stdin_cpy, STDIN_FILENO);
	cmd->red = redreset;
	cmd->red_type = typereset;
	close(*stdin_cpy);
	close(*stdout_cpy);
	return (0);
}

void	ft_redirpipe(t_command *cmd, int *stdin_cpy, int *stdout_cpy)
{
	char	**redreset;
	int		*typereset;

	redreset = cmd->red;
	typereset = cmd->red_type;
	while (*cmd->red && cmd->red_type)
	{
		ft_chooseredir(cmd, stdin_cpy, stdout_cpy);
		cmd->red++;
		cmd->red_type++;
	}
	cmd->red = redreset;
	cmd->red_type = typereset;
}

void	ft_chooseredir(t_command *cmd, int *stdin_cpy, int *stdout_cpy)
{
	if (cmd->red_type[0] == HERDOC)
		ft_heredoc(cmd, stdin_cpy);
	else if (cmd->red_type[0] == REDIN)
		ft_redin(cmd, stdin_cpy);
	else if (cmd->red_type[0] == REDOUT)
		ft_redout(cmd, stdin_cpy, stdout_cpy);
	else if (cmd->red_type[0] == REDAPP)
		ft_redappend(cmd, stdout_cpy);
}
