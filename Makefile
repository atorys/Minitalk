#-------------------------NAME--------------------------/
NAME =		clientserver
#------------------------SOURCES------------------------/

INCLUDES =	./

VPATH =		libft \
			files

HEADERS =	minitalk.h \
			libft/libft.h

LIBRARYS	=	libft/libft.a


#--------------------FILES-----------------------------/

CLIENT_FILES =		client.c\
					utils.c
O_CLIENT_FILES = 	$(addprefix objects/, $(CLIENT_FILES:.c=.o))

SERVER_FILES =		server.c\
              		utils.c
O_SERVER_FILES =	$(addprefix objects/, $(SERVER_FILES:.c=.o))

#-------------------BONUS-FILES

B_CLIENT_FILES =	client_bonus.c\
					utils.c
B_O_CLIENT_FILES = 	$(addprefix objects/, $(B_CLIENT_FILES:.c=.o))

B_SERVER_FILES =	server_bonus.c\
              		utils.c
B_O_SERVER_FILES =	$(addprefix objects/, $(B_SERVER_FILES:.c=.o))


#-----------ADDITIONAL--------------------------------/

CFLAGS =	-Wall -Wextra -Werror -O3
BL =		\033[1m\033[32m
W =			\033[38;2;255;255;255
R =			\033[38;2;204;2;2
FPS =		0.02

#-----------RULES-------------------------------------/

.PHONY =	all	clean fclean re

all		:	objects $(O_SERVER_FILES) $(O_CLIENT_FILES) server client

client	:	$(O_CLIENT_FILES) $(LIBRARYS)
			@$(CC) $(CFLAGS) $(O_CLIENT_FILES) $(LIBRARYS) -o client
			@sleep 0.2
			@bash output.sh ">>> " $(FPS) "$(W);1m"; bash output.sh "client " $(FPS) "$(BL)" "$(BL)";
			@bash output.sh "is ready for data exchange" $(FPS)
			@sleep 0.2
			@echo "\n$(W);m           run \033[;1m./client$(W);m [PID] [MESSAGE] >>>\n"

server	:	$(O_SERVER_FILES) $(LIBRARYS)
			@$(CC) $(CFLAGS) $(O_SERVER_FILES) $(LIBRARYS) -o server
			@sleep 0.7
			@clear ; echo ""
			@bash output.sh ">>> " $(FPS) "$(W);1m"; bash output.sh "server " $(FPS) "$(BL)" "$(BL)";
			@bash output.sh "is ready for data exchange" $(FPS)
			@sleep 0.2
			@echo "\n$(W);m           run \033[;1m./server$(W);m to generate PID >>>\n"

bonus	:			objects $(B_O_SERVER_FILES) $(B_O_CLIENT_FILES) server_bonus client_bonus
client_bonus	:	$(B_O_CLIENT_FILES) $(LIBRARYS)
					@$(CC) $(CFLAGS) $(B_O_CLIENT_FILES) $(LIBRARYS) -o client_bonus
					@sleep 0.2
					@bash output.sh ">>> " $(FPS) "$(W);1m"; bash output.sh "client_bonus " $(FPS) "$(BL)" "$(BL)";
					@bash output.sh "is ready for data exchange" $(FPS)
					@sleep 0.2
					@echo "\n$(W);m                 run \033[;1m./client_bonus$(W);m [PID] [MESSAGE] >>>\n"

server_bonus	:	$(B_O_SERVER_FILES) $(LIBRARYS)
					@$(CC) $(CFLAGS) $(B_O_SERVER_FILES) $(LIBRARYS) -o server_bonus
					@sleep 0.7
					@clear ; echo ""
					@bash output.sh ">>> " $(FPS) "$(W);1m"; bash output.sh "server_bonus " $(FPS) "$(BL)" "$(BL)";
					@bash output.sh "is ready for data exchange" $(FPS)
					@sleep 0.2
					@echo "\n$(W);m                 run \033[;1m./server_bonus$(W);m to generate PID >>>\n"

objects :
					@mkdir $@

$(LIBRARYS):
					make -C libft/

objects/%.o :		%.c $(HEADERS)
					gcc $(CFLAGS) -I $(INCLUDES) -c $< -o $@


#-------CLEAN
clean :
			@rm -rf objects/
			@echo "removing [objects] "
			@make clean -C libft/
			@echo "[libft/objects]"

fclean :	clean
			@rm -f server client
			@rm -f server_bonus client_bonus
			@echo "removing [server] [client] [server_bonus] [client_bonus] "
			@make fclean -C libft/
			@echo "[libft]"

re :		fclean all
