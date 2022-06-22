#include "so_long.h"

void    render_top(t_game *game)
{
    int i;

    i = 0;
    while (i < game->map->x)
        mlx_put_image_to_window(game->mlx, game->win, game->sprite->wall, i++ * SCALE, 0);
}

void    render_enemy(t_game *game)
{
    static int moves;

    if (game->player_x == game->enemy_x && game->player_y == game->enemy_y)
        free_so_long(game);
    mlx_put_image_to_window(game->mlx, game->win, game->sprite->player,
    game->enemy_x * SCALE, game->enemy_y * SCALE);
    if (moves != game->moves)
    {
        moves++;
        random_move_order(game);
    }
}

void    render_player(t_game *game)
{
    mlx_put_image_to_window(game->mlx, game->win, game->sprite->enemy,
    game->player_x * SCALE, game->player_y * SCALE);
}

int render(t_game *game)
{
    draw_map(game, game->map->map);
    render_player(game);
    render_enemy(game);
    if (game->coin == 0 && game->map->map[game->player_y][game->player_x] == 'E')
        free_so_long(game);
    put_data(game);
    return (0);
}