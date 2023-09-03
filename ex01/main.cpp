/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hujeong <hujeong@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/02 14:31:04 by hujeong           #+#    #+#             */
/*   Updated: 2023/09/03 15:14:08 by hujeong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"
#include "Dog.hpp"

int main() {
  Animal* animals[4];

  for (int i = 0; i < 2; i++) {
    animals[i] = new Dog();
  }
  std::cout << std::endl;
  for (int i = 2; i < 4; i++) {
    animals[i] = new Cat();
  }
  std::cout << std::endl;
  for (int i = 0; i < 4; i++) {
    animals[i]->makeSound();
  }
  std::cout << std::endl;
  std::cout << "----------------------------------------" << std::endl;
  animals[0]->setIdea(0, "Dog idea 0");
  animals[2]->setIdea(0, "Cat idea 0");
  *animals[1] = *animals[0];
  *animals[3] = *animals[2];
  std::cout << "----------------------------------------" << std::endl;
  std::cout << std::endl;
  for (int i = 0; i < 4; i++) {
    animals[i]->makeSound();
  }
  std::cout << std::endl;
  for (int i = 0; i < 4; i++) {
    animals[i]->printIdeas();
  }
  std::cout << std::endl;
  animals[0]->setIdea(0, "Dog idea 0 changed");
  animals[2]->setIdea(0, "Cat idea 0 changed");
  std::cout << std::endl;
  for (int i = 0; i < 4; i++) {
    animals[i]->printIdeas();
  }
  std::cout << std::endl;
  for (int i = 0; i < 4; i++) {
    delete animals[i];
  }
  return 0;
}