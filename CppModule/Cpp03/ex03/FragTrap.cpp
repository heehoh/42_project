/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hujeong <hujeong@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/02 11:34:05 by hujeong           #+#    #+#             */
/*   Updated: 2023/09/25 13:25:23 by hujeong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

// Orthodox Canonical form
FragTrap::FragTrap(void) : ClapTrap() {
  std::cout << "FragTrap 기본 생성자 호출" << std::endl;
  _hitPoints = fragtrap::HP;
  _energyPoints = fragtrap::EP;
  _attackDamage = fragtrap::AD;
  _maxHitPoints = fragtrap::HP;
}

FragTrap::FragTrap(std::string name) : ClapTrap(name) {
  std::cout << "FragTrap 생성자 호출" << std::endl;
  _hitPoints = fragtrap::HP;
  _energyPoints = fragtrap::EP;
  _attackDamage = fragtrap::AD;
  _maxHitPoints = fragtrap::HP;
}

FragTrap::FragTrap(const FragTrap& src) : ClapTrap(src) {
  std::cout << "FragTrap 복사 생성자 호출" << std::endl;
}

FragTrap& FragTrap::operator=(const FragTrap& src) {
  std::cout << "FragTrap 대입 연산자 호출" << std::endl;
  ClapTrap::operator=(src);
  return *this;
}

FragTrap::~FragTrap(void) { std::cout << "FragTrap 소멸자 호출" << std::endl; }

// Member functions

void FragTrap::highFivesGuys(void) {
  std::cout << "FragTrap " << _name << "이(가) high fives를 요청합니다!"
            << std::endl;
}