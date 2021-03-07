/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/30 12:18:39 by user42            #+#    #+#             */
/*   Updated: 2020/12/23 14:59:42 by masboula         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdarg.h>
# include "libft/libft.h"

typedef struct	s_format
{
	char	flag;
	char	flag_pr;
	int		width;
	char	prec;
	int		lenght;
	int		lenght_str;
	char	spec;
	int		zero;
	int		zero_pr;
}				t_format;

int				is_sign(char c);
int				ft_printf(const char *format, ...);
int				ft_pars(char *format, va_list *args, int *count);
int				ft_pars2(char *format, t_format *comb, va_list *args);
void			check_conv(t_format *comb, va_list *args, int *count);

int				ft_get_conv(char *format, t_format *comb);
int				ft_get_prec(char *format, t_format *comb);
int				ft_get_zero(char *format, t_format *comb);
int				ft_get_sign(char *format, t_format *comb);

int				is_num(char *format, t_format *comb, va_list *args);
int				is_num_prec(char *format, t_format *comb, va_list *args);
int				ft_len(int num);
char			*ft_itoa_base(long long n, char *base);
void			ft_putnbr_unsigned(int nb);
unsigned int	ft_len_unsigned(unsigned int num);
int				ft_tmp(t_format *comb, int l, int tmp);

int				ft_write_only(unsigned int num, t_format *comb);
int				ft_write_only_pr(unsigned int num, t_format *comb, int *count);
int				ft_write_zero(int len, int tmp, int i);
int				ft_write_space(int len, int tmp, int i);

void			type_id(t_format *comb, va_list *args, int *count);
void			type_c(t_format *comb, va_list *args, int *count);
void			type_str(t_format *comb, va_list *args, int *count);
void			type_u(t_format *comb, va_list *args, int *count);
void			type_p(t_format *comb, va_list *args, int *count);
void			type_x(t_format *comb, va_list *args, int *count);
void			type_xmaj(t_format *comb, va_list *args, int *count);
void			type_mod(t_format *comb, va_list *args, int *count);

void			ft_mod_prec(t_format *comb, int *count);
void			ft_mod_width(t_format *comb, int *count);
void			ft_mod_flag(t_format *comb, int *count);

void			ft_str_prec2(t_format *comb, char *str, int *count, int tmp);
void			ft_str_flag(t_format *comb, char *str, int *count);
void			ft_str_width(t_format *comb, char *str, int *count);
void			ft_str_prec(t_format *comb, char *str, int *count, int s);

void			ft_char_prec(t_format *comb, va_list *args, int *count);
void			ft_char_flag(t_format *comb, va_list *args, int *count);
void			ft_char_width(t_format *comb, va_list *args, int *count);

void			ft_id_flag(t_format *comb, int num, int *count);
int				ft_id_flag_neg(t_format *comb, int num, int *count, int l);
int				ft_id_flag_neg2(t_format *comb, int l, int num, int *tmp);
void			ft_id_width_neg(t_format *comb, int num, int *count, int l);
void			ft_id_prec_neg(t_format *comb, int num, int *count, int l);
void			ft_id_width(t_format *comb, int num, int *count);
void			ft_id_prec(t_format *comb, int num, int *count);
void			ft_id_prec2(t_format *comb, int num, int *count, int l);
void			ft_id_prec3(t_format *comb, int num, int *count, int l);

int				ft_u_zero(unsigned int num, t_format *comb, int *count);
void			ft_u_flag(t_format *comb, unsigned int num, int *count);
int				ft_u_flag2(t_format *comb, unsigned int num, int *tmp, int l);
void			ft_u_width(t_format *comb, unsigned int num, int *count);
void			ft_u_prec2(t_format *comb, unsigned int num,
int *count, int tmp);
void			ft_u_prec(t_format *comb, unsigned int num, int *count);

void			ft_p_prec2(t_format *comb, int *count, char *num, int i);
void			ft_p_flag(t_format *comb, unsigned long add, int *count);
void			ft_p_width(t_format *comb, unsigned long add, int *count);
void			ft_p_prec(t_format *comb, unsigned long add, int *count);
void			ft_p_neg_prec(t_format *comb, int *count,
char *hexa, char *num);

void			ft_x_flag(t_format *comb, char *str,
int *count, unsigned int num);
int				ft_x_flag2(t_format *comb, char *str,
int *count, unsigned int num);
void			ft_x_width(t_format *comb, char *str, int *count);
void			ft_x_prec(t_format *comb, char *str,
int *count, unsigned int num);
int				ft_x_prec2(t_format *comb, int *count, unsigned int num, int l);
void			ft_xmaj_flag(t_format *comb, char *str,
int *count, unsigned int num);
int				ft_xmaj_flag2(t_format *comb, char *str,
int *count, unsigned int num);
void			ft_xmaj_width(t_format *comb, char *str, int *count);
void			ft_xmaj_prec(t_format *comb, char *str,
int *count, unsigned int num);
int				ft_xmaj_prec2(t_format *comb, int *count,
unsigned int num, int l);

#endif
