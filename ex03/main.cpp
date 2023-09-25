/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hujeong <hujeong@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/26 13:24:49 by hujeong           #+#    #+#             */
/*   Updated: 2023/09/25 13:25:12 by hujeong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

#include "DiamondTrap.hpp"

int main() {
  std::cout << "----- 생성자 호출 -----" << std::endl;
  DiamondTrap diamondTrap("다이아몬드트랩");
  ScavTrap scavTrap("스캐브트랩");
  FragTrap fragTrap("프래그트랩");
  ClapTrap enemy("적");
  diamondTrap.printStatus();
  scavTrap.printStatus();
  fragTrap.printStatus();
  enemy.printStatus();

  std::cout << "\n----- 공격 -----" << std::endl;
  diamondTrap.attack(enemy.getName());
  enemy.takeDamage(diamondTrap.getAttackDamage());
  scavTrap.attack(enemy.getName());
  enemy.takeDamage(scavTrap.getAttackDamage());
  fragTrap.attack(enemy.getName());
  enemy.takeDamage(fragTrap.getAttackDamage());
  diamondTrap.printStatus();
  scavTrap.printStatus();
  fragTrap.printStatus();
  enemy.printStatus();

  std::cout << "\n----- 전투 종료 -----" << std::endl;
  diamondTrap.guardGate();
  scavTrap.guardGate();
  fragTrap.highFivesGuys();
  diamondTrap.highFivesGuys();

  std::cout << "\n----- whoAmI 호출 -----" << std::endl;
  diamondTrap.whoAmI();
  std::cout << "\n----- 소멸자 호출 -----" << std::endl;
  return 0;
}
