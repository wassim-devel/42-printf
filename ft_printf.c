/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wlalaoui <wlalaoui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 17:47:33 by wlalaoui          #+#    #+#             */
/*   Updated: 2023/11/16 14:21:35 by wlalaoui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	handle_percent(const char *str, va_list arguments)
{
	if (str[1] == 'd' || str[1] == 'i')
		return (ft_putnbr_fd(va_arg(arguments, int)));
	else if (str[1] == 'c')
		return (ft_putchar_fd(va_arg(arguments, int), 1));
	else if (str[1] == 's')
		return (ft_putstr_fd(va_arg(arguments, char *), 1));
	else if (str[1] == 'u')
		return (ft_putnbr_unsigned(va_arg(arguments, unsigned int)));
	else if (str[1] == '%')
		return (write(1, "%", 1));
	else if (str[1] == 'x')
		return (ft_putnbr_base(va_arg(arguments, unsigned int),
				"0123456789abcdef"));
	else if (str[1] == 'X')
		return (ft_putnbr_base(va_arg(arguments, unsigned int),
				"0123456789ABCDEF"));
	else if (str[1] == 'p')
		return (ft_printhexpointer(va_arg(arguments, unsigned long long),
				"0123456789abcdef"));
	return (0);
}

int	ft_printf(const char *str, ...)
{
	va_list	arguments;
	int		i;
	int		count;

	i = 0;
	count = 0;
	va_start(arguments, str);
	while (str[i])
	{
		if (str[i] == '%')
		{
			count += handle_percent(&str[i], arguments);
			i++;
			count--;
		}
		else
			write(1, &str[i], 1);
		i++;
		count++;
	}
	va_end(arguments);
	return (count);
}

/*#include "stdio.h"
int	main()
{
	void *p;
	p = (void*)5;
	printf("valeur de retour de ft_printf : %d\n", ft_printf(" %p %p ", p, p));
	printf("valeur de retour printf : %d\n", printf(" %p %p ", p, p));
}*/
