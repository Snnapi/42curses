#include "so_long.h"
#include <limits.h>

int move_up(t_game *game)
{
    int x;
    int y;

    x = game->player_x;
    y = game->player_y;
    if (game->map->map[y - 1][x] == '1')
        return (1);
    else if (game->map->map[y - 1][x] == 'C')
    {
        game->map->map[y - 1][x] = '0';
        game->coin--;
    }
    game->player_y--;
    game->moves++;
    return (0);
}

int move_down(t_game *game)
{
    int x;
    int y;

    x = game->player_x;
    y = game->player_y;
    if (game->map->map[y + 1][x] == '1')
        return (1);
    else if (game->map->map[y + 1][x] == 'C')
    {
        game->map->map[y + 1][x] = '0';
        game->coin--;
    }
    game->player_y++;
    game->moves++;
    return (0);
}

int move_left(t_game *game)
{
    int x;
    int y;

    x = game->player_x;
    y = game->player_y;
    if (game->map->map[y][x - 1] == '1')
        return (1);
    else if (game->map->map[y][x - 1] == 'C')
    {
        game->map->map[y][x - 1] = '0';
        game->coin--;
    }
    game->player_x--;
    game->moves++;
    return (0);
}

int move_right(t_game *game)
{
    int x;
    int y;

    x = game->player_x;
    y = game->player_y;
    if (game->map->map[y][x + 1] == '1')
        return (1);
    else if (game->map->map[y][x + 1] == 'C')
    {
        game->map->map[y][x + 1] = '0';
        game->coin--;
    }
    game->player_x++;
    game->moves++;
    return (0);
}

int random_move_order(t_game *game)
{
    char        **map;
    char        *ptr_a;
    long long   ptr;

    map = game->map->map;
    ptr_a = (char *) malloc(sizeof(char) * 10);
    ptr = (long long ) ptr_a % 7;
    if (ptr < 0)
        ptr *= -1;
    if (ptr % 4 == 0 && map[game->enemy_y][game->enemy_x - 1] != '1')
        game->enemy_x--;
    else if (ptr % 4 == 1 && map[game->enemy_y + 1][game->enemy_x] != '1')
        game->enemy_y++;
    else if (ptr % 4 == 2 && map[game->enemy_y - 1][game->enemy_x] != '1')
        game->enemy_y--;
    else if (ptr % 4 == 3 && map[game->enemy_y][game->enemy_x + 1] != '1')
        game->enemy_x++;
    free(ptr_a);
    return (0);  
}