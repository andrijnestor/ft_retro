/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Game.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anestor <anestor@student.unit.ua>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/07 16:32:16 by anestor           #+#    #+#             */
/*   Updated: 2018/04/08 13:59:51 by anestor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GAME_HPP
# define GAME_HPP
# include <iostream>
# include <cmath>
# include <ctime>
# include <ncurses.h>
#include <sys/time.h>
#include "Asteroid.hpp"
#include "Enemy.hpp"
#include "Hero.hpp"

# define FPS 60

class Game
{
private:
	WINDOW		*_win;
	Asteroid	*_asteroids;
	int			_ch;
	clock_t		_t1;
	clock_t		_t2;
	Enemy		*_enemies;
	Hero		*_hero;

public:
	bool		_exit;
	int			_maxWinH;
	int			_maxWinW;

	Game();
	Game(Game const & src);
	Game 			&operator=(Game const &);
	~Game();

	int 	getWinW();
	int 	getWinH();
	void	init();
	void	addAsteroid();
	void	addEnemy();
	void	everyBodyMove();
	void	play();
};

#endif
