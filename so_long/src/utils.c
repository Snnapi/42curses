#include "so_long.h"

int ft_strlen(char *str)
{
    int i;

    i = 0;
    while (str[i])
        i++;
    return (i);
}

char *ft_strdup(char *str)
{
    int i;
    char *rtn;

    i = 0;
    rtn = (char *) malloc(sizeof(char) * ft_strlen(str));
    while (i < ft_strlen(str))
    {
        rtn[i] = str[i];
        i++;
    }
    return (rtn);
}

static void fill_array(char *str, int *index, int number)
{
    if (number)
    {
        fill_array(str, index, number / 10);
        str[(*index)] = (number % 10) + 48;
        (*index)++;
        str[(*index)] = '\0';
    }
}

char *ft_itoa(int nbr)
{
    char *str;
    int len;
    int number;

    if (!nbr)
    {
        str = ft_strdup("0");
        return (str);
    }
    number = nbr;
    while (nbr)
    {
        nbr /= 10;
        len++;
    }
    str = (char *) malloc(sizeof(char) * (len + 1));
    len = 0;
    fill_array(str, &len, number);
    return (str);
}