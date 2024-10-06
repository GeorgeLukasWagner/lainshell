/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hzakharc < hzakharc@student.42wolfsburg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/05 20:16:52 by hzakharc          #+#    #+#             */
/*   Updated: 2024/10/06 16:28:14 by hzakharc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	get_index(char **s_buf)
{
	int	i;

	i = 0;
	while ((*s_buf)[i] && (*s_buf)[i] != '\n')
		i++;
	if ((*s_buf)[i] == '\n')
		i++;
	return (i);
}

static char	*fill_the_line(char **s_buf)
{
	char	*line;
	char	*temp;
	int		i;
	int		j;

	i = get_index(s_buf);
	j = -1;
	line = malloc(i + 1);
	if (!line)
		return (NULL);
	line[i] = '\0';
	while (++j < i)
		line[j] = (*s_buf)[j];
	line[j] = '\0';
	temp = ft_strdup(*s_buf + i);
	if (!temp)
	{
		free(line);
		*s_buf = NULL;
		return (NULL);
	}
	free(*s_buf);
	*s_buf = temp;
	return (line);
}

static int	read_data(int fd, char **s_buf)
{
	char	buf[BUFFER_SIZE + 1];
	char	*temp;
	int		read_bytes;

	read_bytes = 1;
	while (read_bytes > 0 && !ft_strchr(*s_buf, '\n'))
	{
		read_bytes = read(fd, buf, BUFFER_SIZE);
		if (read_bytes < 0)
			return (-1);
		buf[read_bytes] = '\0';
		temp = ft_strjoin(*s_buf, buf);
		free(*s_buf);
		*s_buf = temp;
		if (!*s_buf)
			return (-1);
	}
	return (read_bytes);
}

static void	*free_buf(char **s_buf)
{
	free(*s_buf);
	*s_buf = NULL;
	return (NULL);
}

char	*get_next_line(int fd)
{
	static char	*s_buf;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	if (!s_buf)
		s_buf = ft_strdup("");
	if (!s_buf)
		return (NULL);
	if (read_data(fd, &s_buf) < 0)
	{
		free(s_buf);
		s_buf = NULL;
		return (NULL);
	}
	if (!*s_buf)
		return (free_buf(&s_buf));
	line = fill_the_line(&s_buf);
	if (!line)
	{
		free(s_buf);
		s_buf = NULL;
	}
	return (line);
}

// int main(void)
// {
// 	int fd;
// 	char *next_line;
// 	int count;
//
// 	fd = open("test.txt", O_RDONLY);
// 	count = 0;
// 	while ((next_line = get_next_line(fd)))
// 	{
// 		count++;
// 		printf("[%d]:%s", count, next_line);
// 		free(next_line);
// 	}
// 	close(fd);
//	
// 	return (0);
// }
