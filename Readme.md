# Tetris

## Projet

Ce jeu a été réalisé en C avec la librairie ncurses, le but était de reproduire le tetris dans un terminal !

## Résultat
![](https://github.com/Noa-Trachez/Tetris/blob/main/images/GIF.gif)

<div style="display: flex; flex-wrap: wrap">
    <img src="/images/hud.png" width=312 height=300 />
    <img src="/images/destroy.png" width=312 height=300 />
</div>

Dans ce jeu, tout est configurable et fonctionnel !

## Jouer au jeu

### Prérequis
    - Ncurses
    - C
    - Make


### Avant de lancer le projet

Usage: ./tetris [options]

Options:

--help               Display this help

-L --level={num}     Start Tetris at level num (def: 1)

-l --key-left={K}    Move the tetrimino LEFT using the K key (def: left arrow)

-r --key-right={K}   Move the tetrimino RIGHT using the K key (def: right arrow)

-t --key-turn={K}    TURN the tetrimino clockwise 90d using the K key (def: top arrow)

-d --key-drop={K}    DROP the tetrimino using the K key (def: down arrow)

-q --key-quit={K}    QUIT the game using the K key (def: `q' key)

-p --key-pause={K}   PAUSE/RESTART the game using the K key (def: space bar)

--map-size={row,col} Set the numbers of rows and columns of the map (def: 20,10)

-w --without-next    Hide next tetrimino (def: false)

-D --debug           Debug mode (def: false)


### Lancer le projet
```bash
make
./tetris
```
