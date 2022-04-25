# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tjalo <tjalo@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/04/06 16:31:03 by tjalo             #+#    #+#              #
#    Updated: 2022/04/25 20:09:58 by tjalo            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC 		= gcc
CFLAGS 	= -Wall -Wextra -Werror -I ./include/
EXEC_C 	= client
EXEC_S 	= server

SRC_C =	./Client/client.c \

SRC_S =	./Server/server.c \

OBJ_C =	$(SRC_C:.c=.o)
OBJ_S =	$(SRC_S:.c=.o)

all : $(EXEC_C) $(EXEC_S) 

$(EXEC_C) : $(OBJ_C)
	@$(CC) $(CFLAGS) -o $(EXEC_C) $(OBJ_C)
	@printf "\e[38;5;46m--------------------------------------\n" 
	@printf "\e[38;5;46m./$@ successfully build 🖥  ✅\e[0m\n" 
	@printf "\e[38;5;46m--------------------------------------\n" 

$(EXEC_S) : $(OBJ_S)
	@$(CC) $(CFLAGS) -o $(EXEC_S) $(OBJ_S)
	@printf "\e[38;5;46m./$@ successfully build 🖥  ✅\e[0m\n"
	@printf "\e[38;5;46m--------------------------------------\n"

%.o : %.c
	@$(CC) $(CFLAGS) -o $@ -c $<
	
clean :
	@rm -rf ./Client/*.o
	@rm -rf ./Server/*.o
	@printf "\e[38;5;206m--------------------------------------\n"
	@printf "\e[38;5;206mAll.o files deleted              🗑  ❌\e[0m\n"
	@printf "\e[38;5;206m--------------------------------------\n"

fclean : clean
	@rm -rf $(EXEC_C)
	@rm -rf $(EXEC_S)
	@printf "\e[38;5;200mProg deleted                     🗑  ❌\e[0m\n"
	@printf "\e[38;5;200m--------------------------------------\n"

re : fclean all