/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_to_arr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htrent <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/20 16:47:16 by htrent            #+#    #+#             */
/*   Updated: 2019/08/20 17:02:06 by htrent           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

char	**list_to_arr(t_list *begin_list, int lines, int length)
{
	char	**array;
	int		i;
	t_list	*tmp;
	int		j;

	j = 0;
	tmp = begin_list;
	i = 0;
	array = (char **)malloc(sizeof(char*) * (lines + 1));
	while (i < lines)
		array[i++] = (char *)malloc(sizeof(char) * (length + 1));
	array[lines] = "\0";
	i = 0;
	while (tmp)
	{
		if (tmp->data == '\n')
		{
			array[i++][j] = '\0';
			j = 0;
		}
		else
			array[i][j++] = tmp->data;
		tmp = tmp->next;
	}
	return (array);
}
