/*
** EPITECH PROJECT, 2020
** test
** File description:
** test
*/

#include <stdio.h>

long long compt_nb(int i, char const *str, long long nb)
{
    while (str[i] != '\0') {
        if ((str[i] >= '0') && (str[i] <= '9')) {
            nb = (str[i] - 48) + (nb * 10);
            i++;
        } else {
            return (nb);
            i++;
        }
    }
    return (nb);
}

int extreme(long long nb)
{
    if (nb < -2147483647 || nb > 2147483648) {
        nb = 0;
    }
    return (nb);
}

int calculate(char const *str)
{
    int i = 0;
    int count = 0;
    long long nb = 0;

    while (str[i] == '-' || str[i] == '+') {
        if (str[i] == '-')
            count++;
        i++;
    }
    nb = compt_nb(i, str, nb);
    nb = extreme(nb);
    if (nb != 0) {
        if (count % 2 != 0) {
            nb = nb * (-1);
            return (nb);
        } else {
            return (nb);
        }
    }
    return nb;
}

int my_getnbr(char const *str)
{
    int nb = 0;

    if (str == NULL)
        return -1;
    for (int x = 0; str[x]; x++)
        if ((str[x] < '0' || str[x] >'9') && str[x] != '\n' && str[x] != '-')
            return -1;
    nb = calculate(str);
    return (nb);
}
