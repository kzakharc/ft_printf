/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   for_bs.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kzakharc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/31 17:38:39 by kzakharc          #+#    #+#             */
/*   Updated: 2017/05/31 17:38:41 by kzakharc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdlib.h>
#include "libft/libft.h"

void    get_big_s_no_prec(int *q, t_uck *s, int dummy)
{
	while (*q)
	{
		if ((*q >= 0) && (*q < 128))
			if_one(s, q);
		else if ((*q >= 256) && (*q < 2048))
			if_two(s, q, dummy);
		else if ((*q >= 2048) && (*q < 65536))
			if_three(s, q, dummy);
		q++;
	}
}

void    get_big_s(int *q, t_uck *s, int dummy)
{
	while (*q)
	{
		if (((*q >= 0) && (*q < 128)) && (s->i_p >= 1))
		{
			if_one(s, q);
			s->i_p--;
		}
		else if (((*q >= 256) && (*q < 2048)) && (s->i_p >= 2))
		{
			if_two(s, q, dummy);
			s->i_p -= 2;
		}
		else if (((*q >= 2048) && (*q < 65536)) && (s->i_p >= 3))
		{
			if_three(s, q, dummy);
			s->i_p -= 3;
		}
		q++;
	}
}

void    if_one(t_uck *s, int *q)
{
	s->str = get_memory((1 + s->w), s, s->w);
	s->str[s->w] = (char) *q;
	s->w++;
	s->str[s->w] = '\0';
}

void    if_two(t_uck *s, int *q, int dummy)
{
	s->str = get_memory((2 + s->w), s, s->w);
	dummy = *q >> 6;
	dummy |= 192;
	s->str[s->w] = (char) dummy;
	s->w++;
	dummy = (char) *q;
	dummy &= 63;
	dummy |= 128;
	s->str[s->w] = (char) dummy;
	s->w++;
	s->str[s->w] = '\0';
}

void    if_three(t_uck *s, int *q, int dummy)
{
	s->str = get_memory((3 + s->w), s, s->w);
	dummy = *q >> 12;
	dummy |= 224;
	s->str[s->w] = (char) dummy;
	s->w++;
	dummy = *q >> 6;
	dummy &= 63;
	dummy |= 128;
	s->str[s->w] = (char) dummy;
	s->w++;
	dummy = (char) *q;
	dummy &= 63;
	dummy |= 128;
	s->str[s->w] = (char) dummy;
	s->w++;
	s->str[s->w] = '\0';
}