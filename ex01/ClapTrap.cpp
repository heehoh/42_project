/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hujeong <hujeong@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/26 13:24:46 by hujeong           #+#    #+#             */
/*   Updated: 2023/09/25 13:10:00 by hujeong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

// Orthodox Canonical form
ClapTrap::ClapTrap(void)
    : _name("무명"),
      _hitPoints(claptrap::HP),
      _energyPoints(claptrap::EP),
      _attackDamage(claptrap::AD),
      _maxHitPoints(claptrap::HP) {
  std::cout << "ClapTrap 기본 생성자 호출" << std::endl;
}

ClapTrap::ClapTrap(std::string name)
    : _name(name),
      _hitPoints(claptrap::HP),
      _energyPoints(claptrap::EP),
      _attackDamage(claptrap::AD),
      _maxHitPoints(claptrap::HP) {
  std::cout << "ClapTrap 생성자 호출" << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap& src)
    : _name(src._name),
      _hitPoints(src._hitPoints),
      _energyPoints(src._energyPoints),
      _attackDamage(src._attackDamage),
      _maxHitPoints(src._maxHitPoints) {
  std::cout << "ClapTrap 복사 생성자 호출" << std::endl;
}

ClapTrap& ClapTrap::operator=(const ClapTrap& src) {
  std::cout << "ClapTrap 대입 연산자 호출" << std::endl;
  _name = src._name;
  _hitPoints = src._hitPoints;
  _energyPoints = src._energyPoints;
  _attackDamage = src._attackDamage;
  return *this;
}

ClapTrap::~ClapTrap(void) { std::cout << "ClapTrap 소멸자 호출" << std::endl; }

// Member functions

void ClapTrap::attack(const std::string& target) {
  if (_hitPoints == 0 || _energyPoints == 0) {
    std::cout << "ClapTrap " << _name << "이(가) 공격할 수 없습니다!"
              << std::endl;
    return;
  }
  --_energyPoints;
  std::cout << "ClapTrap " << _name << "이(가) " << target << "을(를) "
            << _attackDamage << "의 데미지로 공격합니다!" << std::endl;
}

void ClapTrap::takeDamage(unsigned int amount) {
  if (_hitPoints == 0) {
    std::cout << "ClapTrap " << _name << "이(가) 이미 파괴되었습니다!"
              << std::endl;
    return;
  }
  std::cout << "ClapTrap " << _name << "이(가) " << amount
            << "의 데미지를 입었습니다!" << std::endl;
  if (_hitPoints <= amount) {
    _hitPoints = 0;
    std::cout << "ClapTrap " << _name << "이(가) 파괴되었습니다!" << std::endl;
  } else
    _hitPoints -= amount;
}

void ClapTrap::beRepaired(unsigned int amount) {
  if (_hitPoints == 0) {
    std::cout << "ClapTrap " << _name << "이(가) 이미 파괴되었습니다!"
              << std::endl;
    return;
  } else if (_energyPoints == 0) {
    std::cout << "ClapTrap " << _name << "이(가) 수리할 수 없습니다!"
              << std::endl;
    return;
  }
  if (_hitPoints + amount > _maxHitPoints)
    _hitPoints = _maxHitPoints;
  else
    _hitPoints += amount;
  --_energyPoints;
  std::cout << "ClapTrap " << _name << "이(가) " << amount
            << "의 체력을 회복합니다!" << std::endl;
}

// Getters and setters

std::string ClapTrap::getName(void) const { return _name; }
unsigned int ClapTrap::getHitPoints(void) const { return _hitPoints; }
unsigned int ClapTrap::getAttackDamage(void) const { return _attackDamage; }
unsigned int ClapTrap::getEnergyPoints(void) const { return _energyPoints; }
unsigned int ClapTrap::getMaxHitPoints(void) const { return _maxHitPoints; }

void ClapTrap::setName(std::string name) { _name = name; }
void ClapTrap::setHitPoints(unsigned int hitPoints) { _hitPoints = hitPoints; }
void ClapTrap::setEnergyPoints(unsigned int energyPoints) {
  _energyPoints = energyPoints;
}
void ClapTrap::setAttackDamage(unsigned int attackDamage) {
  _attackDamage = attackDamage;
}
void ClapTrap::setMaxHitPoints(unsigned int maxHitPoints) {
  _maxHitPoints = maxHitPoints;
}

void ClapTrap::printStatus(void) const {
  std::cout << getName() << " HP: " << getHitPoints()
            << " EP: " << getEnergyPoints() << std::endl;
}