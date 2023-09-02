/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hujeong <hujeong@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/26 13:24:46 by hujeong           #+#    #+#             */
/*   Updated: 2023/09/02 12:02:37 by hujeong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

// Orthodox Canonical form
ClapTrap::ClapTrap(void)
    : name("무명"),
      hitPoints(claptrap::HP),
      energyPoints(claptrap::EP),
      attackDamage(claptrap::AD) {
  std::cout << "ClapTrap 기본 생성자 호출" << std::endl;
}

ClapTrap::ClapTrap(std::string name)
    : name(name),
      hitPoints(claptrap::HP),
      energyPoints(claptrap::EP),
      attackDamage(claptrap::AD) {
  std::cout << "ClapTrap 생성자 호출" << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap& src)
    : name(src.getName()),
      hitPoints(src.getHitPoints()),
      energyPoints(src.getEnergyPoints()),
      attackDamage(src.getAttackDamage()) {
  std::cout << "ClapTrap 복사 생성자 호출" << std::endl;
}

ClapTrap& ClapTrap::operator=(const ClapTrap& src) {
  std::cout << "ClapTrap 대입 연산자 호출" << std::endl;
  name = src.getName();
  hitPoints = src.getHitPoints();
  energyPoints = src.getEnergyPoints();
  attackDamage = src.getAttackDamage();
  return *this;
}

ClapTrap::~ClapTrap(void) { std::cout << "ClapTrap 소멸자 호출" << std::endl; }

// Member functions

void ClapTrap::attack(const std::string& target) {
  if (hitPoints == 0 || energyPoints == 0) {
    std::cout << "ClapTrap " << name << "이(가) 공격할 수 없습니다!"
              << std::endl;
    return;
  }
  --energyPoints;
  std::cout << "ClapTrap " << name << "이(가) " << target << "을(를) "
            << attackDamage << "의 데미지로 공격합니다!" << std::endl;
}

void ClapTrap::takeDamage(unsigned int amount) {
  if (hitPoints == 0) {
    std::cout << "ClapTrap " << name << "이(가) 이미 파괴되었습니다!"
              << std::endl;
    return;
  }
  std::cout << "ClapTrap " << name << "이(가) " << amount
            << "의 데미지를 입었습니다!" << std::endl;
  if (hitPoints <= amount) {
    hitPoints = 0;
    std::cout << "ClapTrap " << name << "이(가) 파괴되었습니다!" << std::endl;
  } else
    hitPoints -= amount;
}

void ClapTrap::beRepaired(unsigned int amount) {
  if (hitPoints == 0) {
    std::cout << "ClapTrap " << name << "이(가) 이미 파괴되었습니다!"
              << std::endl;
    return;
  } else if (energyPoints == 0) {
    std::cout << "ClapTrap " << name << "이(가) 수리할 수 없습니다!"
              << std::endl;
    return;
  }
  if (hitPoints + amount > claptrap::HP)
    hitPoints = claptrap::HP;
  else
    hitPoints += amount;
  --energyPoints;
  std::cout << "ClapTrap " << name << "이(가) " << amount
            << "의 체력을 회복합니다!" << std::endl;
}

// Getters and setters

std::string ClapTrap::getName(void) const { return name; }
unsigned int ClapTrap::getHitPoints(void) const { return hitPoints; }
unsigned int ClapTrap::getAttackDamage(void) const { return attackDamage; }
unsigned int ClapTrap::getEnergyPoints(void) const { return energyPoints; }

void ClapTrap::setName(std::string name) { this->name = name; }
void ClapTrap::setHitPoints(unsigned int hitPoints) {
  this->hitPoints = hitPoints;
}
void ClapTrap::setEnergyPoints(unsigned int energyPoints) {
  this->energyPoints = energyPoints;
}
void ClapTrap::setAttackDamage(unsigned int attackDamage) {
  this->attackDamage = attackDamage;
}

void ClapTrap::printStatus(void) const {
  std::cout << getName() << " HP: " << getHitPoints()
            << " EP: " << getEnergyPoints() << std::endl;
}