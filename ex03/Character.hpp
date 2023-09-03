/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hujeong <hujeong@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/02 20:16:29 by hujeong           #+#    #+#             */
/*   Updated: 2023/09/03 17:01:15 by hujeong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHARACTER_HPP
#define CHARACTER_HPP

#include "ICharacter.hpp"

class Character : public ICharacter {
 private:
  std::string name;
  AMateria* inventory[4];
  AMateria* trash[4];
  Character(void);

 public:
  Character(const std::string& name);

  Character(const Character& other);
  Character& operator=(const Character& other);
  virtual ~Character(void);
  virtual std::string const& getName(void) const;
  virtual void equip(AMateria* m);
  virtual void unequip(int idx);
  virtual void use(int idx, ICharacter& target);
};

#endif