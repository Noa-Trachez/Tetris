cmake_minimum_required(VERSION 3.27)
project(tetris C)

set(CMAKE_C_STANDARD 11)

include_directories(include)

add_library(my STATIC
        lib/my/misc/free_array.c
        lib/my/misc/my_swap.c
        lib/my/globals/globals_methods.c
        lib/my/input/my_getnbr.c
        lib/my/output/my_show_word_array.c
        lib/my/output/my_putchar.c
        lib/my/output/my_putstr.c
        lib/my/output/my_put_nbr.c
        lib/my/strcheck/my_char_isnum.c
        lib/my/strcheck/my_strstr.c
        lib/my/strcheck/my_strcindex.c
        lib/my/strcheck/my_strncmp.c
        lib/my/strcheck/my_str_isprintable.c
        lib/my/strcheck/my_strlen.c
        lib/my/strcheck/my_str_islower.c
        lib/my/strcheck/my_str_isnum.c
        lib/my/strcheck/my_strcmp.c
        lib/my/strcheck/my_str_isalpha.c
        lib/my/strcheck/my_char_isprintable.c
        lib/my/strcheck/my_strcontains.c
        lib/my/strcheck/my_char_isalpha.c
        lib/my/strcheck/my_str_isupper.c
        lib/my/linked_lists/my_delete_node.c
        lib/my/linked_lists/my_append_node.c
        lib/my/linked_lists/my_revprint_list.c
        lib/my/linked_lists/my_print_list.c
        lib/my/maths/my_pow.c
        lib/my/maths/my_sqrt.c
        lib/my/maths/my_factorial.c
        lib/my/strmodif/my_revarr.c
        lib/my/strmodif/my_strlowcase.c
        lib/my/strmodif/my_strappend.c
        lib/my/strmodif/my_strncpy.c
        lib/my/strmodif/my_strcat.c
        lib/my/strmodif/my_str_to_word_array.c
        lib/my/strmodif/my_strpop.c
        lib/my/strmodif/my_strinsert.c
        lib/my/strmodif/my_strdup.c
        lib/my/strmodif/my_strupcase.c
        lib/my/strmodif/my_strcpy.c
        lib/my/strmodif/my_strcapitalize.c
        lib/my/strmodif/my_memset.c
        lib/my/strmodif/dup_double_array.c
        lib/my/strmodif/my_strarr.c
        lib/my/strmodif/my_strncat.c
        lib/my/strmodif/my_revstr.c
)

add_executable(tetris
        src/args/check_args.c
        src/args/check_args_validiti.c
        src/args/set_args.c
        src/debug/compute.c
        src/debug/display_debug.c
        src/debug/info_on_tetr.c
        src/game/ncurses/destroy_row.c
        src/game/ncurses/direction.c
        src/game/ncurses/hud_printing.c
        src/game/ncurses/inputs.c
        src/game/ncurses/physics.c
        src/game/ncurses/print_ui.c
        src/game/ncurses/resize_term.c
        src/game/ncurses/rotation.c
        src/game/ncurses/spawn_tetriminos.c
        src/init/init_ncurses.c
        src/tetriminos/build_tetriminos.c
        src/tetriminos/check_files.c
        src/tetriminos/check_shape.c
        src/tetriminos/check_tetriminos.c
        src/tetriminos/rotate.c
        src/tetriminos/setter_tetriminos.c
        src/global_loop.c
        src/main.c)

target_link_libraries(tetris my ncurses)