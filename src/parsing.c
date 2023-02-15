/*
** EPITECH PROJECT, 2022
** BSQ
** File description:
** BSQ
*/

#include "../include/my.h"

map_t open_map(char *file_path)
{
    map_t map;
    int fd = open(file_path, O_RDONLY);
    int size = size_file(file_path);
    char* map_str;
    if (size == -84 || size == 0) {
        map.error = 84;
        return (map);
    }
    if (fd == -1 || size == -1) {
        map.error = 84;
        return (map);
    }
    map_str = malloc((size + 1) * sizeof(char));
    if (!map_str || read(fd, map_str, size) == -1) {
        map.error = 84;
        return (map);
    }
    map_str[size] = '\0';
    map.map_str = map_str;
    return map;
}

map_t open_map_gen(char *file_path)
{
    map_t map;
    int size = my_strlen(file_path);
    char* map_str;

    map_str = malloc((size + 1) * sizeof(char));
    map_str[size] = '\0';
    map.map_str = map_str;
    return map;
}

int** char_to_nbr(int i, int j, map_t map, int** array_int)
{
    if (map.map_str[map.x] == '.') {
        array_int[i][j] = 1;
    }
    if (map.map_str[map.x] == 'o') {
        array_int[i][j] = 0;
    }
    return array_int;
}

int** array_to_int_array(map_t map)
{
    int x = (first_backslash_n(map) + 1);
    int **array_int = malloc(sizeof(int*) * (map.map_length + 1));

    for (int i = 0; i < map.map_length; i++) {
        array_int[i] = malloc(sizeof(int) * (map.map_width + 1));
        for (int j = 0; j <= map.map_width; j++) {
            map.x = x;
            char_to_nbr(i, j, map, array_int);
            x++;
        }
    }
    return array_int;
}

int** char_to_nbr_gen(int i, int j, map_t map, int** array_int)
{
    if (map.generate_patern[map.x] == '.') {
        array_int[i][j] = 1;
    }
    if (map.generate_patern[map.x] == 'o') {
        array_int[i][j] = 0;
    }
    return array_int;
}
