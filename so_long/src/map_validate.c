#include "so_long.h"

void    find_player(t_game *game)
{
    int i = 0;
    int j = 0;
    char **map = game->map->map;

    while (i < game->map->y)
    {
        j = 0;
        while (j < game->map->x)
        {
            if (map[i][j] == 'P')
            {
                game->player_x = j;
                game->player_y = i;
            }
            else if (map[i][j] == 'C')
                game->coin++;
            else if (map[i][j] == 'E')
            {
                game->enemy_x = j;
                game->enemy_y = i;
            }
            j++;
        }
        //printf("%s\n", map[i]);
        i++;
    }
    //printf("height->%d", game->map->y);
    //printf("width->%d", game->map->x);
}