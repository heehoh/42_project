/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hujeong <hujeong@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/02 12:12:21 by hujeong           #+#    #+#             */
/*   Updated: 2023/09/25 13:20:40 by hujeong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap(void)
    : ClapTrap(), FragTrap(), ScavTrap(), _name(ClapTrap::_name) {
  std::cout << "DiamondTrap 기본 생성자 호출" << std::endl;
  ClapTrap::_name = _name + "_clap_name";
  _hitPoints = fragtrap::HP;
  _energyPoints = scavtrap::EP;
  _attackDamage = fragtrap::AD;
}

DiamondTrap::DiamondTrap(std::string name)
    : ClapTrap(name), FragTrap(name), ScavTrap(name), _name(name) {
  std::cout << "DiamondTrap 생성자 호출" << std::endl;
  ClapTrap::_name = _name + "_clap_name";
  _hitPoints = fragtrap::HP;
  _energyPoints = scavtrap::EP;
  _attackDamage = fragtrap::AD;
}

DiamondTrap::DiamondTrap(const DiamondTrap& src)
    : ClapTrap(src), FragTrap(src), ScavTrap(src), _name(src._name) {
  std::cout << "DiamondTrap 복사 생성자 호출" << std::endl;
}

DiamondTrap& DiamondTrap::operator=(const DiamondTrap& src) {
  std::cout << "DiamondTrap 대입 연산자 호출" << std::endl;
  ClapTrap::operator=(src);
  _name = src._name;
  return *this;
}

DiamondTrap::~DiamondTrap(void) {
  std::cout << "DiamondTrap 소멸자 호출" << std::endl;
}

// Member functions

void DiamondTrap::whoAmI(void) {
  std::cout << "DiamondTrap 이름: " << _name << std::endl;
  std::cout << "ClapTrap 이름: " << ClapTrap::_name << std::endl;
}
