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
CLIENT_NAME_BONUS = client_bonus 
SERVER_NAME_BONUS = server_bonus

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
UTILS_FILES									+= utils2.c

SRC																	= $(addprefix $(UTILS_PATH), $(UTILS_FILES))
SRC_SERVER													= $(addprefix $(SERVER_PATH), $(SERVER_FILES))
SRC_SERVER													+= $(SRC)
SRC_CLIENT													= $(addprefix $(CLIENT_PATH), $(CLIENT_FILES))
SRC_CLIENT													+= $(SRC)

CLIENT_OBJS_DIR										= obj_client
SERVER_OBJS_DIR										= obj_server
CLIENT_OBJS												= $(patsubst %.c, $(CLIENT_OBJS_DIR)/%.o, $(SRC_CLIENT))
SERVER_OBJS												= $(patsubst %.c, $(SERVER_OBJS_DIR)/%.o, $(SRC_SERVER))

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
 
all: $(CLIENT_NAME) $(SERVER_NAME)

bonus: $(CLIENT_NAME_BONUS) $(SERVER_NAME_BONUS)

$(CLIENT_OBJS_DIR):
	@mkdir -p obj_client
	@echo "📋 Client objects directory created!"

$(CLIENT_OBJS_DIR)/%.o: %.c
	@mkdir -p $(dir $@)
	@$(CC) $(CFLAGS) $(INC) -c $< -o $@

$(SERVER_OBJS_DIR):
	@mkdir -p obj_server
	@echo "📋 Server objects directory created!"

$(SERVER_OBJS_DIR)/%.o: %.c
	@mkdir -p $(dir $@)
	@$(CC) $(CFLAGS) $(INC) -c $< -o $@

$(CLIENT_NAME): $(CLIENT_OBJS_DIR) $(CLIENT_OBJS)
	@$(CC) $(CFLAGS) $(INC) $(CLIENT_OBJS) -o $(CLIENT_NAME)
	@echo "🤎 Client compilation completed!"

$(SERVER_NAME): $(SERVER_OBJS_DIR) $(SERVER_OBJS)
	@$(CC) $(CFLAGS) $(INC) $(SERVER_OBJS) -o $(SERVER_NAME)
	@echo "🤎 Server compilation completed!"

$(CLIENT_NAME_BONUS): $(CLIENT_OBJS_DIR) $(CLIENT_OBJS)
	@$(CC) $(CFLAGS) $(INC) $(CLIENT_OBJS) -o $(CLIENT_NAME_BONUS)
	@echo "🤎 Bonus_client compilation completed!"

$(SERVER_NAME_BONUS): $(SERVER_OBJS_DIR) $(SERVER_OBJS)
	@$(CC) $(CFLAGS) $(INC) $(SERVER_OBJS) -o $(SERVER_NAME_BONUS)
	@echo "🤎 Bonus_server compilation completed!"

clean:
	@$(RM) $(SERVER_OBJS) $(CLIENT_OBJS)
	@echo "🌷 Objects removed successfully!"

fclean: clean
	@$(RM) $(CLIENT_NAME) $(CLIENT_OBJS_DIR)
	@$(RM) $(SERVER_NAME) $(SERVER_OBJS_DIR)
	@$(RM) $(CLIENT_NAME_BONUS) $(CLIENT_OBJS_DIR)
	@$(RM) $(SERVER_NAME_BONUS) $(SERVER_OBJS_DIR)
	@echo "✨ Program removed successfully!"

re: fclean all
		@echo "🦉 Re-compile was successfull!"

.SILENT:
