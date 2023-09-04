/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hujeong <hujeong@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/02 14:30:53 by hujeong           #+#    #+#             */
/*   Updated: 2023/09/04 13:38:26 by hujeong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog(void) : Animal() {
  std::cout << "Dog 기본 생성자 호출" << std::endl;
  this->type = "Dog";
  this->brain = new Brain();
}

Dog::Dog(const Dog& copy) : Animal(copy) {
  std::cout << "Dog 복사 생성자 호출" << std::endl;
  this->brain = new Brain(*copy.brain);
}

Dog::~Dog(void) {
  std::cout << "Dog 소멸자 호출" << std::endl;
  delete this->brain;
}

Dog& Dog::operator=(const Animal& src) {
  operator=(dynamic_cast<const Dog&>(src));
  return *this;
}

Dog& Dog::operator=(const Dog& src) {
  Animal::operator=(src);
  std::cout << "Dog 대입 연산자 호출" << std::endl;
  *this->brain = *src.brain;
  return *this;
}

void Dog::makeSound(void) const { std::cout << "멍멍" << std::endl; }
void Dog::printIdeas(void) const { this->brain->printIdeas(); }
void Dog::setIdea(int index, std::string idea) {
  this->brain->setIdea(index, idea);
}