##
## EPITECH PROJECT, 2021
## Makefile
## File description:
## Makefile (Project)
##

SRC	=	src/main.c \
		src/init/init_ncurses.c \
		src/tetriminos/build_tetriminos.c \
		src/tetriminos/setter_tetriminos.c \
		src/tetriminos/check_shape.c \
		src/tetriminos/check_files.c \
		src/tetriminos/check_tetriminos.c \
		src/tetriminos/rotate.c \
		src/args/check_args.c \
		src/args/set_args.c \
		src/args/check_args_validiti.c \
		src/game/ncurses/hud_printing.c \
		src/game/ncurses/print_ui.c \
		src/game/ncurses/inputs.c \
		src/game/ncurses/physics.c \
		src/game/ncurses/direction.c \
		src/game/ncurses/destroy_row.c \
		src/game/ncurses/spawn_tetriminos.c \
		src/game/ncurses/resize_term.c \
		src/game/ncurses/rotation.c \
		src/debug/compute.c \
		src/debug/display_debug.c \
		src/debug/info_on_tetr.c \
		src/global_loop.c

OBJ	=	$(SRC:.c=.o)

NAME	=	tetris

FLAGS	=	-Wall -Wextra -g

LIB	=	-L lib/ -l my -lncurses

INCLUDE	=	-I include/

CFLAGS	=	-Wall -Wextra $(LIB) $(INCLUDE)

all: build_lib compile

build_lib:
	@make --no-print-directory -C lib/my
	@echo -e "\033[44m#####= LIB COMPILED =#####\e[0m"

compile: $(OBJ)
	@echo -e "\033[1;34m#####= Compiling Project... =#####\e[0m"
	gcc -o $(NAME) $(OBJ) -lncurses $(LIB) $(INCLUDE)
	@echo -e "\033[42m#####= COMPILATION FINISHED =#####\e[0m"

clean:
	@echo -e "\033[1;31m#####= Removing .o files... =#####\e[0m"
	@make clean --no-print-directory -C lib/my
	rm -f $(OBJ)

fclean: clean
	@make fclean --no-print-directory -C lib/my
	@echo -e "\033[1;31m#####= Removing binary file... =#####\e[0m"
	rm -f $(NAME)
	@echo -e "\033[41m#####= CLEANING DONE =#####\e[0m"

re:	fclean all

run: all
	./$(NAME) --map-size 30,30

valgrind:
	gcc -o $(NAME) $(FLAGS) $(SRC) $(LIB) $(INCLUDE) -g
	valgrind ./$(NAME) --map-size 10,30
