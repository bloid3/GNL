/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: papereir <papereir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/13 17:12:02 by papereir          #+#    #+#             */
/*   Updated: 2023/07/13 17:35:58 by papereir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*ft_goodline(char *goodline)
{
	char	*aux;
	int		i;

	i = 0;
	if (!goodline)
		return (NULL);
	aux = malloc(sizeof(char) * ft_strlen(goodline) + 1);
	if (!aux)
		return (NULL);
	while (goodline[i] != '\n' && goodline[i])
	{
		aux[i] = goodline[i];
		i++;
	}
	if (goodline[i] == '\n')
		aux[i++] = '\n';
	aux[i] = '\0';
	return (aux);
}

int	aux(char *line, char *lineaux, int i)
{
	int		j;

	j = 0;
	while (line[i] != '\0')
	{
		lineaux[j] = line[i];
		i++;
		j++;
	}
	return (j);
}

char	*ft_restline(char *line)
{
	int		i;
	int		j;
	char	*lineaux;

	i = 0;
	j = 0;
	if (!line)
		return (NULL);
	if (!line[ft_strline(line)])
	{
		free(line);
		return (NULL);
	}
	lineaux = malloc(sizeof(char) * (ft_strlen(line) - ft_strline(line)) + 1);
	if (!lineaux)
		return (NULL);
	while (line[i] != '\n' && line[i])
		i++;
	if (line[i] == '\n')
		i++;
	lineaux[aux(line, lineaux, i)] = '\0';
	free(line);
	return (lineaux);
}

char	*ft_read(int fd, char *goodline, char *todo)
{
	int	r;

	while (!ft_strchr(todo, '\n'))
	{
		r = read(fd, goodline, BUFFER_SIZE);
		if (r == 0 || r == -1)
		{
			free(goodline);
			return (todo);
		}
		goodline[r] = '\0';
		if (!todo)
			todo = ft_strdup(goodline);
		else
			todo = ft_strjoin(todo, goodline);
	}
	free(goodline);
	return (todo);
}

char	*get_next_line(int fd)
{
	static char	*todo[OPEN_MAX];
	char		*goodline;

	if (BUFFER_SIZE <= 0 || fd < 0 || fd > OPEN_MAX)
		return (NULL);
	goodline = malloc(sizeof(char) * BUFFER_SIZE + 1);
	if (!goodline)
		return (NULL);
	todo[fd] = ft_read(fd, goodline, todo[fd]);
	goodline = ft_goodline(todo[fd]);
	todo[fd] = ft_restline(todo[fd]);
	return (goodline);
}
