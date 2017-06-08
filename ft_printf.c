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

void	check_tp(const char **r, va_list ap, t_uck *s)
{
	(**r == 'd' || **r == 'i') ? (print_d_i(ap, s, &(*r))) : 0;
	(**r == 'D') ? (print_bd(ap, s, &(*r))) : 0;
	((**r == 'u') && (s->l != 1)) ? (print_u(ap, s, &(*r))) : 0;
	((**r == 'U') || ((**r == 'u') && (s->l == 1))) ? (print_bu(ap, s, &(*r))) : 0;
	((**r == 'o') && (s->l != 1)) ? (print_o(ap, s, &(*r))) : 0;
	((**r == 'O') || ((**r == 'o') && (s->l == 1))) ? (print_bo(ap, s, &(*r))) : 0;
	((**r == 'c') && (s->l != 1)) ? (print_c(ap, s, &(*r))) : 0;
	(((**r == 'c') && (s->l == 1)) || (**r == 'C')) ? (pr_bc(ap, s, &(*r))) : 0;
	((**r == 's') && (s->l != 1)) ? (print_s(ap, s, &(*r))) : 0;
	((**r == 'S') || ((**r == 's') && (s->l == 1))) ? (pr_bs(ap, s, &(*r))) : 0;
	(**r == 'X') ? (print_bx(ap, s, &(*r))) : 0;
	if (**r == 'p')
	{
		s->has = 1;
		if ((s->ze == 1) && (s->width == 1))
		{
			if_hash(s, &(*r), 1);
			if_hash(s, &(*r), 0);
		}
		s->l = 1;
		print_x(ap, s, &(*r));
	}
	(**r == 'x') ? (print_x(ap, s, &(*r))) : 0;
	(*r)++;
}

void	check_flags(const char **r_form, t_uck *s)
{
	if (ft_strchr(s->f, **r_form))
	{
		(**r_form == '-') ? (s->hyphen = 1) : 0;
		(**r_form == '+') ? (s->plus = 1) : 0;
		(**r_form == ' ') ? (s->space = 1) : 0;
		(**r_form == '#') ? (s->has = 1) : 0;
		(**r_form == '0') ? (s->ze = 1) : 0;
		if (**r_form == 'h')
		{
			s->how++;
			if (s->how % 2 != 0)
				(s->h = 1);
			else
			{
				s->hh = 1;
				s->h = 0;
			}
		}
		if (**r_form == 'l' && *(*r_form + 1) == 'l')
		{
			s->ll = 1;
			*r_form += 1;
		}
		if (**r_form == 'l')
		{
			s->low++;
			if (s->low % 2 != 0)
				(s->l = 1);
			else
				s->ll = 1;
		}
		(**r_form == 'j') ? (s->j = 1) : 0;
		(**r_form == 'z') ? (s->z = 1) : 0;
		find_dominant(s);
	}
}

void	lets_go(const char *r, va_list ap, t_uck *s)
{
	while (*r)
	{
		get_null(s);
		while ((*r != '%') && (*r))
		{
			ft_putchar(*r);
			s->count++;
			(*r) ? (r++) : 0;
		}
		if (*r == '%')
		{
			r++;
			while (ft_strchr(s->f, *r) && *r)
			{
				if ((*r >= 49 && *r <= 57) || (*r == '*'))
					ch_w(&r, ap, s);
				if (*r == '.')
					ch_p(&r, ap, s);
				check_flags(&r, s);
				(ft_strchr(s->f, *r) && (*r != '*') && (*r != '.')) ? (r++) : 0;
			}
			if (*r)
				ft_strchr(s->tp, *r) ? (check_tp(&r, ap, s)) : p_t(s, &r);
		}
	}
}

int		ft_printf(const char *r_form, ...)
{
	va_list	ap;
	t_uck	s;

	s.f = "#0-+ hljz.*123456789";
	s.tp = "sSpdDioOuUxXcC";
	s.count = 0;
	va_start(ap, r_form);
	lets_go(r_form, ap, &s);
	va_end(ap);
	return (s.count);
}
