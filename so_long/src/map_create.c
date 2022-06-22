#include "so_long.h"

static char *put_line(char *buffer, int line_length, int y)
{
	char *line;
	int buffer_index;
	int index;

	buffer_index = (line_length * y) + y;
	index = 0;
	line = (char *) malloc(sizeof(char) * line_length);
	while (index < line_length)
		line[index++] = buffer[buffer_index++];
	return (line);
}

static int count_line(char *buffer)
{
	int line;

	line = 0;
	while (buffer[line] && buffer[line] != '\n')
		line++;
	return (line);
}

static int count_nl(char *buffer, int size)
{
	int enter;
	int i;

	i = 0;
	enter = 0;
	while (i < size)
	{
		if (buffer[i] == '\n')
			enter++;
		i++;
	}
	return (enter + 1);
}

static char	**make_map(char *buffer, t_map *tmap, int size)
{
	char **map;
	int y;
	int	enter;
	int line;

	enter = count_nl(buffer, size);
	line = count_line(buffer);
	tmap->y = enter;
	tmap->x = line;
	y = 0;
	map = (char **) malloc(sizeof(char *) * enter);
	while (y < enter)
	{
		map[y] = put_line(buffer, line, y);
		y++;
	}
	return (map);
}

char    **map_constractor(int fd, t_map *map)
{
    char	buffer[10000];
    int     i;
    int     bytes;

    bytes = 1;
    i = 0;
    while (bytes)
    {
        bytes = read(fd, &buffer[i], 1);
        if (bytes == -1)
		{}//   free_so_long(game);
        i++;
    }
    return (make_map(buffer, map, i));
}