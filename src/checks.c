/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checks.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlariono <dlariono@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/03 19:53:24 by dlariono          #+#    #+#             */
/*   Updated: 2023/06/07 13:39:19 by dlariono         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	map_filename(char *file, t_game *game)
{
	int	i;

	i = ft_strlen(file) - 1;
	if (file[i - 2] != 'b' || file[i - 1] != 'e' || file[i] != 'r')
		show_error('.', game);
}

void	map_parse_n_test_cpe(char *str, t_game *game)
{
	int	i;

	i = 0;
	game->map = ft_split(str, '\n');
	game->visited = ft_split(str, '\n');
	while (str[++i])
	{
		if (str[i] != '0' && str[i] != '1' && str[i] != 'C'
			&& str[i] != 'E' && str[i] != 'P' && str[i] != '\n')
			show_error('C', game);
		if (str[i] == '\n' && game->size_map_x == 0)
			game->size_map_x = i;
		if ((str[i] == '\n' && str[i + 1] == '\n') || str[0] == '\n')
			show_error('L', game);
		if (str[i] == '\n')
			game->size_map_y++;
		if (str[i] == '0')
			game->walls_num++;
		if (str[i] == 'C')
			game->collect_left++;
		if (str[i] == 'E')
			game->exits_num++;
		if (str[i] == 'P')
			game->players_num++;
	}
}

void	map_check_borders_lines(t_game *game)
{
	game->loop_y = 0;
	while (game->loop_y < game->size_map_y)
	{
		if ((int)ft_strlen(game->map[game->loop_y]) != game->size_map_x)
			show_error('R', game);
		if (game->map[game->loop_y][0] != '1'
			|| game->map[game->loop_y][game->size_map_x - 1] != '1')
			show_error('B', game);
		game->loop_y++;
	}
	game->loop_x = 0;
	while (game->loop_x < game->size_map_x)
	{
		if (game->map[0][game->loop_x] != '1'
			|| game->map[game->size_map_y - 1][game->loop_x] != '1')
			show_error('b', game);
		game->loop_x++;
	}
	game->loop_x = 0;
	game->loop_y = 0;
}

void	show_error(char code, t_game *game)
{
	if (code == 'C')
		ft_printf("Error\n 🖥 Wrong characters found \n");
	if (code == 'F')
		ft_printf("Error\n 🖥 Map has no correct path (flood fill) \n");
	if (code == 'L')
		ft_printf("Error\n 🖥 Empty lines in the map \n");
	if (code == 'B')
		ft_printf("Error\n 🖥 Wrong map borders (L/R)\n" );
	if (code == 'b')
		ft_printf("Error\n 🖥 Wrong map borders (T/B)\n" );
	if (code == 'R')
		ft_printf("Error\n 🖥 Map is not rectangular \n" );
	if (code == '.')
		ft_printf("Error\n 🖥 File should be in '.ber' format \n" );
	if (code == 'A')
		ft_printf("Error\n 🖥 Wrong map argument \n" );
	if (code == 'f')
		ft_printf("Error\n 🖥 Reading file error");
	if (code == 'c')
		ft_printf("Error\n 🖥 Please check map requirements CPE\n");
	free(game);
	exit(1);
}

void	flood_fill(t_game *game, int x, int y)
{
	if (x < 0 || x >= game->size_map_x || y < 0 || y >= game->size_map_x
		|| game->visited[y][x] == '1')
		return ;
	if (game->visited[y][x] == 'E' && game->collect_test == game->collect_left)
		game->has_exit = 1;
	if (game->visited[y][x] == 'C')
		game->collect_test++;
	if (game->visited[y][x] != '1' && game->visited[y][x] != 'E')
		game->visited[y][x] = '1';
	flood_fill(game, x + 1, y);
	flood_fill(game, x - 1, y);
	flood_fill(game, x, y + 1);
	flood_fill(game, x, y - 1);
}
