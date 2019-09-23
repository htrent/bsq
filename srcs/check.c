/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htrent <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/20 16:44:15 by htrent            #+#    #+#             */
/*   Updated: 2019/08/20 16:58:20 by htrent           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int		check(t_list *begin_list, t_param *p)
{
	t_list	*tmp;
	int		l;
	int		pl;
	int		c;

	c = 0;
	pl = 0;
	l = 0;
	tmp = begin_list;
	while (tmp)
	{
		if (tmp->data == '\n')
		{
			if ((++c > 2 && l != pl) || (!tmp->next && p->lines != c))
				return (-1);
			else if (!tmp->next)
				return (l);
			pl = l;
			tmp = tmp->next;
			l = 0;
		}
		l++;
		tmp = tmp->next;
	}
	return (-1);
}

int		check_first_line(char *str)
{
	char *buf;

	buf = str;
	if (*buf >= '0' && *buf <= '9')
	{
		while (*buf >= '0' && *buf <= '9')
			buf++;
		if (*(buf + 3) == '\0')
			return (1);
		else
			return (-1);
	}
	return (-1);
}
