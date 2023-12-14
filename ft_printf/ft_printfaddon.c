/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printfaddon.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekoubbi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 01:20:03 by ekoubbi           #+#    #+#             */
/*   Updated: 2023/11/07 01:55:15 by ekoubbi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putbaseul(unsigned int nbr)
{
	int	count;

	count = 1;
	if (nbr > 9)
	{
		count += ft_putbaseul(nbr / 10);
		ft_putchar(nbr % 10 + '0');
	}
	else
		ft_putchar(nbr + '0');
	return (count);
}

int	ft_putbase(long nbr)
{
	int	count;

	count = 1;
	if (nbr < 0)
	{
		write(1, "-", 1);
		nbr = -nbr;
		count++;
	}
	if (nbr > 9)
	{
		count += ft_putbase(nbr / 10);
		ft_putchar(nbr % 10 + '0');
	}
	else
		ft_putchar(nbr + '0');
	return (count);
}

int	ft_putp2(unsigned long long nbr, char *ls)
{
	int	count;

	count = 1;
	if (nbr >= 16)
	{
		count += ft_putp2((nbr / 16), ls);
		ft_putchar(ls[nbr % 16]);
	}
	else
		ft_putchar(ls[nbr]);
	return (count);
}

int	ft_putp(unsigned long long nbr, char *ls)
{
	if (nbr != 0)
	{
		write (1, "0x", 2);
		return (ft_putp2(nbr, ls) + 2);
	}
	else
		write (1, "(nil)", 5);
	return (5);
}

int	ft_putx(unsigned int nbr, char *ls)
{
	int	count;

	count = 1;
	if (nbr >= 16)
	{
		count += ft_putx((nbr / 16), ls);
		ft_putchar(ls[nbr % 16]);
	}
	else
		ft_putchar(ls[nbr]);
	return (count);
}
