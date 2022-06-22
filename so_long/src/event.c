#include "so_long.h"
#include "event.h"

int key_event(int keycode, t_game *game)
{
    int x;
    int y;
    char **map;

    x = game->player_x;
    y = game->player_y;
    map = game->map->map;
    if (ESC == keycode)
    {
        mlx_destroy_window(game->mlx, game->win);
        exit(0);
    }
    else if (W_KEY == keycode || ARROW_UP == keycode)
        move_up(game);
    else if ((A_KEY == keycode || ARROW_LEFT == keycode) && map[y][x - 1] != '1')
        move_left(game);
    else if ((S_KEY == keycode || ARROW_DOWN == keycode) && map[y + 1][x] != '1')
        move_down(game);
    else if ((D_KEY == keycode || ARROW_RIGHT == keycode) && map[y][x + 1] != '1')
        move_right(game);
    return (0);
}