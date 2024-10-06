/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hzakharc < hzakharc@student.42wolfsburg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/08 16:45:12 by hzakharc          #+#    #+#             */
/*   Updated: 2024/10/06 16:20:02 by hzakharc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "exec.h"

int	env_lstsize_exec(t_env *env)
{
	t_env	*temp;
	int		i;

	temp = env;
	i = 0;
	while (temp)
	{
		if (ft_strchr(temp->data, '=') != NULL)
			i++;
		temp = temp->next;
	}
	return (i);
}

char	**create_envp(t_env *env)
{
	char	**envp;
	t_env	*temp;
	int		i;

	temp = env;
	envp = ft_calloc(sizeof(char *), env_lstsize_exec(env) + 1);
	i = 0;
	while (temp != NULL)
	{
		if (ft_strchr(temp->data, '=') != NULL)
		{
			envp[i] = ft_strdup(temp->data);
			i++;
		}
		temp = temp->next;
	}
	return (envp);
}

int	is_a_built(char **argv)
{
	if ((ft_strncmp(argv[0], "echo", ft_strlen(argv[0])) == 0)
		|| (ft_strncmp(argv[0], "cd", ft_strlen(argv[0])) == 0)
		|| (ft_strncmp(argv[0], "pwd", ft_strlen(argv[0])) == 0)
		|| (ft_strncmp(argv[0], "export", ft_strlen(argv[0])) == 0)
		|| (ft_strncmp(argv[0], "unset", ft_strlen(argv[0])) == 0)
		|| (ft_strncmp(argv[0], "env", ft_strlen(argv[0])) == 0)
		|| (ft_strncmp(argv[0], "exit", ft_strlen(argv[0])) == 0))
		return (TRUE);
	else
		return (FALSE);
}

void	execute_cmd(t_data **data, t_cmd *cmd, int index)
{
	char	**envp;

	envp = create_envp((*data)->env);
	if (check_redir_exec((*data)->redir, index) == FALSE)
		exit(1);
	if (execve(cmd->argv[0], cmd->argv, envp) == -1)
	{
		perror(cmd->argv[0]);
		free_matrix(envp);
		exit(127);
	}
	free_matrix(envp);
}

void	open_all_files(t_alt **redir)
{
	t_alt	*cur;
	int		fd;

	cur = *redir;
	while (cur)
	{
		if (cur->token == REDIR_IN)
		{
			fd = open(cur->data, O_RDONLY);
			if (fd == -1)
			{
				// put_error((char *[]){cur->data, ": No such a file or a directory2\n", NULL});
				cur->exec = FALSE;
				break;
			}
			close(fd);
		}
		else if (cur->token == REDIR_OUT)
		{
			fd = open(cur->data, O_WRONLY | O_CREAT | O_TRUNC, 0644);
			if (fd == -1)
			{
				put_error((char *[]){cur->data, ": No such a file or a directory\n", NULL});
				cur->exec = FALSE;
			}
			close(fd);
		}
		else if (cur->token == REDIR_APPEND)
		{
			fd = open(cur->data, O_WRONLY | O_CREAT | O_APPEND, 0644);
			if (fd == -1)
			{
				put_error((char *[]){cur->data, ": No such a file or a director\n", NULL});
				cur->exec = FALSE;
			}
			close(fd);
		}
		// else if (cur->token == HERE_DOC)
		// 	//here_doc execute;
		cur = cur->next;
	}
}

int	check_redir_exec(t_alt *redir, int index)
{
	t_alt	*cur;

	cur = redir;
	while (cur && cur->index != index)
		cur = cur->next;
	while (cur && cur->index == index)
	{
		if (cur->exec == FALSE)
			exit(1);
		cur = cur->next;
	}
	return (TRUE);
}

void	execute(t_data *data, t_cmd *cmd, int index)
{
	pid_t	pid;

	if (cmd->argv == NULL)
		return ;
	if (is_a_built(cmd->argv) == TRUE)
	{
		open_copy_fds(&data);
		exec_built_redir(&data, cmd, index, 0);
	}
	else
	{
		if (data->redir)
		{
			if (check_redir_exec(data->redir, index) == FALSE)
				return ;
		}
		pid = fork();
		if (pid == -1)
			perror("fork");
		else if (pid == 0)
		{
			if (pathfinder(data->env, cmd->argv) == FALSE)
			{
				put_error((char *[]){cmd->argv[0], ": Command was not found\n", NULL});
				exit(127);
			}
			handle_redir(&data->redir, index);
			execute_cmd(&data, cmd, index);
		}
		waitpid(pid, NULL, 0);
	}
}

void	exec(t_data *data)
{
	if (data->cmd->next == NULL)
		execute(data, data->cmd, 0);
	else
		execute_pipeline(data, data->cmd);
}


//have to create a function check redirections for the execve 