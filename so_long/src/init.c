 #include "so_long.h"
#include <fcntl.h>

static t_map    *map_init(char *path)
{
    int     fd;
    t_map   *map;

    map = (t_map *) malloc(sizeof(t_map));
    fd = open(path, O_RDONLY);
    map->map = map_constractor(fd, map);
    //if () validate map
    return (map);
}

static t_sprite *sprite_init(t_game *game)
{
    t_sprite *sprite;
    int x;
    int y;

    sprite = (t_sprite *) malloc(sizeof(t_sprite));
    sprite->wall = mlx_xpm_file_to_image(game->mlx, "sprite/wall.xpm", &x, &y);
    sprite->exit = mlx_xpm_file_to_image(game->mlx, "sprite/exit.xpm", &x, &y);
    sprite->tile = mlx_xpm_file_to_image(game->mlx, "sprite/tile.xpm", &x, &y);
    sprite->coin = mlx_xpm_file_to_image(game->mlx, "sprite/coin.xpm", &x, &y);
    sprite->player = mlx_xpm_file_to_image(game->mlx, "sprite/player.xpm", &x, &y);
    sprite->enemy = mlx_xpm_file_to_image(game->mlx, "sprite/enemy.xpm", &x, &y);
    return (sprite);
}

static t_data   *data_init(t_game *game)
{
    t_data  *data;

    data = (t_data *) malloc(sizeof(t_data));
    data->img = mlx_new_image(game->mlx, game->map->x * SCALE,
    game->map->y * SCALE);
    data->addr = mlx_get_data_addr(data->img, &data->bits_per_pixel,
    &data->line_length, &data->endian);
    return (data);
}

t_game *game_init(char *path)
{
    t_game  *game;

    game = (t_game *) malloc(sizeof(t_game));
    game->coin = 0;
    game->moves = 0;
    game->map = map_init(path);
    find_player(game); // tmp
    game->mlx = mlx_init();
    game->win = mlx_new_window(game->mlx,
    SCALE * game->map->x, SCALE * game->map->y, TITLE);
    game->data = data_init(game);
    game->sprite = sprite_init(game);
    draw_map(game, game->map->map);
    return (game);
}