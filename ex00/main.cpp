/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hujeong <hujeong@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/15 00:32:01 by hujeong           #+#    #+#             */
/*   Updated: 2023/07/15 01:14:01 by hujeong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie* newZombie(std::string name);
void randomChump(std::string name);

int main(void) {
  Zombie zombie1("zombie1");
  Zombie* zombie2;

  zombie1.anounce();
  zombie2 = newZombie("zombie2");
  zombie2->anounce();
  delete zombie2;
  randomChump("zombie3");
}