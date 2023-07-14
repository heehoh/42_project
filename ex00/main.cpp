/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hujeong <hujeong@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/15 00:32:01 by hujeong           #+#    #+#             */
/*   Updated: 2023/07/15 00:41:27 by hujeong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int main(void) {
  Zombie zombie0("zombie0");
  Zombie* zombie1;

  zombie0.anounce();
  zombie1 = newZombie("zombie1");
  zombie1->anounce();
  delete zombie1;
  randomChump("zombie2");
  return (0);
}