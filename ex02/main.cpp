/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hujeong <hujeong@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/02 14:31:04 by hujeong           #+#    #+#             */
/*   Updated: 2023/10/01 16:13:29 by hujeong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cstdlib>

#include "Cat.hpp"
#include "Dog.hpp"

int main() {
  Animal* animals[4];
  // Animal* dummy = new Animal();
  // delete dummy;

  std::cout << "\n------- Dog와 Cat 생성 ------" << std::endl;
  for (int i = 0; i < 2; i++) {
    animals[i] = new Dog();
  }
  for (int i = 2; i < 4; i++) {
    animals[i] = new Cat();
  }
  std::cout << std::endl;
  for (int i = 0; i < 4; i++) {
    animals[i]->makeSound();
  }

  std::cout << "\n--------- Dog와 Cat 생각 설정 -------------" << std::endl;
  animals[0]->setIdea(0, "산책 가자!");
  animals[2]->setIdea(0, "졸려 -_-");
  *animals[1] = *animals[0];
  *animals[3] = *animals[2];

  std::cout << "\n---------- Dog와 Cat의 생각 ------------" << std::endl;
  for (int i = 0; i < 4; i++) {
    animals[i]->makeSound();
    std::cout << "--> ";
    animals[i]->printIdeas();
  }
  std::cout << "\n------ 배고픈 Dog와 Cat의 생각 -------- " << std::endl;
  animals[1]->setIdea(0, "밥줘 ~~!");
  animals[3]->setIdea(0, "밥줘 ~~!");
  for (int i = 0; i < 4; i++) {
    animals[i]->makeSound();
    std::cout << "--> ";
    animals[i]->printIdeas();
  }
  std::cout << "\n------- Dog와 Cat 퇴장 ---------" << std::endl;
  for (int i = 0; i < 4; i++) {
    delete animals[i];
  }
  return 0;
}