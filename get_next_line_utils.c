/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: papereir <papereir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/11 18:24:26 by papereir          #+#    #+#             */
/*   Updated: 2023/07/11 18:38:57 by papereir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*str;
	int		len1;
	int		len2;
	int		i;
	int		j;
	
	if (!s1 || !s2)
		return (NULL);
	len1 = ft_strlen(s1);
	len2 = ft_strlen(s2);
	i = 0;
	j= 0;
	str = malloc(sizeof(char) * (len1 + len2 + 1));
	if (!str)
		return (NULL);
	while (i < len1)
	{
		str[i] = s1[i];
		i++;
	}
	while (i <= len1 + len2)
		str[i++] = s2[j++];
	free((void *) s1);
	return str;
}

char	*ft_strdup(const char *s1)
{
	char	*dst;
	int		count;
	
	count = 0;
	dst = malloc(ft_strlen(s1) + 1);
	if (!dst)
		return (0);
	while (s1[count])
	{
		dst[count] = s1[count];
		count++;
	}
	dst[count] = '\0';
	return (dst);
}

size_t	ft_strlen(const char *str)
{
	int count;

	count = 0;
	while (*str)
	{
		count++;
		str++;
	}
	return (count);
}

size_t	ft_strline(char *str)
{
	int count;
	int i;

	count = 0;
	i = 0;
	while(*str && *str != '\n')
	{
		count++;
		str++;
	}
	if (*str == '\n')
		count++;
	return (count);
}

char	*ft_strchr(const char *str, int c)
{
	int i;

	i = 0;
	if (!str)
		return (NULL);
	while (str[i] != '\0')
	{
		if (str[i] == (unsigned char)c)
		{
			return ((char *)&str[i]);
		}
		i++;
	}
	if (c == 0)
		return ((char *)&str[i]);
	else
		return (NULL);
}