/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   steps.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gjacqual <gjacqual@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/22 03:35:59 by gjacqual          #+#    #+#             */
/*   Updated: 2022/01/24 11:30:42 by gjacqual         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

int	step_conditions(t_game *game, int y_pos, int x_pos)
{
	char	*cur_pos;
	char	*step_pos;

	cur_pos = &game->map[game->player_y_pos][game->player_x_pos];
	step_pos = &game->map[y_pos][x_pos];
	if (*step_pos == WALL_EL)
		return (0);
	if (*step_pos == ENEMY_EL)
	{
		game->died = 1;
		game->the_end = 1;
		return (0);
	}
	if (*step_pos == EXIT_EL)
	{
		if (game->collect != game->elements.coin_el)
			return (0);
		else
		{
			game->passed = 1;
			return (1);
		}
	}
	return (1);
}

void	player_steps(t_game *game, int y_pos, int x_pos)
{
	char	*cur_pos;
	char	*step_pos;

	cur_pos = &game->map[game->player_y_pos][game->player_x_pos];
	step_pos = &game->map[y_pos][x_pos];
	if (game->passed == 0)
	{
		*cur_pos = EMPTY_EL;
		if (*step_pos == COIN_EL)
			game->collect++;
		*step_pos = PLAYER_EL;
		game->player_x_pos = x_pos;
		game->player_y_pos = y_pos;
		game->moves++;
	}
	else if (game->passed == 1)
	{
		*cur_pos = EMPTY_EL;
		*step_pos = PLAYER_EL;
		game->moves++;
		game->the_end = 1;
	}
}
