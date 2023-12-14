/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekoubbi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 18:36:32 by ekoubbi           #+#    #+#             */
/*   Updated: 2023/11/25 01:27:24 by ekoubbi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	if (str == NULL)
		return (0);
	while (str[i])
		i++;
	return (i);
}

char	*ft_strjoin(char *result, char *buffer)
{
	size_t	i;
	size_t	j;
	char	*str;

	i = 0;
	j = 0;
	str = ft_calloc(ft_strlen(result) + ft_strlen(buffer) + 1, 1);
	if (!str)
		return (NULL);
	while (result && result[i])
	{
		str[i] = result[i];
		i++;
	}
	while (buffer[j])
	{
		str[i + j] = buffer[j];
		j++;
	}
	str[i + j] = '\0';
	free(result);
	return (str);
}

int	ft_strchr(char *buffer)
{
	int	i;

	i = 0;
	while (buffer[i] && buffer[i] != '\n')
		i++;
	if (buffer[i] == '\n')
		return (i);
	return (-1);
}

char	*ft_calloc(int nb_elem, int size)
{
	char	*str;
	int		i;

	str = malloc(nb_elem * size);
	if (!str)
		return (NULL);
	i = 0;
	while (i < nb_elem * size)
	{
		str[i] = 0;
		i++;
	}
	return (str);
}
