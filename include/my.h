/*
** EPITECH PROJECT, 2022
** BSQ - my.h
** File description:
** my.h
*/
#ifndef MY_H
    #define MY_H
    #include <stdio.h>
    #include <sys/stat.h>
    #include <pwd.h>
    #include <grp.h>
    #include <time.h>
    #include <unistd.h>
    #include <dirent.h>
    #include <stdlib.h>
    #include <fcntl.h>

typedef struct map_s {
    char* map_arg;
    char* map_str;
    char** map_array;
    int** map_array_int;
    int map_width;
    int map_length;
    int error;
    int error_int;
    int biggest_square;
    int i;
    int j;
    int x;
    char* generate_patern;
    int generate_patern_size;
    int sub_i;
} map_t;

void find_minim(int** array_int, int i, int j);
void reverse_minesweeper(int** array, map_t *map);
char* modify_biggest_square(map_t *map);
map_t open_map(char *file_path);
void my_str_to_word_array(map_t *map);
int first_backslash_n(map_t map);
int** array_to_int_array(map_t map);
int get_length(map_t map);
void my_print_array(char** array, int size);
void my_putchar(char c);
int	my_putstr(char *str);
int size_file(char const *file_path);
int check_args_gen(char **av);
int	my_str_isalpha(char *str);
int my_strlen(char* str);
void my_putnbr(int x);
int error_handling(char *av);
char* bsq_generating(char **av);
int my_atoi(char *str);
void sub_minesweeper(int** array, map_t *map, int x, int y);
int check_map_characters(map_t map);
int get_length_after_gen(map_t map);
int bsq_for_gen (map_t map);
map_t open_map_gen(char *file_path);
int** array_to_int_array_gen(map_t map);
char* modify_biggest_square_gen(map_t *map);
int** char_to_nbr_gen(int i, int j, map_t map, int** array_int);

#endif
