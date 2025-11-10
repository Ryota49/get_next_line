/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jemonthi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/10 07:44:48 by jemonthi          #+#    #+#             */
/*   Updated: 2025/11/10 07:55:23 by jemonthi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

static char	*fill_save(char *line, char *save, char *new_save)
{
	if (!save)
	{
		save = malloc(sizeof(char) * (len(line) + 1));
		if (!save)
			return (NULL);
		ft_strcpy(save, line);
		free (new_save);
	}
	else
	{
		ft_strcpy(new_save, save);
		free (save);
		ft_strcat(new_save, line);
		save = new_save;
		new_save = NULL;
	}
	return (save);
}

static char	*end_of_file(ssize_t i, char *save)
{
	if (i == -1)
	{
		if (save)
		{
			free (save);
			save = NULL;
		}
		return (NULL);
	}
	if (!save)
		return (NULL);
	if (i == 0)
	{
		if (len(save) > 0)
			return (save);
		free (save);
		return (NULL);
	}
	return (NULL);
}

static char	*read_and_malloc(char *save, int fd)
{
	char	*line;
	char	*new_save;
	ssize_t	i;

	line = malloc(sizeof(char) * ((size_t)BUFFER_SIZE + 1));
	if (!line)
		return (NULL);
	i = read(fd, line, BUFFER_SIZE);
	if (i <= 0)
	{
		save = end_of_file(i, save);
		free (line);
		return (save);
	}
	line[i] = '\0';
	new_save = malloc(sizeof(char) * (len(save) + len(line) + 1));
	if (!new_save)
		return (NULL);
	save = fill_save(line, save, new_save);
	free (line);
	return (save);
}

static char	*clear_save(char *save)
{
	char	*keep_after;
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	while (save[i] && save[i] != '\n')
		i++;
	if (save[i] == '\0')
	{
		free (save);
		return (NULL);
	}
	i++;
	keep_after = malloc(sizeof(char) * (len(save + i) + 1));
	if (!keep_after)
		return (NULL);
	while (save[i + j] != '\0')
	{
		keep_after[j] = save[i + j];
		j++;
	}
	keep_after[j] = '\0';
	free(save);
	return (keep_after);
}

char	*get_next_line(int fd)
{
	static char	*s[1024];
	char		*l;

	if (fd < 0 || fd >= 1024)
		return (NULL);
	while (ft_strchr(s[fd], '\n') == NULL)
	{
		l = ft_strdup(s[fd]);
		if (!l && s[fd])
			return (NULL);
		s[fd] = read_and_malloc(s[fd], fd);
		if ((s[fd] && len(l) == len(s[fd])) || !s[fd] || len(s[fd]) == 0)
		{
			free (l);
			break ;
		}
		free(l);
	}
	if (!s[fd] || len(s[fd]) == 0)
		return (NULL);
	l = ft_strdup(s[fd]);
	if (!l)
		return (NULL);
	s[fd] = clear_save(s[fd]);
	return (l);
}
