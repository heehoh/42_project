/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hujeong <hujeong@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/26 13:24:49 by hujeong           #+#    #+#             */
/*   Updated: 2023/09/24 19:05:54 by hujeong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

#include "ScavTrap.hpp"

int main() {
  std::cout << "------ 생성 ------" << std::endl;
  ClapTrap enemy("적");
  ScavTrap scavTrap("스캡트랩");
  scavTrap.guardGate();
  scavTrap.printStatus();
  enemy.printStatus();

  std::cout << "\n------ 공격 ------" << std::endl;
  enemy.attack(scavTrap.getName());
  scavTrap.takeDamage(enemy.getAttackDamage());
  scavTrap.attack(enemy.getName());
  enemy.takeDamage(scavTrap.getAttackDamage());

  std::cout << "\n------ 전투 종료 ------" << std::endl;
  scavTrap.printStatus();
  enemy.printStatus();
  return 0;
}
