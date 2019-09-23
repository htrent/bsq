/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htrent <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/19 12:21:44 by htrent            #+#    #+#             */
/*   Updated: 2019/08/21 16:49:40 by htrent           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HEADER_H
# define HEADER_H

# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>

typedef struct		s_list
{
	struct s_list	*next;
	char			data;
}					t_list;

typedef struct		s_param
{
	int				lines;
	char			empty;
	char			obstacle;
	char			full;
}					t_param;

void				firstline_parser(char *str, t_param *p, int len);
t_list				*ft_create_elem(char data);
void				ft_list_clear(t_list **begin_list);
int					ft_list_size(t_list *begin_list);
void				ft_list_push_back(t_list **begin_list, char data);
char				*mass(t_list *begin_list);
int					check(t_list *begin_list, t_param *p);
int					check_first_line(char *str);
void				ft_putchar(char c);
void				ft_putstr(char *str);
char				**list_to_arr(t_list *begin_list, int lines, int length);
int					**clone(char **arr, int lines, int length, char obst);
int					min(int a, int b, int c);
int					*ft_res_arr(int **array, int li, int l, int i);
char				**change(char **array, int *arr, t_param *p);
void				print_array(char **array, int lines, int length);
void				print(t_list *list, t_param *p, int len);
char				*read_first_line(int fd);
t_list				*to_list(int fd, t_param *p);
int					read_from_file(int fd);
int					read_from_stdin(void);
void				print_list(t_list *begin_list);
int					ft_strlen(char *str);
int					*ft_res_arr_one(int **array, int li, int l);

#endif
