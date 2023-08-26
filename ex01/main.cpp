/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hujeong <hujeong@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/26 13:24:49 by hujeong           #+#    #+#             */
/*   Updated: 2023/08/26 19:30:57 by hujeong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"
#include <iostream>

int main() {
  ScavTrap scavTrap("ScavTrap");

  scavTrap.attack("target");
  scavTrap.guardGate();
  return 0;
}
