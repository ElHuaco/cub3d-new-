/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aleon-ca <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/07 18:26:03 by aleon-ca          #+#    #+#             */
/*   Updated: 2019/11/19 11:35:03 by aleon-ca         ###   ########.fr       */
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

static char	*ft_edgecase(void)
{
	char *a;

	a = malloc(sizeof(char) * 12);
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
	return (a);
}

static void	ft_putnbr(char *a, int n, int *ptr)
{
	if (n >= 10)
		ft_putnbr(a, n / 10, ptr);
	*ptr = *ptr + 1;
	a[*ptr] = n % 10 + 48;
}

char		*ft_itoa(int n)
{
	char	*a;
	int		digits;
	int		*ptr;
	int		i;

	i = -1;
	ptr = &i;
	digits = ft_digitcount(n);
	if (n == -2147483648)
		return (ft_edgecase());
	else
	{
		i = -1 * (n >= 0) + 0;
		ptr = &i;
		a = malloc(sizeof(char) * (digits + 1 + 1 * (n < 0)));
		if (a == 0)
			return (0);
		a[digits + 1 * (n < 0)] = '\0';
		if (n < 0)
			a[0] = '-';
		n *= -1 * (n < 0) + 1 * (n >= 0);
	}
	ft_putnbr(a, n, ptr);
	return (a);
}
