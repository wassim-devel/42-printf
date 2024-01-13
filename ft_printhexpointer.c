/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printhexpointer.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wlalaoui <wlalaoui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/15 18:45:16 by wlalaoui          #+#    #+#             */
/*   Updated: 2023/11/14 17:25:58 by wlalaoui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_dothework(unsigned long long nbr, char *base)
{
	if (error_check(base) == 1)
		;
	else if (nbr < ft_strlen(base))
	{
		write(1, &base[nbr], 1);
	}
	else if (nbr >= ft_strlen(base))
	{
		ft_dothework(nbr / ft_strlen(base), base);
		ft_dothework(nbr % ft_strlen(base), base);
	}
}

int	ft_printhexpointer(unsigned long long nbr, char *base)
{
	int					i;
	unsigned long long	nb;

	nb = nbr;
	i = 0;
	while (nbr != 0)
	{
		nbr /= 16;
		i++;
	}
	if (nb == 0)
	{
		write(1, "(nil)", 5);
		return (5);
	}
	write(1, "0x", 2);
	ft_dothework(nb, base);
	return (i + 2);
}

/*#include "stdio.h"
int	main(void)
{
	char monstring[500] = "salut";
	printf("%p\n", monstring);
	ft_printhexpointer((unsigned long long)(&monstring), "0123456789abcdef");
}*/
