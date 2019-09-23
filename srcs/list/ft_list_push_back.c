/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_push_back.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htrent <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/13 11:41:30 by htrent            #+#    #+#             */
/*   Updated: 2019/08/19 12:52:11 by htrent           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/header.h"
#include <stdlib.h>

void	ft_list_push_back(t_list **begin_list, char data)
{
	t_list *node;
	t_list *tmp;

	tmp = *begin_list;
	node = ft_create_elem(data);
	if (tmp == NULL)
		*begin_list = node;
	else
	{
		while (tmp->next != NULL)
		{
			tmp = tmp->next;
		}
		tmp->next = node;
	}
}
