NAME = libft.a

CFLAGS = -Wall -Wextra -Werror

SRC 		= ft_isalpha ft_isdigit ft_isalnum ft_isascii ft_isprint ft_strlen ft_memset ft_bzero ft_memcpy ft_memmove ft_strlcpy ft_strlcat ft_toupper ft_tolower ft_strchr ft_strrchr ft_strncmp ft_memchr ft_memcmp ft_strnstr ft_atoi ft_calloc ft_strdup \
				ft_substr ft_strjoin ft_strtrim ft_split ft_itoa ft_strmapi ft_striteri ft_putchar_fd ft_putstr_fd ft_putendl_fd ft_putnbr_fd
SRCS		= $(addsuffix .c, $(SRC))

OBJ_DIR		= obj
OBJS		= $(SRCS:%.c=$(OBJ_DIR)/%.o)
BONUS_OBJS	= $(BONUS_SRCS:%.c=$(OBJ_DIR)/%.o)

BONUS_SRC	= ft_lstnew ft_lstadd_front ft_lstsize ft_lstlast ft_lstadd_back ft_lstdelone ft_lstclear ft_lstiter ft_lstmap
BONUS_SRCS	= $(addsuffix _bonus.c, $(BONUS_SRC))

$(OBJ_DIR)/%.o: %.c
	@mkdir -p $(OBJ_DIR)
	@cc ${CFLAGS} -c $< -o $@
# @echo "/// compiling $@.. ///"


all: $(NAME)

# make will try to build missing .o files if a rule for OBJ exist.
# When all dependencies are there it will be executed
# it links all .o files into an exec file called $(NAME)
# $^ represents all the prerequisites, in this case al OBJS
# uses implicite rule for OBJ, see https://www.gnu.org/software/make/manual/html_node/Catalogue-of-Rules.html
$(NAME): $(OBJS) $(BONUS_OBJS)
	@ar -rcs $(NAME) $(OBJS) $(BONUS_OBJS)
	@echo "/// $(NAME) compiled ///"
#	$(CC) $(LFLAGS) -o $(NAME)
# used for leaksanitizer

# bonus: $(BONUS_OBJS)
# 	@ar -rcs $(NAME) 
# 	@echo "/// $(NAME) bonus compiled ///"

clean:
	@rm -rf $(OBJ_DIR)
	@echo "/// cleanin libft ///"

fclean:
	@rm -f $(NAME)
	@echo "/// fcleanin libft ///"

re: fclean all

.PHONY: all bonus clean fclean re