/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlariono <dlariono@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/05 18:22:49 by dlariono          #+#    #+#             */
/*   Updated: 2023/06/07 12:54:51 by dlariono         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	handle_close_btn(t_game *game)
{
	ft_printf("Game closed \n");
	mlx_destroy_window(game->mlx, game->window);
	exit(EXIT_SUCCESS);
}

int	handle_key_press(int keycode, t_game *game)
{
	int	i;

	(void) game;
	i = game->y + game->x;
	if (keycode == 13)
	{
		if (game->map[game->y - 1][game->x] != '1')
			game->y -= 1;
	}
	if (keycode == 1)
		if (game->map[game->y + 1][game->x] != '1')
			game->y += 1;
	if (keycode == 0)
		if (game->map[game->y][game->x - 1] != '1')
			game->x -= 1;
	if (keycode == 2)
		if (game->map[game->y][game->x + 1] != '1')
			game->x += 1;
	if (keycode == 53)
		handle_close_btn(game);
	if (i != game->y + game->x)
		ft_printf("Number of movements: %d \n", ++game->moves);
	render_map(game);
	return (0);
}
