/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hujeong <hujeong@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/15 08:45:20 by hujeong           #+#    #+#             */
/*   Updated: 2023/07/18 16:17:01 by hujeong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANA_HPP
#define HUMANA_HPP

#include "Weapon.hpp"

class HumanA {
 public:
  HumanA(std::string name, Weapon& weapon);
  void attack(void);

 private:
  std::string _name;
  Weapon& _weapon;
};

#endif