/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htrent <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/20 16:21:14 by htrent            #+#    #+#             */
/*   Updated: 2019/08/21 19:52:05 by htrent           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <header.h>

void	print(t_list *list, t_param *p, int len)
{
	print_array(change(list_to_arr(list, p->lines, len),
	ft_res_arr(clone(list_to_arr(list, p->lines, len),
	p->lines, len, p->obstacle), p->lines, len, 0), p),
	p->lines, len);
}

char	*read_first_line(int fd)
{
	char	*buf;
	char	*begin;
	char	c;

	buf = malloc(100);
	begin = buf;
	while (read(fd, &c, 1))
	{
		if (c == '\n')
			break ;
		*buf = c;
		buf++;
	}
	*buf = '\0';
	return (begin);
}

t_list	*to_list(int fd, t_param *p)
{
	char	c;
	t_list	*list;

	list = NULL;
	c = 0;
	while ((read(fd, &c, 1) > 0))
	{
		if (c != p->empty && c != p->obstacle && c != '\n')
			return (0);
		ft_list_push_back(&list, c);
	}
	return (list);
}

int		read_from_file(int fd)
{
	char	*buf;
	char	*begin;
	t_list	*list;
	t_param	p;
	int		len;

	buf = read_first_line(fd);
	begin = buf;
	if (ft_strlen(begin) < 4)
		return (0);
	firstline_parser(begin, &p, ft_strlen(begin));
	list = to_list(fd, &p);
	if (list == 0)
		return (0);
	len = check(list, &p);
	if (len == -1 || check_first_line(begin) == -1)
		return (0);
	print(list, &p, len);
	close(fd);
	free(buf);
	ft_list_clear(&list);
	return (1);
}

int		read_from_stdin(void)
{
	char	*buf;
	char	*begin;
	t_list	*list;
	t_param	p;
	int		len;

	buf = read_first_line(0);
	begin = buf;
	if (ft_strlen(begin) < 4)
		return (0);
	firstline_parser(begin, &p, ft_strlen(begin));
	list = to_list(0, &p);
	if (list == 0)
		return (0);
	len = check(list, &p);
	if (len == -1 || check_first_line(begin) == -1)
		return (0);
	print(list, &p, len);
	free(buf);
	ft_list_clear(&list);
	return (1);
}
