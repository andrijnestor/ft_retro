// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   bullet.hpp                                         :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: lberezyn <marvin@42.fr>                    +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2018/04/07 17:01:10 by lberezyn          #+#    #+#             //
/*   Updated: 2018/04/07 18:55:44 by anestor          ###   ########.fr       */
//                                                                            //
// ************************************************************************** //

#ifndef BULLET_H
# define BULLET_H

# include "Entity.hpp"

class				Bullet : public Entity
{
private:
	bool			_dir;

public:
	Bullet();
	Bullet(Bullet const & src);
	Bullet(int x, int y, bool dir);
	~Bullet();

	Bullet 			&operator=(Bullet const &);
	void			move(int x, int y);
};

#endif
