/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hujeong <hujeong@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/26 15:31:45 by hujeong           #+#    #+#             */
/*   Updated: 2023/09/24 19:15:32 by hujeong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

#include <iostream>

ScavTrap::ScavTrap(void) : ClapTrap() {
  std::cout << "ScavTrap 기본 생성자 호출" << std::endl;
  hitPoints = scavtrap::HP;
  energyPoints = scavtrap::EP;
  attackDamage = scavtrap::AD;
  maxHitPoints = scavtrap::HP;
}

ScavTrap::ScavTrap(std::string name) : ClapTrap(name) {
  std::cout << "ScavTrap 생성자 호출" << std::endl;
  hitPoints = scavtrap::HP;
  energyPoints = scavtrap::EP;
  attackDamage = scavtrap::AD;
}

ScavTrap::ScavTrap(const ScavTrap& src) : ClapTrap(src) {
  std::cout << "ScavTrap 복사 생성자 호출" << std::endl;
}

ScavTrap& ScavTrap::operator=(const ScavTrap& src) {
  std::cout << "ScavTrap 대입 연산자 호출" << std::endl;
  name = src.getName();
  hitPoints = src.getHitPoints();
  energyPoints = src.getEnergyPoints();
  attackDamage = src.getAttackDamage();
  return *this;
}

ScavTrap::~ScavTrap(void) { std::cout << "ScavTrap 소멸자 호출" << std::endl; }

// Member functions

void ScavTrap::attack(const std::string& target) {
  if (getHitPoints() == 0 || getEnergyPoints() == 0) {
    std::cout << "ScavTrap " << name << "이(가) 공격할 수 없습니다!"
              << std::endl;
    return;
  }
  --energyPoints;
  std::cout << "ScavTrap " << name << "이(가) " << target << "을(를) "
            << attackDamage << "의 데미지로 공격합니다!" << std::endl;
}

void ScavTrap::guardGate(void) {
  std::cout << "ScavTrap " << name << "이(가) Gate를 지키기 시작합니다"
            << std::endl;
}