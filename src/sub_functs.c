/*
** EPITECH PROJECT, 2022
** BSQ
** File description:
** BSQ
*/
#include "../include/my.h"

void sub_minesweeper(int** array, map_t *map, int x, int y)
{
    find_minim(array, x, y);
    if (array[x][y] > map->biggest_square) {
        map->i = x;
        map->j = y;
        map->biggest_square = array[x][y];
    }
}

int check_map_characters(map_t map)
{
    for (int i = 0; i < my_strlen(map.map_str); i++) {
        if (map.map_str[i] != '.' && map.map_str[i] != 'o'
        && map.map_str[i] != '\n') {
            return 84;
        }
    }
    return 0;
}

int get_length(map_t map)
{
    int length = 0;
    int i = 0;

    while (map.map_str[i] >= '0' && map.map_str[i] <= '9') {
        length = length * 10 + map.map_str[i++] - '0';
    }
    if (map.map_str[i] != '\n') {
        map.error_int = 84;
        return map.error_int;
    }
    map.map_length = length;
    return (map.map_length);
}

char* modify_biggest_square(map_t *map)
{
    char* map_str = map->map_str + first_backslash_n(*map) + 1;
    for (int i = 0, x = 0; x < map->biggest_square; ++x) {
        i = (map->i - x) * map->map_width + map->i - x;
        for (int j = map->j, y = 0; y < map->biggest_square; --j, ++y) {
            map_str[i + j] = 'x';
        }
    }
    return map_str;
}

char* modify_biggest_square_gen(map_t *map)
{
    for (int i = 0, x = 0; x < map->biggest_square; ++x) {
        i = (map->i - x) * map->map_width + map->i - x;
        for (int j = map->j, y = 0; y < map->biggest_square; --j, ++y) {
            map->generate_patern[i + j] = 'x';
        }
    }
    return map->generate_patern;
}
