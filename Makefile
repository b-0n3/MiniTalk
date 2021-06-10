CLIENT= client
SERVER= server


$(CLIENT): 
	rm -rf client
	gcc -Wall -Wextra -Werror client.c ft_itoa.c utils.c -o $(CLIENT)

$(SERVER):
	rm -rf server
	gcc -Wall -Wextra -Werror server.c ft_itoa.c utils.c -o $(SERVER)

all: $(SERVER) $(CLIENT)
	