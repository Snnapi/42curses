#include "so_long.h"

void    game_hook(t_game *game)
{
    mlx_hook(game->win, 2, 1L<<0, key_event, game);
    mlx_loop_hook(game->mlx, render, game);
}