// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   bullet.cpp                                         :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: lberezyn <marvin@42.fr>                    +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2018/04/07 17:00:55 by lberezyn          #+#    #+#             //
/*   Updated: 2018/05/09 15:47:45 by anestor          ###   ########.fr       */
//                                                                            //
// ************************************************************************** //

# include "Game.hpp"

Bullet::Bullet(void)
{
	this->_colType = 2;
	this->_x = 0;
	this->_y = 0;
	this->_speed = 0.5;
	this->_dir = true;
	this->_type = '-';
	this->_alive = false;
}

Bullet::Bullet(int x, int y, bool dir)
{
	this->_colType = 2;
	if (dir)
		this->_x = x + 3;
	else
		this->_x = x - 3;
	this->_y = y;
	this->_speed = 0.5;
	this->_dir = dir;
	this->_type = '-';
	this->_alive = false;
}

Bullet::Bullet(Bullet const &src)
{
	*this = src;
}

Bullet::~Bullet()
{

}

Bullet& Bullet::operator=(Bullet const & src)
{
	if (this != &src)
	{
		this->_colType = src._colType;
		this->_x = src._x;
		this->_y = src._y;
		this->_speed = src._speed;
		this->_dir = src._dir;
		this->_type = src._type;
		this->_alive = src._alive;
	}
	return (*this);
}

void Bullet::move(int x, int y)
{
	if (this->_alive == true)
	{
		this->erase();
		if (!_dir)
			this->_x -= this->_speed;
		else
			this->_x += this->_speed;
		if (this->_x > -1 && this->_x < x - 1)
			this->draw(x, y);
		if (this->_x > x - 1 || this->_x < 0)
			this->die();
	}
}
