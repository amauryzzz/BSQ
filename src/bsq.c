/*
** EPITECH PROJECT, 2022
** BSQ
** File description:
** BSQ
*/
#include "../include/my.h"

void reverse_minesweeper(int** array, map_t *map)
{
    map->biggest_square = 0;
    map->i = 0;
    map->j = 0;
    for (int x = 1; x < map->map_length; x++) {
        for (int y = 1; y < map->map_width; y++) {
            sub_minesweeper(array, map, x, y);
        }
    }
}

int bsq (char *str)
{
    map_t map;
    int** array_int;
    char* map_str;

    map = open_map(str);
    if (map.error == 84) {
        return 84;
    }
    map.map_length = get_length(map);
    map.map_width = (my_strlen(map.map_str) / map.map_length) - 1;
    array_int = array_to_int_array(map);
    reverse_minesweeper(array_int, &map);
    map_str = modify_biggest_square(&map);
    my_putstr(map_str);
    return (0);
}

char* bsq_generating(char **av)
{
    map_t map;
    int size = my_atoi(av[1]);
    int patern_size = size * (size + 1);
    map.generate_patern = malloc(patern_size);
    int j = 0;
    int count = 1;
    for (int i = 0; i < patern_size; i++) {
        map.generate_patern[i] = av[2][j];
        if (j == my_strlen(av[2]) - 1)
            j = 0;
        else
            j += 1;
        if (count == size) {
            i++;
            map.generate_patern[i] = '\n';
            count = 1;
        } else
            count += 1;
    }
    return (map.generate_patern);
}

int main(int ac, char **av)
{
    struct stat statbuf;
    map_t map;
    if (ac < 2)
        return (84);
    if (ac > 3)
        return (84);
    if (ac == 3) {
        if (my_str_isalpha(av[1]) == 1)
            return 84;
        if (my_atoi(av[1]) < 0)
            return 84;
        map.generate_patern = bsq_generating(av);
        map.map_length = my_atoi(av[1]);
        bsq_for_gen(map);
    }
    if (ac == 2) {
        if (stat(av[1], &statbuf) == -1)
            return 84;
        bsq(av[1]);
    }
}

int bsq_for_gen(map_t map)
{
    int** array_int;

    map.map_width = (my_strlen(map.generate_patern) / map.map_length) - 1;
    array_int = array_to_int_array_gen(map);
    reverse_minesweeper(array_int, &map);
    map.generate_patern = modify_biggest_square_gen(&map);
    my_putstr(map.generate_patern);
    return (0);
}
