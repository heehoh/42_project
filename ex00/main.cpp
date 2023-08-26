/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hujeong <hujeong@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/26 13:24:49 by hujeong           #+#    #+#             */
/*   Updated: 2023/08/26 18:52:19 by hujeong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include <iostream>

void showInfo(ClapTrap& clapTrap) {
  std::cout << clapTrap.getName() << " HP: " << clapTrap.getHitPoints() << " EP: "<< clapTrap.getEnergyPoints() << std::endl;
}

int main() {
  std::cout << "------ 클랩트랩 생성 ------" << std::endl;
  ClapTrap clapTrap("클랩트랩");
  ClapTrap enemy("적");
  showInfo(clapTrap);
  showInfo(enemy);

  std::cout << "\n------ 공격 ------" << std::endl;
  clapTrap.attack("적");
  enemy.takeDamage(clapTrap.getAttackDamage());
  enemy.attack("클랩트랩");
  clapTrap.takeDamage(enemy.getAttackDamage());
  showInfo(clapTrap);
  showInfo(enemy);

  std::cout << "\n------ 우르르 쾅쾅 ------" << std::endl;
  clapTrap.takeDamage(5);
  enemy.takeDamage(10);
  showInfo(clapTrap);
  showInfo(enemy);
  
  std::cout << "\n------ 수리 ------" << std::endl;
  clapTrap.beRepaired(10);
  enemy.beRepaired(10);
  showInfo(clapTrap);
  showInfo(enemy);
  
  std::cout << "\n------ 공격 ------" << std::endl;
  clapTrap.attack("적");
  enemy.takeDamage(clapTrap.getAttackDamage());
  enemy.attack("적");
  showInfo(clapTrap);
  showInfo(enemy);
  
  std::cout << "\n------ 전투 종료 ------" << std::endl;
  showInfo(clapTrap);
  showInfo(enemy);
  return 0;
}
