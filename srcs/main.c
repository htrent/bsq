/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htrent <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/19 10:55:05 by htrent            #+#    #+#             */
/*   Updated: 2019/08/21 16:47:28 by htrent           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>

int		main(int argc, char **argv)
{
	int		fd;
	int		j;

	j = 0;
	if (argc == 1)
	{
		if (read_from_stdin() == 0)
		{
			write(2, "map error\n", 10);
			return (0);
		}
	}
	while (++j < argc)
	{
		fd = open(argv[j], O_RDONLY);
		if (fd == -1 || read_from_file(fd) == 0)
			write(2, "map error\n", 10);
		if (j != argc - 1)
			ft_putchar('\n');
	}
	return (0);
}
