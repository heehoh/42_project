/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hujeong <hujeong@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/02 14:31:01 by hujeong           #+#    #+#             */
/*   Updated: 2023/10/01 15:52:01 by hujeong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat(void) : Animal() {
  std::cout << "Cat 기본 생성자 호출" << std::endl;
  type = "Cat";
  this->brain = new Brain();
}

Cat::Cat(const Cat& copy) : Animal(copy) {
  std::cout << "Cat 복사 생성자 호출" << std::endl;
  this->brain = new Brain(*copy.brain);
}

Cat::~Cat(void) {
  std::cout << "Cat 소멸자 호출" << std::endl;
  delete this->brain;
}

Cat& Cat::operator=(const Animal& src) {
  operator=(dynamic_cast<const Cat&>(src));
  return *this;
}

Cat& Cat::operator=(const Cat& src) {
  std::cout << "Cat 대입 연산자 호출" << std::endl;
  Animal::operator=(src);
  *this->brain = *src.brain;
  return *this;
}

void Cat::makeSound(void) const { std::cout << "냥냥" << std::endl; }
void Cat::printIdeas(void) const { this->brain->printIdeas(); }
void Cat::setIdea(int index, std::string idea) {
  this->brain->setIdea(index, idea);
}