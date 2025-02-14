/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anchikri <anchikri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 19:49:29 by anchikri          #+#    #+#             */
/*   Updated: 2025/01/30 03:11:00 by anchikri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/libft.h"

// function who calculates the length of an integer
int	len_int(int n)
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

// function who converts an integer to a string
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
