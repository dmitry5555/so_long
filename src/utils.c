/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlariono <dlariono@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/03 19:53:22 by dlariono          #+#    #+#             */
/*   Updated: 2023/06/07 13:29:03 by dlariono         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	init_data(t_game *game)
{
	game->pxl = 32;
	game->y = 0;
	game->x = 0;
	game->loop_x = 0;
	game->loop_y = 0;
	game->is_finished = 0;
	game->collect_left = 0;
	game->collect_test = 0;
	game->size_map_x = 0;
	game->size_map_y = 0;
	game->walls_num = 0;
	game->exits_num = 0;
	game->players_num = 0;
	game->moves = 0;
	game->has_exit = 0;
}

void	player_start(t_game *game)
{
	while (game->map[game->loop_y])
	{
		game->loop_x = 0;
		while (game->map[game->loop_y][game->loop_x])
		{
			if (game->map[game->loop_y][game->loop_x] == 'P')
			{
				game->x = game->loop_x;
				game->y = game->loop_y;
			}
			game->loop_x++;
		}
		game->loop_y++;
	}
	game->loop_y = 0;
	game->loop_x = 0;
}

void	game_actions(t_game *game)
{
	game->loop_x = 0;
	game->loop_y = 0;
	if (game->map[game->y][game->x] == 'C')
	{
		game->map[game->y][game->x] = '0';
		game->collect_left--;
	}
	if (game->map[game->y][game->x] == 'E' && game->collect_left == 0)
	{
		mlx_destroy_window(game->mlx, game->window);
		free(game);
		exit(EXIT_SUCCESS);
	}
}

void	render_map(t_game *game)
{
	while (game->map[game->loop_y])
	{
		game->loop_x = 0;
		while (game->map[game->loop_y][game->loop_x])
		{
			if (game->map[game->loop_y][game->loop_x] == '1')
				mlx_put_image_to_window(game->mlx, game->window, game->wall,
					game->pxl * game->loop_x, game->pxl * game->loop_y);
			if (game->map[game->loop_y][game->loop_x] == '0'
				|| game->map[game->loop_y][game->loop_x] == 'P')
				mlx_put_image_to_window(game->mlx, game->window, game->grass,
					game->pxl * game->loop_x, game->pxl * game->loop_y);
			if (game->map[game->loop_y][game->loop_x] == 'C')
				mlx_put_image_to_window(game->mlx, game->window, game->collect,
					game->pxl * game->loop_x, game->pxl * game->loop_y);
			if (game->map[game->loop_y][game->loop_x] == 'E')
				mlx_put_image_to_window(game->mlx, game->window, game->exit,
					game->pxl * game->loop_x, game->pxl * game->loop_y);
			game->loop_x++;
		}
		game->loop_y++;
	}
	game_actions(game);
	mlx_put_image_to_window(game->mlx, game->window, game->player,
		game->pxl * game->x, game->pxl * game->y);
}

void	read_map(int ac, char *file, t_game *game)
{
	int		count;
	int		fd;
	char	*str;
	char	c;

	count = 0;
	if (ac != 2)
		show_error('A', game);
	map_filename(file, game);
	fd = open(file, O_RDONLY);
	if (fd < 0)
		show_error('f', game);
	while (read(fd, &c, 1) == 1)
		count++;
	close(fd);
	str = (char *)malloc(sizeof(char) * (count + 2));
	if (!str)
		return ;
	fd = open(file, O_RDONLY);
	read(fd, str, count);
	str[count] = '\n';
	str[count + 1] = '\0';
	close(fd);
	map_parse_n_test_cpe(str, game);
	free(str);
}
