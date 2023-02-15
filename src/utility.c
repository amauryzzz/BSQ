/*
** EPITECH PROJECT, 2022
** BSQ
** File description:
** BSQ
*/
#include "../include/my.h"

void my_putchar(char c)
{
    write(1, &c, 1);
}

int	my_putstr(char *str)
{
    while (*str != '\0') {
        my_putchar(*str);
        str++;
    }
    return (1);
}

int size_file(char const *file_path)
{
    int size;
    struct stat statbuf;

    if (stat(file_path, &statbuf) == -1) {
        return (-84);
    }
    if (statbuf.st_size == 0) {
        return (-84);
    }
    size = statbuf.st_size;
    return (size);
}

int my_strlen(char* str)
{
    int len;

    len = 0;
    while (str[len] != '\0')
        len = len + 1;
    return (len);
}

void my_putnbr(int x)
{
    int modulo;

    if (x <= 9 && x >= 0) {
        my_putchar(x + '0');
    }
    if (x < 0) {
        my_putchar('-');
        x = x * (- 1);
        if (x <= 9 && x >= 0)
            my_putnbr(x);
    }
    if (x > 9) {
        modulo = x % 10;
        my_putnbr(x / 10);
        my_putchar(modulo + '0');
    }
}
