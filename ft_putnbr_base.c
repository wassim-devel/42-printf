/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wlalaoui <wlalaoui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/15 18:45:16 by wlalaoui          #+#    #+#             */
/*   Updated: 2023/11/14 17:25:42 by wlalaoui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	is_one_character_two_times_in_the_string(char *str, char character)
{
	int	is_present;
	int	i;

	is_present = 0;
	i = 0;
	while (*str != '\0')
	{
		if (i > 0)
		{
			if (*str == character)
			{
				is_present = 1;
				break ;
			}
		}
		str++;
		i++;
	}
	return (is_present);
}

int	error_check(char *base)
{
	int	is_error;

	is_error = 0;
	if (ft_strlen(base) == 0 || ft_strlen(base) == 1)
	{
		is_error = 1;
	}
	else
	{
		while (*base != '\0')
		{
			if (*base == '+' || *base == '-')
			{
				is_error = 1;
				break ;
			}
			if (is_one_character_two_times_in_the_string(base, *base) == 1)
			{
				is_error = 1;
				break ;
			}
			base++;
		}
	}
	return (is_error);
}

void	ft_putnbr_base_after(unsigned int nbr, char *base)
{
	if (error_check(base) == 1)
		;
	else if (nbr < ft_strlen(base))
	{
		write(1, &base[nbr], 1);
	}
	else if (nbr >= ft_strlen(base))
	{
		ft_putnbr_base(nbr / ft_strlen(base), base);
		ft_putnbr_base(nbr % ft_strlen(base), base);
	}
}

int	ft_putnbr_base(unsigned int nbr, char *base)
{
	int	i;
	int	nb;

	nb = nbr;
	i = 0;
	while (nbr != 0)
	{
		nbr /= 16;
		i++;
	}
	ft_putnbr_base_after(nb, base);
	if (nb == 0)
		return (1);
	return (i);
}

/*#include "stdio.h"
int	main(void)
{
	printf("\n%d\n", ft_putnbr_base(0, "0123456789abcdef"));
}*/
