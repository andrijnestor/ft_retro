// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   Game.cpp                                           :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: lberezyn <marvin@42.fr>                    +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2018/04/08 09:25:46 by lberezyn          #+#    #+#             //
/*   Updated: 2018/05/09 15:48:43 by anestor          ###   ########.fr       */
//                                                                            //
// ************************************************************************** //

# include "Game.hpp"

Game::Game()
{
	return ;
}

Game::Game(Game const &src)
{
	*this = src;
}

Game & Game::operator=(Game const & src)
{
	this->_maxWinH = src._maxWinH;
	this->_maxWinW = src._maxWinW;
	this->_exit = false;
	return *this;
}

Game::~Game()
{
	int x = (_maxWinW - 10)/ 2;
	int y = _maxWinH / 2;

	move(y, x);
	printw("~* GAME OVER *~");
	while (getch() != 27);
	endwin();
	std::cout << "~* GAME OVER *~" << std::endl;
}

int Game::getWinW()
{
	return(Game::_maxWinW);
}

int Game::getWinH()
{
	return(Game::_maxWinH);
}

void Game::init()
{
	initscr();
	start_color();
	cbreak();
	keypad(stdscr, TRUE);
	noecho();
	curs_set(0);
	init_pair(1, COLOR_CYAN, COLOR_BLACK);
	init_pair(2, COLOR_RED, COLOR_BLACK);
	init_pair(3, COLOR_YELLOW, COLOR_BLACK);
	init_pair(4, COLOR_GREEN, COLOR_BLACK);
	_win = newwin(0, 0, 0, 0);
	keypad(_win, true);
	nodelay(_win, true);
	getmaxyx(_win, _maxWinH, _maxWinW);
	_exit = false;
	_asteroids = new Asteroid[50];
	_enemies = new Enemy[30];
}

void Game::addAsteroid()
{
	for (int i = 0; i < 50; ++i)
	{
		if (clock() % 200 == 0)
			if (this->_asteroids[i].isAlive() == false)
				this->_asteroids[i].newAsteroid(this->_maxWinW, this->_maxWinH);
	}
}

void Game::addEnemy()
{
	for (int i = 0; i < 30; ++i)
	{
		if (clock() % 200 == 0)
			if (this->_enemies[i].isAlive() == false)
				this->_enemies[i].newEnemy(this->_maxWinW, this->_maxWinH);
	}
}

void Game::play()
{
	Entity::_score = 0;
	init();
	long long time = 0;
	_hero = new Hero(this->_maxWinW, this->_maxWinH);
	while(!_exit)
	{
		getmaxyx(this->_win, this->_maxWinH, this->_maxWinW);
		this->_t1 = clock() / (CLOCKS_PER_SEC / FPS);
		if (this->_t1 > this->_t2)
		{
			time++;
			this->_t2 = (clock() / (CLOCKS_PER_SEC / FPS));
			this->_ch = wgetch(this->_win);
			addAsteroid();
			addEnemy();
			switch(_ch)
			{
				case KEY_LEFT:
					--(*_hero);
					break;
				case KEY_RIGHT:
					++(*_hero);
					break;
				case KEY_UP:
					(*_hero)--;
					break;
				case KEY_DOWN:
					(*_hero)++;
					break;
				case 27:
					_exit = true;
					break;
				case ' ':
					_hero->attack();
					break;
			}
			_hero->draw(_maxWinW, _maxWinH);
			if (Hero::lives <= 0)
				_exit = true;
			everyBodyMove();
			move(1, 1);
			printw("SCORE: %d", Entity::_score);
			move(1, 20);
			printw("LIVES: %d", Hero::lives);
			move(1, 40);
			printw("TIME: %d", time / FPS);
			refresh();
		}
	}
}

void Game::everyBodyMove() {
	for (int i = 0; i < 50; i++)
	{
		_asteroids[i].move(getWinW(), getWinH());
	}
	for (int i = 0; i < 30; ++i)
	{
		_enemies[i].move(getWinW(), getWinH());
	}
}
