// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   Asteroid.cpp                                       :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: lberezyn <marvin@42.fr>                    +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2018/04/07 15:36:33 by lberezyn          #+#    #+#             //
/*   Updated: 2018/04/08 14:08:20 by anestor          ###   ########.fr       */
//                                                                            //
// ************************************************************************** //

# include "Game.hpp"

Asteroid::Asteroid()
{
	this->_colType = 4;
	this->_type = 'O';
	this->_x = 2;
	this->_y = 2;
	this->_speed = 0.4;
	this->_alive = false;
}

Asteroid::Asteroid(int x, int y)
{
	this->_colType = 4;
	this->_type = 'O';
	this->_x = x - 2;
	this->_y = std::rand() % y - 2;
	if (this->_y < 2)
		this->_y = 2;
	this->_speed = 0.4;
	this->_alive = false;
}

Asteroid::Asteroid(Asteroid const &src)
{
	*this = src;
}

Asteroid& Asteroid::operator=(Asteroid const &src)
{
	if (this != &src)
	{
		this->_colType = src._colType;
		this->_x = src._x;
		this->_y = src._y;
		this->_speed = src._speed;
		this->_type = src._type;
		this->_alive = src._alive;
	}
	return (*this);
}

Asteroid::~Asteroid()
{

}

void	Asteroid::newAsteroid(int x, int y)
{
	this->_alive = true;
	this->_x = x - 2;
	this->_y = std::rand() % y - 2;
	if (this->_y < 2)
		this->_y = 2;
}

void Asteroid::move(int x, int y)
{
	if (this->_alive == true)
	{
		if (this->checkCollision())
		{
			if ((mvinch(this->_y, this->_x) & A_CHARTEXT) == '-')
			{
				Entity::_score++;
			}
			return ;
		}
		this->erase();
		this->_x -= this->_speed;
		if (this->_x < 1)
			this->_x = x - 2;
		this->draw(x, y);
	}
}
