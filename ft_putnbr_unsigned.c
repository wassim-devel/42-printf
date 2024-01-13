/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_unsigned.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wlalaoui <wlalaoui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 11:42:52 by wlalaoui          #+#    #+#             */
/*   Updated: 2023/11/14 17:24:44 by wlalaoui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putnbr_unsigned_after(unsigned int n)
{
	unsigned int	nombre;

	if (n < 10)
	{
		nombre = n + 48;
		write(1, &nombre, 1);
	}
	else if (n >= 10)
	{
		ft_putnbr_unsigned(n / 10);
		ft_putnbr_unsigned(n % 10);
	}
}

int	ft_putnbr_unsigned(unsigned int nbr)
{
	int				i;
	unsigned int	nb;

	i = 1;
	nb = nbr;
	while (nbr / 10 != 0)
	{
		nbr /= 10;
		i++;
	}
	ft_putnbr_unsigned_after(nb);
	return (i);
}

/*int main()
{
	ft_putnbr_unsigned(555);
}*/