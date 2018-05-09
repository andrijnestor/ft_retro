/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Hero.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anestor <anestor@student.unit.ua>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/07 16:45:40 by anestor           #+#    #+#             */
/*   Updated: 2018/04/08 13:48:36 by anestor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "Game.hpp"

int Hero::lives = 3;

Hero::Hero()
{
	this->_colType = 3;
	this->_winW = 100;
	this->_winH = 100;
	this->_type = '>';
	this->_x = INIT_POS_X;
	this->_y = INIT_POS_Y;
	this->_speed = 1;
	this->_alive = true;
}

Hero::Hero(int x, int y)
{
	this->_winW = x;
	this->_winH = y;
	this->_colType = 3;
	this->_type = '>';
	this->_x = INIT_POS_X;
	this->_y = INIT_POS_Y;
	this->_speed = 1;
	this->_alive = true;
	this->nBullet = 0;
	this->bullet = new Bullet[50];
	for (int i = 0; i != 50; i++)
		this->bullet[i] = Bullet(this->_x, this->_y, true);
}

Hero::Hero(Hero const &src)
{
	*this = src;;
}

Hero& Hero::operator=(Hero const & src)
{
	if (this != &src)
	{
		this->_type = src._type;
		this->_colType = src._colType;
		this->_alive = src._alive;
		this->_x = src._x;
		this->_y = src._y;
		this->_speed = src._speed;
	}
	return (*this);
}

Hero::~Hero() {

}


void			Hero::draw(int x, int y)
{
	if (this->_alive == true)
	{
		if (this->checkCollision())
		{
			if (((mvinch(this->_y, this->_x) & A_CHARTEXT) == '-') ||
					((mvinch(this->_y, this->_x) & A_CHARTEXT) == 'O') ||
					((mvinch(this->_y, this->_x) & A_CHARTEXT) == '<'))
			{
				Hero::lives--;
			}
			if (Hero::lives > 0)
				this->_alive = true;
			else
				return ;
		}
		if (this->_x > 0 && this->_y > 0
				&& this->_x <= x - 1 && this->_y <= y - 1)
		{
			attron(COLOR_PAIR(this->_colType));
			mvaddch((int)floor(this->_y), (int)floor(this->_x), this->_type);
			attroff(COLOR_PAIR(this->_colType));
		}
		for (int i = 0; i != 50; i++)
			this->bullet[i].move(x, y);
	}
}

void			Hero::operator++()
{
	this->erase();
	this->_x += this->_speed;
	if (this->_x > this->_winW - 2)
		this->_x = this->_winW - 2;
	if (this->checkCollision())
	{
		if (Hero::lives > 0)
			this->_alive = true;
		return ;
	}
	this->draw(this->_winW, this->_winH);
}

void			Hero::operator++(int)
{
	this->erase();
	this->_y += this->_speed;
	if (this->_y > this->_winH - 2)
		this->_y = this->_winH - 2;
	if (this->checkCollision())
	{
		if (Hero::lives > 0)
			this->_alive = true;
		return ;
	}
	this->draw(this->_winW, this->_winH);
}

void			Hero::operator--()
{
	this->erase();
	this->_x -= this->_speed;
	if (this->_x < 1)
		this->_x = 1;
	if (this->checkCollision())
	{
		if (Hero::lives > 0)
			this->_alive = true;
		return ;
	}
	this->draw(this->_winW, this->_winH);
}

void			Hero::operator--(int)
{
	this->erase();
	this->_y -= this->_speed;
	if (this->_y < 2)
		this->_y = 2;
	if (this->checkCollision())
	{
		if (Hero::lives > 0)
			this->_alive = true;
		return ;
	}
	this->draw(this->_winW, this->_winH);
}

void			Hero::attack(void)
{
	this->bullet[nBullet].setX(this->_x + 2);
	this->bullet[nBullet].setY(this->_y);
	this->bullet[nBullet].setAlive(true);
	this->nBullet++;
	if (this->nBullet > 50)
		this->nBullet = 0;
}
