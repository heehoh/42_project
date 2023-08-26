/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hujeong <hujeong@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/26 13:24:46 by hujeong           #+#    #+#             */
/*   Updated: 2023/08/26 19:38:41 by hujeong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include <iostream>

// Orthodox Canonical form
ClapTrap::ClapTrap(void) : name("무명"), hitPoints(C_HP), energyPoints(C_EP), attackDamage(C_AD){
  std::cout << "ClapTrap 기본 생성자 호출" << std::endl;
}

ClapTrap::ClapTrap(std::string name) : name(name), hitPoints(C_HP), energyPoints(C_EP), attackDamage(C_AD) {
  std::cout << "ClapTrap 생성자 호출" << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap& src) {
  std::cout << "ClapTrap 복사 생성자 호출" << std::endl;
  name = src.name;
  hitPoints = src.hitPoints;
  energyPoints = src.energyPoints;
  attackDamage = src.attackDamage;
}

ClapTrap& ClapTrap::operator=(const ClapTrap& src) {
  std::cout << "ClapTrap 대입 연산자 호출" << std::endl;
  name = src.name;
  hitPoints = src.hitPoints;
  energyPoints = src.energyPoints;
  attackDamage = src.attackDamage;
  return *this;
}

ClapTrap::~ClapTrap(void) {
  std::cout << "ClapTrap 소멸자 호출" << std::endl;
}

// Member functions

void ClapTrap::attack(const std::string& target) {
  if (hitPoints == 0 || energyPoints == 0) {
    std::cout << name << "이(가) 공격할 수 없습니다!" << std::endl;
    return ;
  }
  --energyPoints;
  std::cout << name << "이(가) " << target << "을(를) " << attackDamage << "의 데미지로 공격합니다!" << std::endl;
}

void ClapTrap::takeDamage(unsigned int amount) {
  if (hitPoints == 0) {
    std::cout << name << "이(가) 데미지를 입을 수 없습니다!" << std::endl;
    return ;
  }
  std::cout << name << "이(가) " << amount << "의 데미지를 입었습니다!" << std::endl;
  if (hitPoints < amount)
    hitPoints = 0;
  else
    hitPoints -= amount;
}

void ClapTrap::beRepaired(unsigned int amount) {
  if (hitPoints == 0 || energyPoints == 0) {
    std::cout << name << "이(가) 회복할 수 없습니다!" << std::endl;
    return ;
  }
  if (hitPoints + amount > 10)
    hitPoints = 10;
  else
    hitPoints += amount;
  --energyPoints;
  std::cout << name << "이(가) " << amount << "의 체력을 회복했습니다!" << std::endl;
}

// Getters and setters

std::string ClapTrap::getName(void) const {
  return name;
}
unsigned int ClapTrap::getHitPoints(void) const {
  return hitPoints;
}
unsigned int ClapTrap::getAttackDamage(void) const {
  return attackDamage;
}
unsigned int ClapTrap::getEnergyPoints(void) const {
  return energyPoints;
}

void ClapTrap::setName(std::string name) {
  this->name = name;
}
void ClapTrap::setHitPoints(unsigned int hitPoints) {
  this->hitPoints = hitPoints;
}
void ClapTrap::setEnergyPoints(unsigned int energyPoints) {
  this->energyPoints = energyPoints;
}
void ClapTrap::setAttackDamage(unsigned int attackDamage) {
  this->attackDamage = attackDamage;
}