/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hujeong <hujeong@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/15 08:45:22 by hujeong           #+#    #+#             */
/*   Updated: 2023/07/15 08:52:21 by hujeong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanA.hpp"

#include <iostream>

HumanA::HumanA(std::string name, Weapon& weapon)
    : _name(name), _weapon(weapon) {}
void HumanA::attack(void) {
  std::cout << _name << " attacks with his " << _weapon.getType() << std::endl;
}