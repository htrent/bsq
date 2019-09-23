/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clone.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htrent <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/21 16:59:48 by htrent            #+#    #+#             */
/*   Updated: 2019/08/21 17:00:46 by htrent           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int		**clone(char **arr, int lines, int length, char obst)
{
	int **array;
	int i;
	int j;

	i = 0;
	j = 0;
	array = (int **)malloc(sizeof(int*) * lines);
	while (i < lines)
		array[i++] = (int *)malloc(sizeof(int) * length);
	i = 0;
	while (i < lines)
	{
		while (j < length)
		{
			if (arr[i][j] == obst)
				array[i][j] = 0;
			else
				array[i][j] = 1;
			j++;
		}
		j = 0;
		i++;
	}
	return (array);
}
