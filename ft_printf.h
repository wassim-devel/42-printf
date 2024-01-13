/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wlalaoui <wlalaoui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 15:30:21 by wlalaoui          #+#    #+#             */
/*   Updated: 2023/11/14 17:26:10 by wlalaoui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "stdlib.h"
# include "unistd.h"
# include "stdarg.h"

int		ft_printf(const char *str, ...);
int		ft_putchar_fd(char c, int fd);
int		ft_putnbr_fd(int nbr);
int		ft_putstr_fd(char *s, int fd);
size_t	ft_strlen(const char *s);
int		ft_putnbr_base(unsigned int nbr, char *base);
int		ft_putnbr_unsigned(unsigned int nbr);
int		ft_printhexpointer(unsigned long long nbr, char *base);
int		error_check(char *base);
char	*ft_itoa(int n);
int		ft_printnumber(int number);

#endif
