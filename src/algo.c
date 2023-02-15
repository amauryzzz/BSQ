/*
** EPITECH PROJECT, 2022
** BSQ
** File description:
** BSQ
*/

#include "../include/my.h"

void my_print_array(char** array, int size)
{
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < my_strlen(array[i]); j++)
            my_putchar(array[i][j]);
    }
    my_putchar('\n');
}

void my_str_to_word_array(map_t *map)
{
    int x = first_backslash_n(*map);
    map->map_array = malloc(sizeof(char) * my_strlen(map->map_str) + 1);

    for (int i = 0; i < map->map_length; i ++) {
        map->map_array[i] = malloc(sizeof(char) * (map->map_width + 1));
        for (int j = 0; j < map->map_width + 1; j++) {
            map->map_array[i][j] = map->map_str[x];
            x++;
        }
    }
}

int first_backslash_n(map_t map)
{
    int len = 0;

    while (map.map_str[len] != '\n')
        len = len + 1;
    return (len);
}

int	my_atoi(char *str)
{
    int	res;
    int	sign;
    int	i;

    res = 0;
    sign = 0;
    i = 0;
    ((str[i] == '-') ? (sign = 1, i++) : (0));
    while (str[i] != '\0') {
        if (str[i] >= '0' && str[i] <= '9') {
            res *= 10;
            res += str[i] - '0';
        } else
            return (res);
        i++;
    }
    if (sign == 0)
        return (res);
    else
        return (-res);
}

void find_minim(int** array_int, int i, int j)
{
    int save_min = array_int[i][j - 1];

    if (array_int[i - 1][j] < save_min) {
        save_min = array_int[i - 1][j];
    }
    if (array_int[i - 1][j - 1] < save_min) {
        save_min = array_int[i - 1][j - 1];
    }
    if (array_int [i][j] != 0)
        array_int[i][j] = save_min + 1;
}
