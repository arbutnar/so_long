/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arbutnar <arbutnar@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/22 23:17:40 by arbutnar          #+#    #+#             */
/*   Updated: 2023/03/22 23:17:41 by arbutnar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./global.h"
#include "./glob.h"
#include "./executor.h"

static char	*prompt_part_2(t_minishell *shell)
{
	char	*prompt;

	signal(SIGQUIT, SIG_IGN);
	signal(SIGINT, ft_sigs_handler);
	prompt = our_prompt(shell, getcwd(NULL, 0));
	return (prompt);
}

static int	do_dirty2(int len, char new_str[], char *str)
{
	int		i;
	int		j;
	char	quote;

	i = -1;
	j = -1;
	while (++j, ++i < len)
	{
		if (str[i] == '<' || str[i] == '>' || str[i] == '|')
			do_dirty3(str, new_str, &i, &j);
		else if (str[i] == '"' || str[i] == '\'')
		{
			quote = str[i];
			new_str[j] = str[i];
			while (i < len && str[++i] != quote)
				new_str[++j] = str[i];
			new_str[++j] = quote;
		}
		else
			new_str[j] = str[i];
	}
	return (j);
}

static void	do_it_dirty(char *str)
{
	int		i;
	int		j;
	int		len;
	char	new_str[8000];

	len = ft_strlen(str);
	j = do_dirty2(len, new_str, str);
	new_str[j] = '\0';
	i = -1;
	while (new_str[++i] != '\0')
		str[i] = new_str[i];
	str[i] = '\0';
}

static int	prompt_loop(t_minishell *shell)
{
	char	*prompt;

	while (TRUE)
	{
		prompt = prompt_part_2(shell);
		shell->input = readline(prompt);
		free(prompt);
		if (!shell->input)
		{
			write(1, "\rexit\n", 7);
			break ;
		}
		if (ft_strncmp(shell->input, "", 1))
			add_history(shell->input);
		do_it_dirty(shell->input);
		if (lexer_init(shell) == 0)
			if (parser(shell) == SUCCESS)
				ft_executor(shell->current_cmd);
		free_commands(shell);
		free(shell->input);
	}
	clear_history();
	free_shell(shell);
	return (0);
}

int	main(int argc, char **argv, char **env)
{
	t_minishell	*shell;

	(void)argc;
	(void)argv;
	shell = (t_minishell *) malloc(sizeof(t_minishell));
	if (!shell)
		return (EXIT_FAILURE);
	init_shell(shell, env);
	prompt_loop(shell);
	return (0);
}
