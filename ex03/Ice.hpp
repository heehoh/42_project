/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hujeong <hujeong@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/02 20:16:07 by hujeong           #+#    #+#             */
/*   Updated: 2023/09/03 16:35:20 by hujeong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ICE_HPP
#define ICE_HPP

#include "AMateria.hpp"

class Ice : public AMateria {
 private:
  Ice(const Ice& other);
  Ice& operator=(const Ice& other);

 public:
  Ice(void);
  virtual ~Ice();

  virtual AMateria* clone() const;
  virtual void use(ICharacter& target);
};

#endif