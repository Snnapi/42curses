#include "so_long.h"

int main(int argc, char **argv)
{
    t_game *game;

    game = game_init(argv[1]);
    game_hook(game);
    mlx_loop(game->mlx);
    return (0);
}