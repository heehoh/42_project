/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hujeong <hujeong@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/02 14:30:53 by hujeong           #+#    #+#             */
/*   Updated: 2023/09/02 17:43:42 by hujeong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog(void) : Animal() {
  std::cout << "Dog 기본 생성자 호출" << std::endl;
  type = "Dog";
  brain = new Brain();
}

Dog::Dog(const Dog& copy) : Animal(copy) {
  std::cout << "Dog 복사 생성자 호출" << std::endl;
  brain = new Brain(*copy.getBrain());
}

Dog::~Dog(void) {
  std::cout << "Dog 소멸자 호출" << std::endl;
  delete brain;
}

Dog& Dog::operator=(const Dog& src) {
  std::cout << "Dog 대입 연산자 호출" << std::endl;
  if (this == &src) return *this;
  type = src.getType();
  delete brain;
  brain = new Brain(*src.getBrain());
  return *this;
}

void Dog::makeSound(void) const { std::cout << "멍멍" << std::endl; }

Brain* Dog::getBrain(void) const { return brain; }