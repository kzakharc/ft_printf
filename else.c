/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   else.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kzakharc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/11 17:34:53 by kzakharc          #+#    #+#             */
/*   Updated: 2017/05/14 16:46:02 by kzakharc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdlib.h>
#include "libft/libft.h"

void	print_bs(va_list ap, t_uck *s, const char **r_f)
{
	int *q;
	int dummy;

	s->w = 0;
	dummy = 0;
	s->plus = 0;
	s->space = 0;
	s->has = 0;
	q = (va_arg(ap, int *));
	if ((s->prec == 1) && (s->i_p >= 0))
	{
		while (*q)
		{
			if (((*q >= 0) && (*q < 128)) && (s->i_p >= 1))
			{
				if_one(s, q);
				s->i_p--;
			}
			if (((*q >= 128) && (*q < 2048)) && (s->i_p >= 2))
			{
				if_two(s, q, dummy);
				s->i_p -= 2;
			}
			if (((*q >= 2048) && (*q < 65536)) && (s->i_p >= 3))
			{
				if_three(s, q, dummy);
				s->i_p -= 3;
			}
			q++;
		}
	}
	else
	{
		while (*q)
		{
			if ((*q >= 0) && (*q < 128))
				if_one(s, q);
			if ((*q >= 128) && (*q < 2048))
				if_two(s, q, dummy);
			if ((*q >= 2048) && (*q < 65536))
				if_three(s, q, dummy);
			q++;
		}
	}
	(s->str == NULL) ? (s->str = "(null)") : 0;
	(s->width == 1) ? (print_w(s, &(*r_f))) : (print(s, &(*r_f)));
}

void	get_null(t_uck *s)
{
	s->i_w = 0;
	s->i_p = 0;
	s->hyphen = 0;
	s->plus = 0;
	s->space = 0;
	s->has = 0;
	s->ze = 0;
	s->hh = 0;
	s->h = 0;
	s->l = 0;
	s->ll = 0;
	s->j = 0;
	s->z = 0;
	s->count_1 = 0;
	s->width = 0;
	s->prec = 0;
	s->c = 0;
	s->k = 0;
	s->i = 0;
	s->str_clear = 0;
}

void	find_dominant(t_uck *s)
{
	if (s->z == 1)
	{
		s->j = 0;
		s->ll = 0;
		s->l = 0;
		s->h = 0;
		s->hh = 0;
	}
	if (s->j == 1)
	{
		s->ll = 0;
		s->l = 0;
		s->h = 0;
		s->hh = 0;
	}
	if (s->ll == 1)
	{
		s->l = 0;
		s->h = 0;
		s->hh = 0;
	}
	find_little_dominant(s);
}

void	find_little_dominant(t_uck *s)
{
	if (s->l == 1)
	{
		s->h = 0;
		s->hh = 0;
	}
	if (s->h == 1)
		s->hh = 0;
}

void	for_d(t_uck *s, const char **r_f)
{
	char *tmp;

	if ((s->str[0] == '-') && ((s->ze == 1) || (s->prec == 1) ||
				((s->width == 1) && (s->prec == 1))))
	{
		ft_putchar('-');
		s->count++;
		s->count_1++;
		tmp = s->str;
		s->str = ft_strdup(tmp + 1);
		ft_strdel(&tmp);
		s->plus = 0;
		s->space = 0;
	}
	if ((s->str[0] == '-') && (s->width == 1) && (s->plus == 1))
		s->count_1 -= 1;
	if ((s->str[0] == '0') && (!(s->i_p) && s->prec == 1))
		ft_strclr(s->str);
	(s->prec == 1) ? (s->str = change_for_prec(s, 0)) : 0;
	((s->prec == 1) && (s->i_p > s->k)) ? (free(s->str_p)) : 0;
	(s->width == 1) ? (print_w(s, &(*r_f))) : (print(s, &(*r_f)));
	s->str_clear == 1 ? 0 : free(s->str);
}
