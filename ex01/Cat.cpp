/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hujeong <hujeong@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/02 14:31:01 by hujeong           #+#    #+#             */
/*   Updated: 2023/09/02 17:44:06 by hujeong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat(void) : Animal() {
  std::cout << "Cat 기본 생성자 호출" << std::endl;
  type = "Cat";
  brain = new Brain();
}

Cat::Cat(const Cat& copy) : Animal(copy) {
  std::cout << "Cat 복사 생성자 호출" << std::endl;
  brain = new Brain(*copy.brain);
}

Cat::~Cat(void) {
  std::cout << "Cat 소멸자 호출" << std::endl;
  delete brain;
}

Cat& Cat::operator=(const Cat& src) {
  std::cout << "Cat 대입 연산자 호출" << std::endl;
  if (this == &src) return *this;
  type = src.getType();
  delete brain;
  brain = new Brain(*src.brain);
  return *this;
}

void Cat::makeSound(void) const { std::cout << "야옹" << std::endl; }

Brain* Cat::getBrain(void) const { return brain; }