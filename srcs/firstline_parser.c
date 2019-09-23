/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   firstline_parser.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htrent <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/19 12:35:52 by htrent            #+#    #+#             */
/*   Updated: 2019/08/21 11:03:47 by htrent           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	firstline_parser(char *str, t_param *p, int len)
{
	int result;

	result = 0;
	while (len > 3)
	{
		if (*str < '0' || *str > '9')
		{
			p->lines = -1;
			return ;
		}
		result = result * 10 + (*str - '0');
		str++;
		len--;
	}
	p->empty = *(str++);
	p->obstacle = *(str++);
	p->full = *(str++);
	if (*str != '\0' || p->empty == p->obstacle ||
	p->empty == p->full || p->obstacle == p->full)
	{
		p->lines = -1;
		return ;
	}
	p->lines = result;
}
