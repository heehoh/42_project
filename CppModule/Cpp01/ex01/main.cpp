/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hujeong <hujeong@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/15 00:45:41 by hujeong           #+#    #+#             */
/*   Updated: 2023/07/18 16:17:12 by hujeong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie* zombieHorde(int N, std::string name);

int main(void) {
  Zombie* zombies;

  zombies = zombieHorde(5, "zombie");
  for (int i = 0; i < 5; i++) {
    zombies[i].anounce();
  }
  delete[] zombies;
  return (0);
}