/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.Hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hujeong <hujeong@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/15 08:45:16 by hujeong           #+#    #+#             */
/*   Updated: 2023/07/15 08:57:48 by hujeong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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