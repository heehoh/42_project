/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hujeong <hujeong@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/15 08:45:18 by hujeong           #+#    #+#             */
/*   Updated: 2023/08/12 22:12:52 by hujeong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanB.hpp"

#include <iostream>

HumanB::HumanB(std::string name) : _name(name) {}

void HumanB::setWeapon(Weapon& weapon) { _weapon = &weapon; }

void HumanB::attack(void) {
  std::cout << _name << " attacks with his " << _weapon->getType() << std::endl;
}
