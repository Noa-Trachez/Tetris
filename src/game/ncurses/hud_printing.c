/*
** EPITECH PROJECT, 2022
** TETRIS
** File description:
** TODO: description
*/

#include "tetris/tetris.h"
#include <ncurses.h>

int **create_game_array(vector2i mapSize)
{
    int **arr = malloc(sizeof(int *) * (mapSize.y + 1));

    for (int y = 0; y < mapSize.y; y++)
        arr[y] = malloc(sizeof(int) * (mapSize.x + 1));
    for (int y = 0; y < mapSize.y; y++)
        for (int x = 0; x < mapSize.x; x++)
            arr[y][x] = 0;
    return (arr);
}

void next_tetriminos(char **shape)
{
    for (int y = 0; y < 18; y++)
        mvprintw(7 + y, 10, "\n");
    for (int y = 0; shape[y]; y++)
        mvprintw(7 + y, 10, "%s\n", shape[y]);
    print_borders((vector2i){18, 9}, (vector2i){4, 5});
}

void print_level(int level)
{
    mvprintw(20, 5, "DESTROYED : %d", get_global(&g_destroyed_row));
    mvprintw(21, 5, "LEVEL : %d", level);
}

void ncurse(tetris_t *tetris)
{
    int **game = create_game_array(tetris->mapSize);
    int **new = create_game_array(tetris->mapSize);
    vector2i size;
    clock_t start = clock();

    init_ncurses();
    while (get_global(&g_ingame)) {
        if (respawn_tetriminos(&new, tetris->mapSize))
            size = spawn_tetriminos(tetris, &new, &game);
        error_term(tetris);
        get_inputs(tetris, &new, &game, (vector2i[2]){tetris->mapSize, size});
        print_timer(start);
        print_level(tetris->level);
        print_hud();
        print_game(game, tetris->mapSize);
        print_tetriminos(new, tetris->mapSize);
        physic(&game, &new, tetris->mapSize, &tetris->level);
        print_borders(tetris->mapSize, (vector2i){38, 4});
    }
    endwin();
}
