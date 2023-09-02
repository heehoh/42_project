/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hujeong <hujeong@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/02 18:06:01 by hujeong           #+#    #+#             */
/*   Updated: 2023/09/02 22:02:55 by hujeong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AMATERIA_HPP
#define AMATERIA_HPP

#include <iostream>

class ICharacter;

class AMateria {
 protected:
  const std::string type;

 public:
  AMateria(std::string const& type);

  AMateria(void);
  AMateria(const AMateria& other);
  virtual ~AMateria(void);
  AMateria& operator=(const AMateria& other);

  std::string const& getType(void) const;  // Returns the materia type

  virtual AMateria* clone(void) const = 0;
  virtual void use(ICharacter& target);
};

#endif