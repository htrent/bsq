/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_clear.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htrent <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/13 12:47:15 by htrent            #+#    #+#             */
/*   Updated: 2019/08/19 12:51:59 by htrent           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/header.h"
#include <stdlib.h>

void	ft_list_clear(t_list **begin_list)
{
	t_list *tmp;
	t_list *current;

	tmp = *begin_list;
	while (tmp)
	{
		current = tmp;
		tmp = tmp->next;
		free(current);
	}
}
