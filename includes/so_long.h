/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlariono <dlariono@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/03 19:02:36 by dlariono          #+#    #+#             */
/*   Updated: 2023/06/07 13:29:30 by dlariono         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <stdio.h>
# include <stdlib.h>
# include <fcntl.h>
# include <unistd.h>
# include <stdbool.h>
# include <stddef.h>
# include <stdarg.h>
# include "mlx.h"

typedef struct s_game
{
	void	*mlx;
	void	*window;
	char	**map;
	char	**visited;
	int		pxl;
	int		y;
	int		x;
	int		loop_x;
	int		loop_y;
	int		collect_left;
	int		collect_test;
	int		moves;
	int		is_finished;
	int		has_exit;
	int		size_map_x;
	int		size_map_y;

	int		walls_num;
	int		exits_num;
	int		players_num;

	void	*wall;
	void	*grass;
	void	*collect;
	void	*player;
	void	*exit;

}	t_game;

void	player_start(t_game *game);
void	map_filename(char *file, t_game *game);
void	map_parse_n_test_cpe(char *map_str, t_game *game);
void	map_check_borders_lines(t_game *game);
void	flood_fill(t_game *game, int x, int y);
void	show_error(char code, t_game *game);
void	read_map(int ac, char *file, t_game *game);
void	load_images(t_game *game);

void	init_data(t_game *game);
void	game_actions(t_game *game);
void	render_map(t_game *game);
int		handle_close_btn(t_game *game);
int		handle_key_press(int keycode, t_game *game);

char	**ft_split(char const *s, char c);
size_t	ft_strlen(const char *a);
char	*ft_substr(char const *s, unsigned int start, size_t len);
size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize);

int		ft_putchar(char c);
int		ft_num(unsigned long long nbr, int base, char *str, int mod);
int		convert_var(va_list args, char curr_format);
int		ft_printf(const char *str, ...);

#endif
