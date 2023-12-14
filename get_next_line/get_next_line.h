/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekoubbi <ekoubbi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 17:41:15 by ekoubbi           #+#    #+#             */
/*   Updated: 2023/11/25 00:48:29 by ekoubbi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 500
# endif

# include <string.h>
# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <fcntl.h>

int		ft_strlen(char *str);
char	*ft_strjoin(char *result, char *buffer);
char	*ft_calloc(int nb_elem, int size);
int		ft_strchr(char *buffer);
char	*ft_read_file(int fd, char *result);
char	*ft_returned_line(char *result);
char	*ft_next_line(char *result, char *returned_line);
char	*get_next_line(int fd);

#endif
