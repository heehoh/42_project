/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hujeong <hujeong@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/15 00:45:27 by hujeong           #+#    #+#             */
/*   Updated: 2023/07/15 01:08:50 by hujeong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

#include <iostream>

Zombie::Zombie(void) {}
Zombie::Zombie(std::string name) : _name(name) {}
Zombie::~Zombie(void) { std::cout << _name << " is dead." << std::endl; }
void Zombie::anounce(void) {
  std::cout << _name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}
void Zombie::setName(std::string name) { _name = name; }