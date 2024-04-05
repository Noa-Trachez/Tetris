##
## EPITECH PROJECT, 2021
## Makefile
## File description:
## Makefile (Lib)
##

INPUT	=	input/my_getnbr.c

LINKED_LISTS	= linked_lists/my_append_node.c \
			linked_lists/my_revprint_list.c \
			linked_lists/my_print_list.c \
			linked_lists/my_delete_node.c

MATHS	=	maths/my_factorial.c \
			maths/my_pow.c \
			maths/my_sqrt.c

MISC	=	misc/my_swap.c \
			misc/free_array.c

OUTPUT	=	output/my_put_nbr.c \
			output/my_putchar.c \
			output/my_putstr.c \
			output/my_show_word_array.c

STRCHECK	=	strcheck/my_char_isalpha.c \
			strcheck/my_char_isnum.c \
			strcheck/my_char_isprintable.c \
			strcheck/my_str_isalpha.c \
			strcheck/my_str_islower.c \
			strcheck/my_str_isnum.c \
			strcheck/my_str_isprintable.c \
			strcheck/my_str_isupper.c \
			strcheck/my_strcindex.c \
			strcheck/my_strcmp.c \
			strcheck/my_strcontains.c \
			strcheck/my_strlen.c \
			strcheck/my_strncmp.c \
			strcheck/my_strstr.c

STRMODIF	=	strmodif/my_memset.c \
			strmodif/my_revarr.c \
			strmodif/my_revstr.c \
			strmodif/my_strappend.c \
			strmodif/my_strarr.c \
			strmodif/my_strcapitalize.c \
			strmodif/my_strcat.c \
			strmodif/my_strcpy.c \
			strmodif/my_strdup.c \
			strmodif/my_strinsert.c \
			strmodif/my_strlowcase.c \
			strmodif/my_strncat.c \
			strmodif/my_strncpy.c \
			strmodif/my_strpop.c \
			strmodif/my_strupcase.c \
			strmodif/dup_double_array.c \

GLOBALS		= globals/globals_methods.c

OBJ		=	$(INPUT:.c=.o) \
			$(LINKED_LISTS:.c=.o) \
			$(MATHS:.c=.o) \
			$(MISC:.c=.o) \
			$(OUTPUT:.c=.o) \
			$(STRCHECK:.c=.o) \
			$(STRMODIF:.c=.o) \
			$(GLOBALS:.c=.o) \

NAME =		libmy.a

FLAGS	=	-Wall -Wextra

all: build header

build: $(OBJ)
	@echo -e "\033[1;34m#####= Creating library... =#####\e[0m"
	ar rc $(NAME) $(OBJ)
	@ranlib $(NAME)
	@cp $(NAME) ../
	@mv $(NAME) ".."

header:
	@mkdir -p ../../include
	@cp include/*.h ../../include
	@mkdir -p ../../include/lib
	@cp include/lib/*.h ../../include/lib

clean:
	rm -f $(OBJ)

fclean:
	@echo -e "\033[1;31m#####= Deleting library... =#####\e[0m"
	rm -f ../$(NAME)
	rm -f ../../$(NAME)

re:	fclean all
