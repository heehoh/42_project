/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hujeong <hujeong@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/02 14:31:04 by hujeong           #+#    #+#             */
/*   Updated: 2023/09/03 15:54:43 by hujeong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongCat.hpp"

int main() {
  const Animal* meta = new Animal();
  const Animal* j = new Dog();
  const Animal* i = new Cat();
  std::cout << "-------------------------------" << std::endl;
  std::cout << j->getType() << " " << std::endl;
  std::cout << i->getType() << " " << std::endl;
  i->makeSound();
  j->makeSound();
  meta->makeSound();
  std::cout << "-------------------------------" << std::endl;

  delete meta;
  delete j;
  delete i;
  std::cout << "-------------------------------" << std::endl;

  WrongAnimal* wrongAnimals[2];

  std::cout << std::endl;
  wrongAnimals[0] = new WrongAnimal();
  wrongAnimals[1] = new WrongCat();

  std::cout << std::endl;
  for (int i = 0; i < 2; i++) {
    wrongAnimals[i]->makeSound();
  }

  std::cout << std::endl;
  for (int i = 0; i < 2; i++) {
    delete wrongAnimals[i];
  }
  return 0;
}