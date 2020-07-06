/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aleon-ca <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/07 18:26:03 by aleon-ca          #+#    #+#             */
/*   Updated: 2020/01/20 15:36:35 by aleon-ca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_digitcount(unsigned long n, int basesize)
{
	int				count;
	unsigned long	max;

	if (n < 0)
		n *= -1;
	max = basesize - 1;
	count = 1;
	while (n > max)
	{
		n = n / basesize;
		count++;
	}
	return (count);
}

static void	ft_putnbrbase(char *a, unsigned long n, int *ptr, char *base)
{
	unsigned long	size;

	size = (unsigned long)ft_strlen(base);
	if (n >= size)
		ft_putnbrbase(a, n / size, ptr, base);
	*ptr = *ptr + 1;
	a[*ptr] = base[n % size];
}

char		*ft_ultoabase(unsigned long n, char *base)
{
	char	*a;
	int		digits;
	int		*ptr;
	int		i;

	i = -1;
	ptr = &i;
	digits = ft_digitcount(n, ft_strlen(base));
	i = -1 * (n >= 0) + 0;
	ptr = &i;
	a = malloc(sizeof(char) * (digits + 1 + 1 * (n < 0)));
	if (a == 0)
		return (0);
	a[digits + 1 * (n < 0)] = '\0';
	if (n < 0)
		a[0] = '-';
	n *= -1 * (n < 0) + 1 * (n >= 0);
	ft_putnbrbase(a, n, ptr, base);
	return (a);
}

char		*ft_ultoamode(unsigned long n, char specf)
{
	if (specf == 'u')
		return (ft_ultoabase(n, "0123456789"));
	else if (specf == 'x')
		return (ft_ultoabase(n, "0123456789abcdef"));
	else
		return (ft_ultoabase(n, "0123456789ABCDEF"));
}
