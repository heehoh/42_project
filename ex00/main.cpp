/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hujeong <hujeong@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/26 13:24:49 by hujeong           #+#    #+#             */
/*   Updated: 2023/09/02 11:10:40 by hujeong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

int main() {
  std::cout << "------ 클랩트랩 생성 ------" << std::endl;
  ClapTrap clapTrap("클랩트랩");
  ClapTrap enemy("적");
  clapTrap.printStatus();
  enemy.printStatus();

  std::cout << "\n------ 공격 ------" << std::endl;
  clapTrap.attack("적");
  enemy.takeDamage(clapTrap.getAttackDamage());
  enemy.attack("클랩트랩");
  clapTrap.takeDamage(enemy.getAttackDamage());
  clapTrap.printStatus();
  enemy.printStatus();

  std::cout << "\n------ 우르르 쾅쾅 ------" << std::endl;
  clapTrap.takeDamage(5);
  enemy.takeDamage(10);
  clapTrap.printStatus();
  enemy.printStatus();

  std::cout << "\n------ 수리 ------" << std::endl;
  clapTrap.beRepaired(10);
  enemy.beRepaired(10);
  clapTrap.printStatus();
  enemy.printStatus();

  std::cout << "\n------ 공격 ------" << std::endl;
  clapTrap.attack("적");
  enemy.takeDamage(clapTrap.getAttackDamage());
  enemy.attack("적");
  clapTrap.printStatus();
  enemy.printStatus();

  std::cout << "\n------ 전투 종료 ------" << std::endl;
  clapTrap.printStatus();
  enemy.printStatus();
  return 0;
}
