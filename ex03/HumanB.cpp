/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hujeong <hujeong@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/15 08:45:18 by hujeong           #+#    #+#             */
/*   Updated: 2023/07/18 16:39:01 by hujeong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANB_HPP
#define HUMANB_HPP

#include "HumanB.hpp"

#include <iostream>

HumanB::HumanB(std::string name) : _name(name) {}
void HumanB::setWeapon(Weapon& weapon) { _weapon = &weapon; }
void HumanB::attack(void) {
  std::cout << _name << " attacks with his " << _weapon->getType() << std::endl;
}

#endif