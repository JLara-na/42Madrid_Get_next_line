/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlara-na <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/17 19:53:59 by jlara-na          #+#    #+#             */
/*   Updated: 2022/09/13 14:33:20 by jlara-na         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include "get_next_line_bonus.h"

static char	*stasher(int fd, char *stash)
{
	char	*buff;
	int		read_out;

	read_out = 1;
	if (!stash)
		stash = ft_calloc(sizeof(char), 1);
	buff = ft_calloc(sizeof(char), (BUFFER_SIZE + 1));
	if (!buff)
		return (NULL);
	while (!ft_strchr(buff, '\n') && read_out != 0)
	{
		read_out = read(fd, buff, BUFFER_SIZE);
		if (read_out == -1)
		{
			free(buff);
			free(stash);
			return (NULL);
		}
		buff[read_out] = '\0';
		stash = ft_strjoin(stash, buff);
	}
	free(buff);
	return (stash);
}

static char	*liner(char *stash)
{
	char	*line;
	int		i;

	i = 0;
	if (!stash[i])
		return (NULL);
	while (stash[i] != '\n' && stash[i] != '\0')
		i++;
	line = ft_calloc(sizeof(char), (i + 2));
	if (!line)
		return (NULL);
	i = 0;
	while (stash[i] != '\n' && stash[i] != '\0')
	{
		line[i] = stash[i];
		i++;
	}
	if (stash[i] == '\n' && stash[i])
		line[i] = stash[i];
	return (line);
}

static char	*stash_cutter(char *stash)
{
	char	*buff;
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (stash[i] != '\n' && stash[i] != '\0')
		i++;
	if (!stash[i])
	{
		free(stash);
		return (NULL);
	}
	buff = calloc(sizeof(char), (ft_strlen(stash) + 1 - i));
	if (!buff)
		return (NULL);
	i++;
	while (stash[i])
		buff[j++] = stash[i++];
	free(stash);
	return (buff);
}

char	*get_next_line(int fd)
{
	static char	*stash[FD_MAX];
	char		*buff;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	stash[fd] = stasher(fd, stash[fd]);
	if (!stash[fd])
		return (NULL);
	buff = liner(stash[fd]);
	stash[fd] = stash_cutter(stash[fd]);
	return (buff);
}
