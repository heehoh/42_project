/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hujeong <hujeong@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/02 11:34:05 by hujeong           #+#    #+#             */
/*   Updated: 2023/09/02 12:06:23 by hujeong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

// Orthodox Canonical form
FragTrap::FragTrap(void) : ClapTrap("무명") {
  std::cout << "FragTrap 기본 생성자 호출" << std::endl;
  hitPoints = fragtrap::HP;
  energyPoints = fragtrap::EP;
  attackDamage = fragtrap::AD;
}

FragTrap::FragTrap(std::string name) : ClapTrap(name) {
  std::cout << "FragTrap 생성자 호출" << std::endl;
  hitPoints = fragtrap::HP;
  energyPoints = fragtrap::EP;
  attackDamage = fragtrap::AD;
}

FragTrap::FragTrap(const FragTrap& src) : ClapTrap(src) {
  std::cout << "FragTrap 복사 생성자 호출" << std::endl;
  hitPoints = src.getHitPoints();
  energyPoints = src.getEnergyPoints();
  attackDamage = src.getAttackDamage();
}

FragTrap& FragTrap::operator=(const FragTrap& src) {
  std::cout << "FragTrap 대입 연산자 호출" << std::endl;
  name = src.getName();
  hitPoints = src.getHitPoints();
  energyPoints = src.getEnergyPoints();
  attackDamage = src.getAttackDamage();
  return *this;
}

FragTrap::~FragTrap(void) { std::cout << "FragTrap 소멸자 호출" << std::endl; }

// Member functions

void FragTrap::attack(std::string& target) {
  if (getHitPoints() == 0 || getEnergyPoints() == 0) {
    std::cout << "FragTrap " << name << "이(가) 공격할 수 없습니다!"
              << std::endl;
    return;
  }
  --energyPoints;
  std::cout << "FragTrap " << name << "이(가) " << target << "을(를) "
            << attackDamage << "의 데미지로 공격합니다!" << std::endl;
}

void FragTrap::takeDamage(unsigned int amount) {
  if (hitPoints == 0) {
    std::cout << "FragTrap " << name << "이(가) 이미 파괴되었습니다!"
              << std::endl;
    return;
  }
  std::cout << "FragTrap " << name << "이(가) " << amount
            << "의 데미지를 입었습니다!" << std::endl;
  if (amount > hitPoints) {
    hitPoints = 0;
    std::cout << "FragTrap " << name << "이(가) 파괴되었습니다!" << std::endl;
  } else
    hitPoints -= amount;
}

void FragTrap::beRepaired(unsigned int amount) {
  if (hitPoints == 0) {
    std::cout << "FragTrap " << name << "이(가) 이미 파괴되었습니다!"
              << std::endl;
    return;
  } else if (energyPoints == 0) {
    std::cout << "FragTrap " << name << "이(가) 수리할 수 없습니다!"
              << std::endl;
    return;
  }
  if (hitPoints + amount > fragtrap::HP)
    hitPoints = fragtrap::HP;
  else
    hitPoints += amount;
  --energyPoints;
  std::cout << "FragTrap " << name << "이(가) " << amount
            << "의 체력을 회복합니다!" << std::endl;
}

void FragTrap::highFivesGuys(void) {
  std::cout << "FragTrap " << name << "이(가) high fives를 요청합니다!"
            << std::endl;
}