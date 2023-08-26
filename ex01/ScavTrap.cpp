/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hujeong <hujeong@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/26 15:31:45 by hujeong           #+#    #+#             */
/*   Updated: 2023/08/26 19:45:21 by hujeong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"
#include <iostream>

ScavTrap::ScavTrap(void) : ClapTrap() {
  std::cout << "ScavTrap 기본 생성자 호출" << std::endl;
  setHitPoints(S_HP);
  setEnergyPoints(S_EP);
  setAttackDamage(S_AD);
}

ScavTrap::ScavTrap(std::string name) : ClapTrap(name) {
  std::cout << "ScavTrap 생성자 호출" << std::endl;
  setHitPoints(S_HP);
  setEnergyPoints(S_EP);
  setAttackDamage(S_AD);
}

ScavTrap::ScavTrap(const ScavTrap& src) {
  std::cout << "ScavTrap 복사 생성자 호출" << std::endl;
  setName(src.getName());
  setHitPoints(src.getHitPoints());
  setEnergyPoints(src.getEnergyPoints());
  setAttackDamage(src.getAttackDamage());
}

ScavTrap& ScavTrap::operator=(const ScavTrap& src) {
  std::cout << "ScavTrap 대입 연산자 호출" << std::endl;
  setName(src.getName());
  setHitPoints(src.getHitPoints());
  setEnergyPoints(src.getEnergyPoints());
  setAttackDamage(src.getAttackDamage());
  return *this;
}

ScavTrap::~ScavTrap(void) {
  std::cout << "ScavTrap 소멸자 호출" << std::endl;
}

// Member functions

void ScavTrap::attack(std::string name) {
  if (getHitPoints() == 0 || getEnergyPoints() == 0) {
    std::cout << "ScavTrap " << getName() << "이(가) 공격할 수 없습니다!" << std::endl;
    return ;
  }
  std::cout << "ScavTrap " << getName() << "이(가) " << name << "을(를) " << getAttackDamage() << "의 데미지로 공격합니다!" << std::endl;
}

void ScavTrap::guardGate(void) {
  std::cout << "ScavTrap " << getName() << "이(가) Gate를 지키기 시작합니다" << std::endl;
}