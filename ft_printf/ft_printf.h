/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekoubbi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/04 21:46:55 by ekoubbi           #+#    #+#             */
/*   Updated: 2023/11/07 01:46:24 by ekoubbi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>

int	ft_putbaseul(unsigned int nbr);
int	ft_putchar(char c);
int	ft_putstr(char *s);
int	print_nbr(const char s, va_list ap);
int	ft_putbaseul(unsigned int nbr);
int	ft_putbase(long nbr);
int	ft_putp2(unsigned long long nbr, char *ls);
int	ft_putp(unsigned long long nbr, char *ls);
int	ft_putx(unsigned int nbr, char *ls);
int	ft_printf(const char *s, ...);

#endif
