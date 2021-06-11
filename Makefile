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