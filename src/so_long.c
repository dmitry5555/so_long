/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlariono <dlariono@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/03 19:53:26 by dlariono          #+#    #+#             */
/*   Updated: 2023/06/07 12:54:48 by dlariono         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	load_images(t_game *game)
{
	game->wall = mlx_xpm_file_to_image(game->mlx, "img/p_wall.xpm",
			&game->pxl, &game->pxl);
	game->grass = mlx_xpm_file_to_image(game->mlx, "img/p_black.xpm",
			&game->pxl, &game->pxl);
	game->collect = mlx_xpm_file_to_image(game->mlx, "img/p_pacdot_food.xpm",
			&game->pxl, &game->pxl);
	game->player = mlx_xpm_file_to_image(game->mlx, "img/ghost_right1.xpm",
			&game->pxl, &game->pxl);
	game->exit = mlx_xpm_file_to_image(game->mlx, "img/p_portal.xpm",
			&game->pxl, &game->pxl);
	game->window = mlx_new_window(game->mlx, game->pxl * game->size_map_x,
			game->pxl * game->size_map_y, "not so long");
}

int	main(int ac, char **av)
{
	t_game	*game;

	game = (t_game *)malloc(sizeof(t_game));
	if (!game)
		return (0);
	init_data(game);
	read_map(ac, av[1], game);
	if (game->players_num != 1 || game->exits_num != 1 || game->collect_left < 1
		|| game->walls_num == 0)
		show_error('c', game);
	map_check_borders_lines(game);
	player_start(game);
	flood_fill(game, game->x, game->y);
	if (!game->has_exit)
		show_error('F', game);
	game->mlx = mlx_init();
	load_images(game);
	render_map(game);
	mlx_key_hook(game->window, handle_key_press, game);
	mlx_hook(game->window, 17, 1L << 5, handle_close_btn, game);
	mlx_loop(game->mlx);
	return (0);
}
