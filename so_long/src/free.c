#include "so_long.h"

static void    free_map(char **map, int y)
{
    int i;

    i = 0;
    while (i < y)
        free(map[i++]);
}

void    free_so_long(t_game *game)
{
    if (game->map->map)
        free_map(game->map->map, game->map->y);
    if (game->map)
        free(game->map);
    if (game->data)
        free(game->data);
    if (game->sprite)
        free(game->sprite);
    mlx_destroy_window(game->mlx, game->win);
    if (game)
        free(game);
    exit(0);
}