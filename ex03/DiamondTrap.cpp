/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hujeong <hujeong@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/02 12:12:21 by hujeong           #+#    #+#             */
/*   Updated: 2023/09/02 14:21:47 by hujeong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap(void) : FragTrap(), ScavTrap() {
  std::cout << "DiamondTrap 기본 생성자 호출" << std::endl;
  DiamondTrap::name = ClapTrap::getName() + "_DiamondTrap";
  hitPoints = fragtrap::HP;
  energyPoints = scavtrap::EP;
  attackDamage = fragtrap::AD;
}

DiamondTrap::DiamondTrap(std::string name) : FragTrap(name), ScavTrap(name) {
  std::cout << "DiamondTrap 생성자 호출" << std::endl;
  DiamondTrap::name = ClapTrap::getName() + "_DiamondTrap";
  hitPoints = fragtrap::HP;
  energyPoints = scavtrap::EP;
  attackDamage = fragtrap::AD;
}

DiamondTrap::DiamondTrap(const DiamondTrap& src)
    : FragTrap(src), ScavTrap(src) {
  std::cout << "DiamondTrap 복사 생성자 호출" << std::endl;
  DiamondTrap::name = src.ClapTrap::getName() + "_DiamondTrap";
}

DiamondTrap& DiamondTrap::operator=(const DiamondTrap& src) {
  std::cout << "DiamondTrap 대입 연산자 호출" << std::endl;
  name = src.getName();
  hitPoints = src.getHitPoints();
  energyPoints = src.getEnergyPoints();
  attackDamage = src.getAttackDamage();
  return *this;
}

DiamondTrap::~DiamondTrap(void) {
  std::cout << "DiamondTrap 소멸자 호출" << std::endl;
}

// Member functions

void DiamondTrap::whoAmI(void) {
  std::cout << "DiamondTrap 이름: " << name << std::endl;
  std::cout << "ClapTrap 이름: " << ClapTrap::getName() << std::endl;
}
