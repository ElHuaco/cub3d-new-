/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aleon-ca <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/09 13:05:11 by aleon-ca          #+#    #+#             */
/*   Updated: 2020/01/20 15:45:56 by aleon-ca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include "libft.h"

# define FLAG_NUMBER 6

# define NONE -2
# define ERROR -3

typedef struct	s_f
{
	int			flags[FLAG_NUMBER];
	int			min_width;
	int			precision;
}				t_format;

int				ft_printf(const char *line, ...);

int				ft_setformat(const char *l, int i, t_format *f, va_list p);

int				ft_printf_int(t_format *form, char specf, int arg);
int				ft_printf_chr(t_format *form, char specf, unsigned int arg);
int				ft_printf_unsign(t_format *f, char specf, unsigned int arg);
int				ft_printf_str(t_format *form, char specf, char *arg);
int				ft_printf_mem(t_format *form, char specf, void *arg);

void			ft_initform(t_format *ptr);
void			ft_errorform(t_format *ptr);
int				ft_isspecifier(char c);
int				ft_isflag(int c);
int				ft_isnum(int c);

int				ft_issignedvalid(int c, int arg);
int				ft_issharpvalid(int c);
int				ft_isprimavalid(int c);
int				ft_findflag(t_format *ptr, int flag);
int				ft_finderror(t_format *ptr);

char			*ft_firstposflagupdate(char *str, int flag);
char			*ft_intprecisionupdate(char *str, int specf, t_format *f);
char			*ft_widthupdate(char *str, t_format *form, char specf);
char			*ft_widthnegint(char *str, char *temp);

char			*ft_chrstr(int len, int c);
void			ft_strmv(char *s1, char *s2);

char			*ft_ultoamode(unsigned long n, char specf);
#endif
