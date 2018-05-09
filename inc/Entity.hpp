// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   Entity.hpp                                         :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: lberezyn <marvin@42.fr>                    +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2018/04/07 15:35:44 by lberezyn          #+#    #+#             //
/*   Updated: 2018/04/07 20:09:30 by anestor          ###   ########.fr       */
//                                                                            //
// ************************************************************************** //

#ifndef ENTITY_H
# define ENTITY_H
# include "Game.hpp"

class					Entity
{
protected:
	char				_type;
	int					_colType;
	bool				_alive;
	float				_x;
	float				_y;
	float				_speed;

public:
	Entity();
	Entity(Entity const & src);
	~Entity();

	static int 		_score;

	Entity 				&operator=(Entity const &);
	bool				isAlive();
	bool				checkCollision(void);
	void				setX(float x);
	void				setY(float y);
	void				setAlive(bool set);
	void				draw(int x, int y);
	void				erase(void);
	void				die();
};

#endif
