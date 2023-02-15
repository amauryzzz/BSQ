/*
** EPITECH PROJECT, 2022
** BSQ
** File description:
** BSQ
*/
#include "../include/my.h"

int** array_to_int_array_gen(map_t map)
{
    int x = 0;
    int **array_int = malloc(sizeof(int*) * (map.map_length + 1));

    for (int i = 0; i < map.map_length; i++) {
        array_int[i] = malloc(sizeof(int) * (map.map_width + 1));
        for (int j = 0; j <= map.map_width; j++) {
            map.x = x;
            char_to_nbr_gen(i, j, map, array_int);
            x++;
        }
    }
    return array_int;
}

int	my_str_isalpha(char *str)
{
    int	i;
    i = 0;
    while (str[i] != '\0') {
        if ((str[i] >= 'A' && str[i] <= 'Z') ||
            (str[i] >= 'a' &&  str[i] <= 'z'))
            i = i + 1;
        else
            return (0);
    }
    return (1);
}
