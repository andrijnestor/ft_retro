// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   Enemy.hpp                                          :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: lberezyn <marvin@42.fr>                    +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2018/04/07 16:49:35 by lberezyn          #+#    #+#             //
/*   Updated: 2018/04/07 19:47:52 by anestor          ###   ########.fr       */
//                                                                            //
// ************************************************************************** //

#ifndef ENEMY_H
# define ENEMY_H

# include "Entity.hpp"
# include "Bullet.hpp"

class						Enemy: public Entity
{
	private:
		Bullet				*_bullet;
		int 				_t2;

	public:
		Enemy();
		Enemy(int x, int y);
		Enemy(Enemy const & src);
		~Enemy();

		Enemy 				&operator=(Enemy const &);
		void				move(int x, int y);
		void				newEnemy(int x, int y);
		void				attack();
};

#endif
