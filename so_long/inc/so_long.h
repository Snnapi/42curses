#ifndef SO_LONG_H
# define SO_LONG_H

# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include "mlx.h"

# define SCALE 64
# define TITLE "so_long"

typedef struct s_data
{
    void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}   t_data;

typedef struct s_sprite
{
	void	*enemy;
	void	*player;
	void	*coin;
	void	*wall;
	void	*tile;
	void	*exit;
}	t_sprite;

typedef struct s_map
{
    char	**map;
    int		y;
    int		x;
}   t_map;

typedef struct s_game
{
	void	*mlx;
	void	*win;
    int		player_x;
    int		player_y;
	int		enemy_x;
	int		enemy_y;
	int		coin;
	int 	moves;
    t_map	*map;
    t_data	*data;
	t_sprite	*sprite;
}   t_game;

t_game	*game_init(char *path);


char	**map_constractor(int fd, t_map *map);

void	draw_map(t_game *game, char **map);

void	game_hook(t_game *game);

int		key_event(int keycode, t_game *game);
void	render_player(t_game *game);
int		render(t_game *game);
void	draw_sprites(t_game *game, int x, int y);
void	put_data(t_game *game);
void	free_so_long(t_game *game);

//MOVE
int		move_up(t_game *game);
int		move_down(t_game *game);
int		move_left(t_game *game);
int		move_right(t_game *game);
int		random_move_order(t_game *game);

//TMP
void    find_player(t_game *game);

//UTILS
char	*ft_itoa(int nbr);
char	*ft_strdup(char *str);
int		ft_strlen(char *str);

#endif