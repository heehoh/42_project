/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zombieHorde.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hujeong <hujeong@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/15 00:45:34 by hujeong           #+#    #+#             */
/*   Updated: 2023/07/15 01:13:11 by hujeong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sstream>

#include "Zombie.hpp"

Zombie* zombieHorde(int N, std::string name) {
  Zombie* zombies = new Zombie[N];
  std::stringstream ss;

  for (int i = 0; i < N; i++) {
    ss.str("");
    ss << i + 1;
    zombies[i].setName(name + ss.str());
  }
  return (zombies);
}