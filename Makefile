# **************************************************************************** #
#                                    Config                                    #
# **************************************************************************** #

MAKE = make --no-print-directory --silent
SHELL = bash

# **************************************************************************** #
#                                    Names                                     #
# **************************************************************************** #

CLIENT_NAME = client 
SERVER_NAME = server

# **************************************************************************** #
#                                    Paths                                     #
# **************************************************************************** #

INC_PATH										= ./includes/

SRC_PATH										= ./src/

SERVER_PATH									= $(SRC_PATH)server/

SERVER_FILES								= server.c

CLIENT_PATH									= $(SRC_PATH)client/

CLIENT_FILES								= client.c

UTILS_PATH									= $(SRC_PATH)utils/

UTILS_FILES									= utils.c

SRC													= $(addprefix $(SRC_PATH), $(SRC_FILES))
SRC													+= $(addprefix $(SERVER_PATH), $(SERVER_FILES))
SRC													+= $(addprefix $(CLIENT_PATH), $(CLIENT_FILES))C													+= $(addprefix $(CLIENT_PATH), $(CLIENT_FILES))
SRC													+= $(addprefix $(UTILS_PATH), $(UTILS_FILES))

OBJS_DIR										= obj
OBJS												= $(patsubst %.c, $(OBJS_DIR)/%.o, $(SRC))

# **************************************************************************** #
#                                   Compiler                                   #
# **************************************************************************** #

CC						           = cc
CFLAGS		        		   = -Wall -Wextra -Werror -g
INC            		       = -I $(INC_PATH)

# **************************************************************************** #
#                                   Commands                                   #
# **************************************************************************** #

RM              = rm -rf

# **************************************************************************** #
#                                    Rules                                     #
# **************************************************************************** #
 
intro: 
	@echo "\033[1;35m✿.•° ✧°•.✿.•° ✧°•.✿.•° ✧°•.✿\033[0m"
	@echo "\033[1;35m███╗   ███╗██╗███╗   ██╗██╗████████╗ █████╗ ██╗      ██╗  ██╗\033[0m"
	@echo "\033[1;35m████╗ ████║██║████╗  ██║██║╚══██╔══╝██╔══██╗██║      ██║ ██╔╝\033[0m"
	@echo "\033[1;35m██╔████╔██║██║██╔██╗ ██║██║   ██║   ███████║██║      █████╔╝ \033[0m"
	@echo "\033[1;35m██║╚██╔╝██║██║██║╚██╗██║██║   ██║   ██╔══██║██║      ██╔═██╗ \033[0m"
	@echo "\033[1;35m██║ ╚═╝ ██║██║██║ ╚████║██║   ██║   ██║  ██║███████╗ ██║  ██╗\033[0m"
	@echo "\033[1;35m╚═╝     ╚═╝╚═╝╚═╝  ╚═══╝╚═╝   ╚═╝   ╚═╝  ╚═╝╚══════╝ ╚═╝  ╚═╝\033[0m"
	@echo "\033[1;36m｡･:*:･ﾟ★,｡･:*:･ﾟ☆   M I N I T A L K   ☆ﾟ･:*:･｡,★ﾟ･:*:･｡\033[0m"
	@echo "\033[1;35m✿.•° ✧°•.✿.•° ✧°•.✿.•° ✧°•.✿\033[0m"


all: intro $(NAME)

$(OBJS_DIR):
	@mkdir -p obj
	@echo "📋 Objects directory created!"

$(OBJS_DIR)/%.o: %.c
	@mkdir -p $(dir $@)
	@$(CC) $(CFLAGS) $(INC) -c $< -o $@

$(NAME): $(OBJS_DIR) $(OBJS)
	@$(CC) $(CFLAGS) $(INC) $(OBJS) -o $(NAME)
	@echo "🤎 Compilation completed!"

clean:
	@$(RM) $(OBJS)
	@echo "🌷 Objects removed successfully!"

fclean: clean
	@$(RM) $(NAME) $(OBJS_DIR)
	@echo "✨ Program removed successfully!"

re: fclean all
		@echo "🦉 Re-compile was successfull!"

.SILENT:
