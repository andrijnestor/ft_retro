/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Hero.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anestor <anestor@student.unit.ua>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/07 16:46:30 by anestor           #+#    #+#             */
/*   Updated: 2018/04/08 13:32:42 by anestor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HERO_H
# define HERO_H

# include "Entity.hpp"

# define INIT_POS_X 5
# define INIT_POS_Y 5

class					Hero : public Entity
{
	protected:
			int 		_winW;
			int 		_winH;
			Bullet		*bullet;
			int			nBullet;
	public:
		Hero();
		Hero(int x, int y);
		Hero(Hero const & src);
		~Hero();

		static int 		lives;
		void			operator++(void);
		void			operator++(int);
		void			operator--(void);
		void			operator--(int);
		Hero			&operator=(Hero const &);
		void			attack();
		void			draw(int x, int y);
};

#endif
