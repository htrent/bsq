/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_size.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htrent <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/13 12:10:53 by htrent            #+#    #+#             */
/*   Updated: 2019/08/19 12:52:22 by htrent           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/header.h"

int		ft_list_size(t_list *begin_list)
{
	t_list	*tmp;
	int		n;

	n = 0;
	tmp = begin_list;
	while (tmp)
	{
		tmp = tmp->next;
		n++;
	}
	return (n);
}
