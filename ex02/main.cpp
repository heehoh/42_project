/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hujeong <hujeong@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/02 14:31:04 by hujeong           #+#    #+#             */
/*   Updated: 2023/09/02 19:39:13 by hujeong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"
#include "Dog.hpp"

int main() {
  Animal* animals[3];

  animals[0] = new Animal();
  animals[1] = new Cat();
  animals[2] = new Dog();

  std::cout << std::endl;
  for (int i = 0; i < 3; i++) {
    animals[i]->makeSound();
  }

  std::cout << std::endl;
  for (int i = 0; i < 3; i++) {
    delete animals[i];
  }

  std::cout << std::endl;

  return 0;
}