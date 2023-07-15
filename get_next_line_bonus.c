/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/14 14:03:55 by marvin            #+#    #+#             */
/*   Updated: 2023/07/14 14:03:55 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*ft_read_to_left_str(int fd, char *left_str)
{
	char	*buff;
	int		rd_bytes;

	buff = malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!buff)
		return (NULL);
	rd_bytes = 1;
	while (!ft_strchr(left_str, '\n') && rd_bytes != 0)
	{
		rd_bytes = read(fd, buff, BUFFER_SIZE);
		if (rd_bytes == -1)
		{
			free(left_str);
			left_str = NULL;
			free(buff);
			return (NULL);
		}
		buff[rd_bytes] = '\0';
		left_str = ft_strjoin(left_str, buff);
	}
	free(buff);
	return (left_str);
}

char	*get_next_line(int fd)
{
	char		*line;
	static char	*left_str[4096];

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (0);
	left_str[fd] = ft_read_to_left_str(fd, left_str[fd]);
	if (!left_str[fd])
		return (NULL);
	line = ft_get_line(left_str[fd]);
	left_str[fd] = ft_new_left_str(left_str[fd]);
	return (line);
}
/*
void leaks() {
	system("leaks a.out");
}

int main()
{
	atexit(leaks);
	int fds[NUM_FILES];
	char *lines[NUM_FILES];

	// Abrir archivos en modo de solo lectura
	fds[0] = open("archivo1.txt", O_RDONLY);
	fds[1] = open("archivo2.txt", O_RDONLY);
	fds[2] = open("archivo3.txt", O_RDONLY);

	if (fds[0] == -1 || fds[1] == -1 || fds[2] == -1)
	{
		perror("Error al abrir los archivos");
		return 1;
	}

	int files_remaining = NUM_FILES;

	// Leer líneas de los archivos hasta que se llegue al final o ocurra un error
	while (files_remaining > 0)
	{
		for (int i = 0; i < NUM_FILES; i++)
		{
			if (fds[i] != -1 && !lines[i])
			{
				lines[i] = get_next_line(fds[i]);

				if (!lines[i])
				{
					close(fds[i]);
					fds[i] = -1;
					files_remaining--;
				}
			}

			if (lines[i])
			{
				printf("Archivo %d: %s\n", i + 1, lines[i]);
				free(lines[i]);
				lines[i] = NULL;
			}
		}
	}

	return 0;
}
*/