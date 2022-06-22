#include "so_long.h"

void    draw_sprites(t_game *game, int x, int y)
{
    char **map;

    map = game->map->map;
    if (map[y][x] == '1')
        mlx_put_image_to_window(game->mlx, game->win, game->sprite->wall, x * SCALE, y * SCALE);
    else if (map[y][x] == '0' || map[y][x] == 'P')
        mlx_put_image_to_window(game->mlx, game->win, game->sprite->tile, x * SCALE, y * SCALE);
    else if (map[y][x] == 'C')
        mlx_put_image_to_window(game->mlx, game->win, game->sprite->coin, x * SCALE, y * SCALE);
    else if (map[y][x] == 'E')
        mlx_put_image_to_window(game->mlx, game->win, game->sprite->exit, x * SCALE, y * SCALE);
}

void    put_data(t_game *game)
{
    char *str;


    str = ft_itoa(game->coin);
    mlx_string_put(game->mlx, game->win, 0, SCALE / 2, 0x00FFFFFF, "COINS: ");
    mlx_string_put(game->mlx, game->win, SCALE - (SCALE / 3), SCALE / 2, 0x00FFFFFF, str);
    free(str);
    str = ft_itoa(game->moves);
    mlx_string_put(game->mlx, game->win, SCALE, SCALE / 2, 0x00FFFFFF, "MOVES: ");
    mlx_string_put(game->mlx, game->win, SCALE * 2 - (SCALE / 3), SCALE / 2, 0x00FFFFFF, str);
    free(str);
}

void    draw_map(t_game *game, char **map)
{
    int i;
    int j;

    i = 0;
    j = 0;
    while (i < game->map->y)
    {
        j = 0;
        while (j < game->map->x)
            draw_sprites(game, j++, i);
        i++;
    }
}