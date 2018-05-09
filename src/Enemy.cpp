// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   Enemy.cpp                                          :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: lberezyn <marvin@42.fr>                    +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2018/04/07 16:49:24 by lberezyn          #+#    #+#             //
/*   Updated: 2018/04/07 19:57:39 by anestor          ###   ########.fr       */
//                                                                            //
// ************************************************************************** //

#include "Game.hpp"

Enemy::Enemy()
{
	this->_alive = false;
	this->_x = 2;
	this->_y = 2;
	this->_speed = 0.3;
	this->_type = '<';
	this->_bullet = new Bullet(_x, _y, false);
}

Enemy::Enemy(int x, int y)
{
	this->_t2 = (clock() / (CLOCKS_PER_SEC / FPS));
	this->_alive = false;
	this->_x = x - 2;
	this->_y = std::rand() % y - 2;
	if (this->_y < 2)
		this->_y = 2;
	this->_speed = 0.3;
	this->_type = '<';
	this->_bullet = new Bullet(_x, _y, false);
}

Enemy::Enemy(Enemy const &src)
{
	*this = src;
}

Enemy& Enemy::operator=(Enemy const &src)
{
	if (this != &src)
	{
		this->_colType = src._colType;
		this->_x = src._x;
		this->_y = src._y;
		this->_speed = src._speed;
		this->_type = src._type;
		this->_alive = src._alive;
		this->_t2 = src._t2;
		this->_bullet = src._bullet;
	}
	return (*this);
}

Enemy::~Enemy()
{

}

void	Enemy::newEnemy(int x, int y)
{
	this->_alive = true;
	this->_x = x - 2;
	this->_y = std::rand() % y - 2;
	if (this->_y < 2)
		this->_y = 2;
}

void Enemy::move(int x, int y)
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
		if (clock() % 150 == 0 && !this->_bullet->isAlive())
			this->attack();
	}
	this->_bullet->move(x, y);
}

void Enemy::attack()
{
	this->_bullet->setX(this->_x - 2);
	this->_bullet->setY(this->_y);
	this->_bullet->setAlive(true);
}
