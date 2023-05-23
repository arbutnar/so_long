/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signals2_0.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arbutnar <arbutnar@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/22 23:19:18 by arbutnar          #+#    #+#             */
/*   Updated: 2023/03/22 23:19:19 by arbutnar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./global.h"

static void	ft_suppress_output(void)
{
	struct termios	new_settings;

	tcgetattr(STDIN_FILENO, &new_settings);
	new_settings.c_lflag &= ~ECHOCTL;
	tcsetattr(STDIN_FILENO, 0, &new_settings);
}

void	ft_sigs_handler(int sig)
{
	if (sig == SIGINT)
	{
		(void)sig;
		set_ecode(130);
		write(1, "\n", 1);
		ft_suppress_output();
		rl_replace_line("", 0);
		rl_on_new_line();
		rl_redisplay();
	}
	else if (sig == SIGQUIT)
	{
		ft_printf("Quit (core dumped)\n");
		set_ecode(131);
	}
}

// check that the error will be printed only if printed for every subshell
void	control_c_signal(int sig)
{
	if (sig == SIGINT)
		set_ecode(130);
	else if (sig == SIGQUIT)
		set_ecode(131);
	return ;
}

void	control_slash(int sig)
{
	if (sig == SIGINT)
	{
		ft_printf("^C\n");
		set_ecode(130);
	}
	else if (sig == SIGQUIT)
	{
		ft_printf("Quit (core dumped)\n");
		set_ecode(131);
		exit(131);
	}
	return ;
}
