/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hujeong <hujeong@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/26 13:24:49 by hujeong           #+#    #+#             */
/*   Updated: 2023/09/24 19:29:38 by hujeong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

#include "FragTrap.hpp"
#include "ScavTrap.hpp"

int main() {
  std::cout << "------ 생성 ------" << std::endl;
  FragTrap fragTrap("프래그트랩");
  ScavTrap scavTrap("스캡트랩");
  ClapTrap enemy("적");
  scavTrap.guardGate();
  fragTrap.printStatus();
  scavTrap.printStatus();
  enemy.printStatus();

  std::cout << "\n------ 공격 ------" << std::endl;
  scavTrap.attack(enemy.getName());
  enemy.takeDamage(scavTrap.getAttackDamage());
  fragTrap.attack(enemy.getName());
  enemy.takeDamage(fragTrap.getAttackDamage());

  std::cout << "\n------ 전투 종료 ------" << std::endl;
  fragTrap.highFivesGuys();
  fragTrap.printStatus();
  scavTrap.printStatus();
  enemy.printStatus();
  return 0;
}
