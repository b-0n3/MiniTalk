# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aait-ham <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/06/11 11:29:00 by aait-ham          #+#    #+#              #
#    Updated: 2021/06/11 11:29:02 by aait-ham         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CLIENT= client
SERVER= server




all: $(SERVER) $(CLIENT)


fclean:
	rm -rf $(SERVER) $(CLIENT)

re: fclean $(SERVER) $(CLIENT)



$(CLIENT): 
	gcc -Wall -Wextra -Werror client.c utils.c -o $(CLIENT)

$(SERVER):
	gcc -Wall -Wextra -Werror server.c utils.c -o $(SERVER)
