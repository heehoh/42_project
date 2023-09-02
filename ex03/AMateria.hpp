/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hujeong <hujeong@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/02 18:06:01 by hujeong           #+#    #+#             */
/*   Updated: 2023/09/02 20:11:52 by hujeong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AMATERIA_HPP
#define AMATERIA_HPP

#include <iostream>

class ICharacter;

class AMateria {
 protected:
  public:
  AMateria();
  AMateria(std::string const& type);
  AMateria(const AMateria& other);
  virtual ~AMateria();

  AMateria& operator=(const AMateria& other);

  std::string const& getType() const;
  virtual AMateria* clone() const = 0;
  virtual void use(ICharacter& target);
};

#endif