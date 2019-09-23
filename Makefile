#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: htrent <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/08/19 12:35:29 by htrent            #+#    #+#              #
#    Updated: 2019/08/21 19:57:58 by htrent           ###   ########.fr        #
#                                                                              #
#******************************************************************************#

NAME = bsq

all:fclean 
	@gcc -I headers -Wall -Wextra -Werror -o $(NAME) srcs/*.c srcs/list/*.c

fclean: clean
	@/bin/rm -f $(NAME)

clean:
	@/bin/rm -f *.o

temp:
	@/bin/rm -rf *~ \#*

.PHONY: all fclean clean temp