#include "args.h"

int is_space(char c)
{
	if (c <= 32)
		return (1);
	else
		return (0);
}

int wordlen(char *line)
{
	int len;

	len = 0;
	while (!is_space(*line))
	{
		len++;
		line++;
	}
	return (len);
}

t_token     check_quote(char c)
{
	if (c == '"')
		return (DOUBLE_QUOTE);
	else if (c == '\'')
		return (QUOTE);
}

int eat_space(char *line, int i)
{
	while (is_space(line[i]) && line[i])
		i++;
	return (i);
}

int putcmd(t_args **list, char *line, int *i)
{
	t_args  *new;
	char    *cmd;

	cmd = ft_substr(line, *i, wordlen(line + *i));
	new = ft_lstnew(cmd, CMD);
	ft_lstadd_back(list, new);
	*i += wordlen(line + *i);
	return (0);
}

int quotecheck(char *line, int i, char quote)
{
	i++;
	while (line[i] && line[i] != quote)
		i++;
	if (!line[i])
		return (0);
	return (1);
}

int quotelen(char *line, char quote)
{
	int len;

	len = 1;
	while (line[len] && line[len] != quote)
		len++;
	len++;
	return (len);
}

int putquote(t_args **list, char *line, int i, char quote)
{
	t_args  *new;
	char    *cmd;

	cmd = ft_substr(line, i, quotelen(line + i, quote));
	new = ft_lstnew(cmd, check_quote(quote));
	ft_lstadd_back(list, new);
	i += quotelen(line + i, quote);
	return (i);
}

int check_redir(char *line, int i)
{
	if (line[i] == '<' || line[i] == '>')
		return (1);
	return (0);
}

int check_rtype(char *line, int i)
{
	if (line[i] == '<')
	{
		if (line[i + 1] == '<')
			return (i + 2);
		else
			return (i + 1);
	}
	else
	{
		if (line[i + 1] == '>')
			return (i + 2);
		else
			return (i + 1);
	}
}

int putredir(t_args **list, char *line, int i, int *cmd)
{
	t_args  *new;

	*cmd = 0;
	if (line[i] == '<')
	{
		if (line[i + 1] == '<')
			new = ft_lstnew(NULL, HERE_DOC);
		else
			new = ft_lstnew(NULL, REDIR_IN);
	}
	else if (line[i] == '>')
	{
		if (line[i + 1] == '>')
			new = ft_lstnew(NULL, REDIR_APPEND);
		else
			new = ft_lstnew(NULL, REDIR_OUT);
	}
	ft_lstadd_back(list, new);
	return (check_rtype(line, i));
}

int putpipe(t_args **list, char *line, int *i)
{
	t_args  *new;

	new = ft_lstnew(NULL, PIPE);
	ft_lstadd_back(list, new);
	*i += 1;
	return (1);
}

int putarg(t_args **list, char *line, int i)
{
	t_args  *new;
	char    *arg;

	arg = ft_substr(line, i, wordlen(line + i));
	new = ft_lstnew(arg, ARG);
	ft_lstadd_back(list, new);
	i += wordlen(line + i);
	return (i);
}

t_args    *split_args(char *line)
{
	t_args  *list;
	int     i;
	int     cmd;

	list = NULL;
	i = 0;
	cmd = 1;
	while (line[i])
	{
		i = eat_space(line, i);
		if (check_redir(line, i))
			i = putredir(&list, line, i, &cmd);
		else if (line[i] == '|')
			cmd = putpipe(&list, line, &i);
		else if (cmd)
			cmd = putcmd(&list, line, &i);
		else if ((line[i] == '"' || line[i] == '\'') && quotecheck(line, i, line[i]))
			i = putquote(&list, line, i, line[i]);
		else if (line[i])
			i = putarg(&list, line, i);
	}
	return (list);
}

int main(int argc, char **argv)
{
	t_args	*args;
	t_args	*tmp;

	args = split_args("ls -l | cat -e \"afeaingfuieg augfhbgiueabg eareujat\" > file < aeiogjaoiejg aejfgoijaegoij | aefigoiaejgi << aopgjegopjaeog          ");
	ft_printlst(args);
	free_list(&args);
	return (0);
}
