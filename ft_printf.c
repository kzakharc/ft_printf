/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kzakharc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/14 15:22:34 by kzakharc          #+#    #+#             */
/*   Updated: 2017/05/14 16:35:50 by kzakharc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdlib.h>
#include "libft/libft.h"

void	check_tp(const char **r_f, va_list ap, t_uck *s)
{
	(**r_f == 'd' || **r_f == 'i') ? (print_d_i(ap, s, &(*r_f))) : 0;
	(**r_f == 'D') ? (print_bd(ap, s, &(*r_f))) : 0;
	(**r_f == 'u') ? (print_u(ap, s, &(*r_f))) : 0;
	(**r_f == 'U') ? (print_bu(ap, s, &(*r_f))) : 0;
	(**r_f == 'o') ? (print_o(ap, s, &(*r_f))) : 0;
	(**r_f == 'O') ? (print_bo(ap, s, &(*r_f))) : 0;
	(**r_f == 'c' || **r_f == 'C') ? (print_c(ap, s, &(*r_f))) : 0;
	(**r_f == 's') ? (print_s(ap, s, &(*r_f))) : 0;
	(**r_f == 'S') ? (print_bs(ap, s, &(*r_f))) : 0;
	(**r_f == 'X') ? (print_bx(ap, s, &(*r_f))) : 0;
	if (**r_f == 'p')
	{
		s->space = 0;
		s->plus = 0;
		s->has = 1;
		s->l = 1;
		print_x(ap, s, &(*r_f));
	}
	(**r_f == 'x') ? (print_x(ap, s, &(*r_f))) : 0;
	(*r_f)++;
}

void	check_flags(const char **r_form, t_uck *s)
{
	if (ft_strchr(s->flag, **r_form))
	{
		(**r_form == '-') ? (s->hyphen = 1) : 0;
		(**r_form == '+') ? (s->plus = 1) : 0;
		(**r_form == ' ') ? (s->space = 1) : 0;
		(**r_form == '#') ? (s->has = 1) : 0;
		(**r_form == '0') ? (s->ze = 1) : 0;
		if (**r_form == 'h' && *(*r_form + 1) == 'h')
		{
			s->hh = 1;
			*r_form += 1;
		}
		else if (**r_form == 'h')
			(s->h = 1);
		if (**r_form == 'l' && *(*r_form + 1) == 'l')
		{
			s->ll = 1;
			*r_form += 1;
		}
		else if (**r_form == 'l')
			(s->l = 1);
		(**r_form == 'j') ? (s->j = 1) : 0;
		(**r_form == 'z') ? (s->z = 1) : 0;
		find_dominant(s);
	}
}

void	lets_go(const char *rf, va_list ap, t_uck *s)
{
	while (*rf)
	{
		get_null(s);
		while ((*rf != '%') && (*rf))
		{
			ft_putchar(*rf);
			s->count++;
			(*rf) ? (rf++) : 0;
		}
		if (*rf == '%')
		{
			rf++;
			while (ft_strchr(s->flag, *rf) && *rf)
			{
				if ((*rf >= 49 && *rf <= 57) || (*rf == '*'))
					ch_w(&rf, ap, s);
				if (*rf == '.')
					ch_p(&rf, ap, s);
				check_flags(&rf, s);
				(ft_strchr(s->flag, *rf) && (*rf != '*')) ? (rf++) : 0;
			}
			if (*rf)
				ft_strchr(s->tp, *rf) ? (check_tp(&rf, ap, s)) : p_t(s, &rf);
		}
	}
}

int		ft_printf(const char *r_form, ...)
{
	va_list	ap;
	t_uck	s;

	s.flag = "#0-+ hljz.*123456789";
	s.tp = "sSpdDioOuUxXcC";
	s.count = 0;
	va_start(ap, r_form);
	lets_go(r_form, ap, &s);
	va_end(ap);
	return (s.count);
}
