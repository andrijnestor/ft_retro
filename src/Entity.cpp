// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   Entity.cpp                                         :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: lberezyn <marvin@42.fr>                    +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2018/04/07 15:35:34 by lberezyn          #+#    #+#             //
/*   Updated: 2018/04/08 13:57:29 by anestor          ###   ########.fr       */
//                                                                            //
// ************************************************************************** //

#include "Game.hpp"

int Entity::_score = 0;

Entity::Entity()
{
	this->_type = 'a';
	this->_colType = 1;
	this->_x = 0;
	this->_y = 0;
	this->_speed = 1;
	this->_alive = true;
}

Entity::Entity(Entity const &src)
{
 	*this = src;
}

Entity::~Entity()
{

}

Entity& Entity::operator=(Entity const & src)
{
	this->_type = src._type;
	this->_colType = src._colType;
	this->_x = src._x;
	this->_y = src._y;
	this->_speed = src._speed;
	this->_alive = true;
	return *this;
}

bool	Entity::checkCollision(void)
{
	if ((mvinch(this->_y, this->_x) & A_CHARTEXT) != this->_type
		&& (mvinch(this->_y, this->_x) & A_CHARTEXT) != ' ')
	{
		this->die();
		return (true);
	}
	return (false);
}

void	Entity::setAlive(bool set)
{
	this->_alive = set;
}

void	Entity::setX(float x)
{
	this->_x = x;
}

void	Entity::setY(float y)
{
	this->_y = y;
}

void Entity::die()
{
	this->_alive = false;
}

bool	Entity::isAlive(void)
{
	return(this->_alive);
}

void Entity::draw(int x, int y)
{
	if (this->_x > 0 && this->_y > 0
			&& this->_x <= x && this->_y <= y)
	{
		attron(COLOR_PAIR(this->_colType));
		mvaddch((int)floor(this->_y), (int)floor(this->_x), this->_type);
		attroff(COLOR_PAIR(this->_colType));
	}
}

void	Entity::erase()
{
	mvaddch(floor(this->_y), floor(this->_x), ' ');
}
