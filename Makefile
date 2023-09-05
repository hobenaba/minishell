# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hindbenabad <hindbenabad@student.42.fr>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/05/23 02:49:56 by nerrakeb          #+#    #+#              #
#    Updated: 2023/09/05 18:09:04 by hindbenabad      ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CFLAGS = -Wall -Wextra -Werror

RDFLAGS +=  -lreadline -L/goinfre/$(USER)/homebrew/opt/readline/lib
INCLUDES += -I /goinfre/$(USER)/homebrew/opt/readline/include

PARSING = my_free.c ft_lst_one.c utils.c parse.c init.c \
		ft_lst_second.c words.c env.c tokens.c lexer.c tokens_exp.c env_saver.c
EXECUTION = exec_bltn.c exec_heredoc.c execution.c exec_pipes.c get_path.c \
			exec_cmd.c exec_helpers.c ft_dup.c env_list_to_tab.c add_to_underscore.c

EXECUTION_EXP = export.c modifie_and_add.c check_exp.c exp_utils.c sort_and_print.c
EXECUTION_RDR = her.c files.c
EXECUTION_BU =  echo.c pwd.c env.c exit.c unset.c utils.c cd.c unset_utils.c
SRCS =	main.c my_fd.c $(addprefix ./parsing/, $(PARSING)) $(addprefix ./execution/, $(EXECUTION)) \
		$(addprefix ./execution/builtins/export/, $(EXECUTION_EXP))  \
		$(addprefix ./execution/redirections/, $(EXECUTION_RDR)) \
		$(addprefix ./execution/builtins/, $(EXECUTION_BU)) signal.c 
		
OBJS = $(SRCS:.c=.o)
LIBFT= libft.a
LIBFT_DIR= libft/
NAME = minishell

$(NAME) : $(OBJS) $(LIBFT)
	@$(CC) $(CFLAGS) $(OBJS) $(LIBFT) -o $(NAME) $(INCLUDES) $(RDFLAGS)
	
	@echo "\033[0;93m- your minishell is getting ready ...\033[0m"

$(LIBFT): $(LIBFT_DIR)libft.h
	@$(MAKE) -C $(LIBFT_DIR)
	@mv $(LIBFT_DIR)$(LIBFT) .

all : $(NAME)

clean :
	@rm -rf $(OBJS)
	@$(MAKE) clean -C $(LIBFT_DIR)
	@echo "\033[1;31m- Object files removed!\033[0m"

fclean : clean
	@rm -rf $(NAME)
	@rm -f $(LIBFT)
	@echo "\033[1;31m all clean\033[0;0m"

re : fclean all

.SILENT : $(OBJS)

.PHONY: all clean fclean re
