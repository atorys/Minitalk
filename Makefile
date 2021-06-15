#-------------------------NAME--------------------------/
NAME =		clientserver
#------------------------SOURCES------------------------/
INCLUDES =	./

VPATH =		libft \
			files

HEADERS =	minitalk.h \
			libft/libft.h

LIBRARYS	=	libft/libft.a

#----------FILES

CLIENT_FILES = client.c
O_CLIENT_FILES = $(addprefix objects/, $(CLIENT_FILES:.c=.o))

SERVER_FILES = server.c
O_SERVER_FILES = $(addprefix objects/, $(SERVER_FILES:.c=.o))

#-----ADDITIONAL
CFLAGS =	-Wall -Wextra -Werror -O3
Y =			\033[38;2;255;250;166
B =			\033[38;2;181;230;207
BL =		\033[38;2;41;41;41
W =			\033[38;2;255;255;255
G =			\033[38;2;100;247;146
R =			\033[38;2;204;2;2
FPS =		0.02

#--------------------RULES-------------------------------/

.PHONY =	all	clean fclean re

all		:	objects $(O_SERVER_FILES) $(O_CLIENT_FILES) server client

client	:	$(O_CLIENT_FILES) $(LIBRARYS)
			@$(CC) $(CFLAGS) $(O_CLIENT_FILES) $(LIBRARYS) -o client
			@sleep 0.2
			@bash output.sh ">>> " $(FPS) "$(W);1m"; bash output.sh "client " $(FPS) "$(B);1m" "$(B);1m";
			@bash output.sh "is ready for data exchange" $(FPS)
			@sleep 0.2
			@echo "\n$(W);m           run \033[;1m./client$(W);m [PID] [MESSAGE] >>>\n"

server	:	$(O_SERVER_FILES) $(LIBRARYS)
			@$(CC) $(CFLAGS) $(O_SERVER_FILES) $(LIBRARYS) -o server
			@sleep 0.7
			@clear ; echo ""
			@bash output.sh ">>> " $(FPS) "$(W);1m"; bash output.sh "DONE " 0.05 "$(W);1m" "$(W);1m"
			@bash output.sh "<<< " $(FPS) "$(W);1m";clear; echo ""
			@bash output.sh ">>> " $(FPS) "$(W);1m"; bash output.sh "server " $(FPS) "$(Y);1m" "$(Y);1m";
			@bash output.sh "is ready for data exchange" $(FPS)
			@sleep 0.2
			@echo "\n$(W);m           run \033[;1m./server$(W);m to generate PID >>>\n"

objects :
			@mkdir $@

$(LIBRARYS):
			make -C libft/

objects/%.o :		%.c $(HEADERS)
			gcc $(CFLAGS) -I $(INCLUDES) -c $< -o $@


#-------CLEAN
clean :
			@rm -rf objects/

			@bash output.sh "[objects]" $(FPS) "$(BL);1m" "$(R);1m";
			@make clean -C libft/
			@bash output.sh "[libft/objects]" $(FPS) "$(BL);1m" "$(R);1m"

fclean :	clean
			@rm -f server client
			@bash output.sh "[server]" $(FPS) "$(BL);1m" "$(R);1m";
			@bash output.sh "[client]" $(FPS) "$(BL);1m" "$(R);1m" ;
			@make fclean -C libft/
			@bash output.sh "[libft.a]" $(FPS) "$(BL);1m" "$(R);1m" ; echo ""


re :		fclean all
