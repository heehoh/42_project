/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hujeong <hujeong@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/26 13:24:49 by hujeong           #+#    #+#             */
/*   Updated: 2023/09/02 12:08:30 by hujeong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

#include "FragTrap.hpp"
#include "ScavTrap.hpp"

int main() {
  ScavTrap scavTrap("ScavTrap");
  std::string target = "target";

  scavTrap.attack(target);
  scavTrap.guardGate();
  return 0;
}
