/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hujeong <hujeong@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/02 20:16:07 by hujeong           #+#    #+#             */
/*   Updated: 2023/09/02 21:14:23 by hujeong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ICE_HPP
#define ICE_HPP

#include "AMateria.hpp"

class Ice : public AMateria {
 public:
  Ice(void);
  Ice(const Ice& other);
  virtual ~Ice();
  Ice& operator=(const Ice& other);

  virtual AMateria* clone() const;
  virtual void use(ICharacter& target);
};

#endif