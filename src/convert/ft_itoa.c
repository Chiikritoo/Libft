/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anchikri <anchikri@student.42mulhouse.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 19:49:29 by anchikri          #+#    #+#             */
/*   Updated: 2024/08/15 15:27:27 by anchikri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/convert.h"

static int	len_int(int n)
{
	int	len;

	len = 0;
	if (n <= 0)
		len = 1;
	while (n)
	{
		n /= 10;
		len++;
	}
	return (len);
}

char	*ft_itoa(int n)
{
	int		len;
	long	nb;
	char	*tab;

	nb = n;
	len = len_int(nb);
	tab = ft_calloc(len + 1, sizeof(char));
	if (!tab)
		return (NULL);
	if (nb < 0)
	{
		tab[0] = '-';
		nb *= -1;
	}
	while (len > 0 && tab[len - 1] != '-')
	{
		len--;
		tab[len] = (nb % 10) + 48;
		nb /= 10;
	}
	return (tab);
}
