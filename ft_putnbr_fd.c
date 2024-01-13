/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wlalaoui <wlalaoui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 15:27:33 by wlalaoui          #+#    #+#             */
/*   Updated: 2023/11/14 17:25:12 by wlalaoui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putnbr_fd_after(int n, int fd)
{
	int	nombre;

	if (n == -2147483648)
		write(fd, "-2147483648", 11);
	else if (n < 0)
	{
		write(fd, "-", 1);
		ft_putnbr_fd_after(-n, fd);
	}
	else if (n < 10)
	{
		nombre = n + 48;
		write(fd, &nombre, 1);
	}
	else if (n >= 10)
	{
		ft_putnbr_fd_after(n / 10, fd);
		ft_putnbr_fd_after(n % 10, fd);
	}
}

int	ft_putnbr_fd(int nbr)
{
	int	i;
	int	nb;

	nb = nbr;
	i = 1;
	if (nbr < 0)
		i++;
	while (nbr / 10 != 0)
	{
		nbr /= 10;
		i++;
	}
	ft_putnbr_fd_after(nb, 1);
	return (i);
}
