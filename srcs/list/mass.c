/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mass.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbrigitt <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/18 16:56:31 by dbrigitt          #+#    #+#             */
/*   Updated: 2019/08/20 17:00:55 by htrent           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/header.h"

char	*mass(t_list *begin_list)
{
	char	*mass;
	t_list	*tmp;
	char	*buf;

	tmp = begin_list;
	mass = malloc(sizeof(char) * (ft_list_size(begin_list) + 5));
	buf = mass;
	while (tmp)
	{
		*mass = tmp->data;
		mass++;
		tmp = tmp->next;
	}
	*mass = '\0';
	return (buf);
}
