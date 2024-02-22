/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hujeong <hujeong@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/04 14:55:37 by hujeong           #+#    #+#             */
/*   Updated: 2023/09/04 14:55:53 by hujeong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANB_HPP
#define HUMANB_HPP

#include "Weapon.hpp"

class HumanB {
 public:
  HumanB(std::string name);
  void setWeapon(Weapon& weapon);
  void attack(void);

 private:
  std::string _name;
  Weapon* _weapon;
};

#endif
