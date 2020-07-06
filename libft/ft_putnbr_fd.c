/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aleon-ca <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/10 11:53:16 by aleon-ca          #+#    #+#             */
/*   Updated: 2019/11/18 14:24:11 by aleon-ca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_digitcount(int n)
{
	int		count;

	if (n < 0)
		n *= -1;
	count = 1;
	while (n > 9)
	{
		n = n / 10;
		count++;
	}
	return (count);
}

static void	ft_edgecase(char *a)
{
	a[0] = '-';
	a[1] = '2';
	a[2] = '1';
	a[3] = '4';
	a[4] = '7';
	a[5] = '4';
	a[6] = '8';
	a[7] = '3';
	a[8] = '6';
	a[9] = '4';
	a[10] = '8';
	a[11] = '\0';
}

static void	ft_putnbr(char *a, int n, int *ptr)
{
	if (n != -2147483648)
	{
		if (n >= 10)
			ft_putnbr(a, n / 10, ptr);
		*ptr = *ptr + 1;
		a[*ptr] = n % 10 + 48;
	}
}

void		ft_putnbr_fd(int n, int fd)
{
	char	a[12];
	int		digits;
	int		t;
	int		*ptr;

	t = -1;
	ptr = &t;
	digits = ft_digitcount(n);
	if (n == -2147483648)
		ft_edgecase(a);
	else if (n < 0)
	{
		*ptr = 0;
		a[0] = '-';
		a[digits + 1] = '\0';
		n *= -1;
	}
	else
		a[digits] = '\0';
	ft_putnbr(a, n, ptr);
	t = 0;
	while (a[t])
		t++;
	write(fd, a, t);
}
