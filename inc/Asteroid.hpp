// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   Asteroid.hpp                                       :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: lberezyn <marvin@42.fr>                    +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2018/04/07 15:36:41 by lberezyn          #+#    #+#             //
/*   Updated: 2018/04/07 16:39:45 by anestor          ###   ########.fr       */
//                                                                            //
// ************************************************************************** //

#ifndef ASTEROID_H
# define ASTEROID_H

# include "Entity.hpp"
# include "Game.hpp"

class Asteroid : public Entity
{
protected:

public:
	Asteroid();
	Asteroid(int x, int y);
	Asteroid(Asteroid const & src);
	~Asteroid();

	Asteroid 	&	operator=(Asteroid const &);
	void				newAsteroid(int x, int y);
	void				move(int x, int y);
};

#endif
