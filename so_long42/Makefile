
NAME = so_long

BINS_PATH = ./bin/
NAME = ${BINS_PATH}so_long


CC = cc
CFLAGS = -Wall -Wextra -Werror -g3

LFLAGS = -lft -lftprintf -lmlx -lmlx_Linux -lX11 -lXext -lm


REMOVE = rm -rf

MKDIR = mkdir -p


SRCS_PATH =  ./srcs/
OBJS_PATH = ./objs/
LIBS_PATH = ./libs/
BINS_PATH = ./bin/
HEADER_PATH = ./include/
GNL_PATH = $(LIBS_PATH)get_next_line/


LIBFT_PATH = $(LIBS_PATH)libft/
PRINTF_PATH = $(LIBS_PATH)libftprintf/
MLX_PATH = $(LIBS_PATH)mlx/


SRCS_FILES = count_elements.c \
	free_memory.c \
	init.c \
	so_long.c \
	map_handling.c \
	movement.c \
	render.c \
	solvability.c

GNL_SRCS_FILES = $(GNL_PATH)get_next_line.c \
	$(GNL_PATH)get_next_line_utils.c


OBJS_FILES = $(patsubst %.c, $(OBJS_PATH)%.o, $(SRCS_FILES)) \
	$(patsubst $(GNL_PATH)%.c, $(OBJS_PATH)%.o, $(GNL_SRCS_FILES))


INCLUDES = -I $(LIBFT_PATH) -I $(MLX_PATH) -I$(PRINTF_PATH)

PATH_LIBS = -L$(LIBFT_PATH) -L$(MLX_PATH) -L$(PRINTF_PATH)


all : $(NAME)


$(NAME) : $(OBJS_FILES)
	$(MKDIR) $(BINS_PATH)
	make -C $(LIBFT_PATH) --no-print-directory
	make -C $(PRINTF_PATH) --no-print-directory
	make -C $(MLX_PATH) --no-print-directory
	$(CC) $(CFLAGS) $(OBJS_FILES) -o $(NAME) $(PATH_LIBS) $(LFLAGS)


$(OBJS_PATH)%.o : $(SRCS_PATH)%.c
	$(MKDIR) $(OBJS_PATH)
	$(CC) $(CFLAGS) -I $(HEADER_PATH) -c $< -o $@


$(OBJS_PATH)%.o : $(GNL_PATH)%.c
	$(MKDIR) $(OBJS_PATH)
	$(CC) $(CFLAGS) -I $(HEADER_PATH) -c $< -o $@


clean :
	@$(REMOVE) $(OBJS_PATH)
	@make clean -C $(LIBFT_PATH) --no-print-directory
	@make clean -C $(PRINTF_PATH) --no-print-directory
	@make clean -C $(MLX_PATH) --no-print-directory


fclean : clean
	@$(REMOVE) $(NAME) $(BINS_PATH) $(OBJS_PATH)
	@make fclean -C $(LIBFT_PATH) --no-print-directory
	@make fclean -C $(PRINTF_PATH) --no-print-directory
	@make clean -C $(MLX_PATH) --no-print-directory


re : fclean all

# Phony targets
.PHONY : all clean fclean re
