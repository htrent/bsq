/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htrent <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/20 16:33:48 by htrent            #+#    #+#             */
/*   Updated: 2019/08/21 16:50:42 by htrent           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int		min(int a, int b, int c)
{
	if (a <= b && a <= c)
		return (a);
	if (b <= a && b <= c)
		return (b);
	return (c);
}

int		*ft_res_arr_one(int **array, int li, int l)
{
	int	i;
	int	j;
	int	*res_arr;

	res_arr = (int *)malloc(sizeof(int) * 3);
	res_arr[0] = 0;
	i = -1;
	j = -1;
	while (++i < li)
	{
		while (++j < l)
		{
			if (array[i][j] == 1)
			{
				res_arr[1] = i;
				res_arr[2] = j;
				res_arr[0] = 1;
				return (res_arr);
			}
		}
		j = -1;
	}
	return (res_arr);
}

int		*ft_res_arr(int **array, int li, int l, int i)
{
	int	j;
	int	*res_arr;

	res_arr = (int *)malloc(sizeof(int) * 3);
	res_arr[0] = 0;
	if (li == 1 || l == 1)
		return (ft_res_arr_one(array, li, l));
	j = 0;
	while (++i < li)
	{
		while (++j < l)
		{
			if (array[i][j] > 0)
				array[i][j] += min(array[i][j - 1],
				array[i - 1][j - 1], array[i - 1][j]);
			if (array[i][j] > res_arr[0])
			{
				res_arr[1] = i;
				res_arr[2] = j;
				res_arr[0] = array[i][j];
			}
		}
		j = 0;
	}
	return (res_arr);
}

char	**change(char **array, int *arr, t_param *p)
{
	int	i;
	int	j;

	i = arr[1] - arr[0] + 1;
	j = arr[2] - arr[0] + 1;
	while (i < arr[1] + 1)
	{
		while (j < arr[2] + 1)
		{
			array[i][j] = p->full;
			j++;
		}
		j = arr[2] - arr[0] + 1;
		i++;
	}
	return (array);
}

void	print_array(char **array, int lines, int length)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i < lines)
	{
		while (j < length)
		{
			ft_putchar(array[i][j]);
			j++;
		}
		ft_putchar('\n');
		j = 0;
		i++;
	}
}
