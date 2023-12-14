/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekoubbi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/05 14:20:50 by ekoubbi           #+#    #+#             */
/*   Updated: 2023/11/07 20:26:10 by ekoubbi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putchar(char c)
{
	write(1, &c, 1);
	return (1);
}

int	ft_putstr(char *s)
{
	int	i;

	i = 0;
	if (s == NULL)
	{
		write(1, "(null)", 6);
		return (6);
	}
	while (s[i] != 0)
	{
		write (1, &s[i], 1);
		i++;
	}
	return (i);
}

int	print_nbr(const char s, va_list ap)
{
	int	count;

	count = 0;
	if (s == 'c')
		count = ft_putchar(va_arg(ap, int));
	if (s == 's')
		count = ft_putstr(va_arg(ap, char *));
	if (s == 'd' || s == 'i')
		count = ft_putbase(va_arg(ap, int));
	if (s == 'u')
		count = ft_putbaseul(va_arg(ap, unsigned int));
	if (s == 'x')
		count = ft_putx(va_arg(ap, unsigned int), "0123456789abcdef");
	if (s == 'X')
		count = ft_putx(va_arg(ap, unsigned int), "0123456789ABCDEF");
	if (s == 'p')
		count = ft_putp(va_arg(ap, unsigned long long), "0123456789abcdef");
	if (s == '%')
		count = ft_putchar('%');
	return (count);
}

int	ft_printf(const char *s, ...)
{
	va_list	ap;
	int		count;
	int		i;

	i = 0;
	count = 0;
	va_start(ap, s);
	while (s[i] != 0)
	{
		if (s[i] == '%')
		{
			count += print_nbr(s[i + 1], ap);
			i++;
		}
		else
		{
			write(1, &s[i], 1);
			count++;
		}
		i++;
	}
	va_end(ap);
	return (count);
}
/*              
#include <limits.h>
int	main ()
{
	int i;
	int j;
	char	*c;

	c = NULL;
	i = printf("%s et %% et %d et %x\n", "coco" , "%", 4223, 42);
	j = ft_printf("%s et %% et %d et %x\n", "coco" , "%", 4223, 42);

	printf("%d\n", i);
	printf("%d\n", j);
}
*/
