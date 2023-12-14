/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekoubbi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 17:40:42 by ekoubbi           #+#    #+#             */
/*   Updated: 2023/11/25 18:06:08 by ekoubbi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_read_file(int fd, char *result)
{
	char	*buffer;
	int		n;

	buffer = ft_calloc(BUFFER_SIZE + 1, 1);
	n = 1;
	while (n > 0)
	{
		n = read(fd, buffer, BUFFER_SIZE);
		if (n <= 0)
		{
			free(buffer);
			if (n == -1)
			{
				free(result);
				return (NULL);
			}
			return (result);
		}
		buffer[n] = 0;
		result = ft_strjoin(result, buffer);
		if (ft_strchr(result) != -1)
			break ;
	}
	free(buffer);
	return (result);
}

char	*ft_returned_line(char *result)
{
	char	*str;
	int		len;
	int		i;

	if (!result)
		return (NULL);
	len = 0;
	while (result[len] && result[len] != '\n')
		len++;
	str = ft_calloc(len + 2, 1);
	i = 0;
	while (i < len)
	{
		str[i] = result[i];
		i++;
	}
	if (result[i] == '\n')
		str[i] = '\n';
	return (str);
}

char	*ft_next_line(char *result, char *returned_line)
{
	char	*str;
	int		i;
	int		j;

	i = 0;
	while (returned_line[i])
		i++;
	if (!result[i])
	{
		free(result);
		return (NULL);
	}
	str = ft_calloc(ft_strlen(result) - i + 1, 1);
	j = 0;
	while (result[i])
		str[j++] = result[i++];
	free(result);
	return (str);
}

char	*get_next_line(int fd)
{
	static char	*result = NULL;
	char		*returned_line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (0);
	result = ft_read_file(fd, result);
	if (result == NULL || result[0] == '\0')
		return (NULL);
	returned_line = ft_returned_line(result);
	result = ft_next_line(result, returned_line);
	return (returned_line);
}

/*  
int main(void)
{
	int fd;
	int i;
	char    *result;

	i = 0;
	fd = open("text.txt", O_RDONLY);
	if (fd == -1)
	{
		close(fd);
		return (1);
	}
	while (i < 3)
	{
		result = get_next_line(fd);
		printf("%s", result);
		i++;
	}
	free(result);
	return (0);
}
*/
