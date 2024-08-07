/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hujeong <hujeong@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/02 14:30:53 by hujeong           #+#    #+#             */
/*   Updated: 2023/09/03 12:20:57 by hujeong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog(void) : Animal() {
  std::cout << "Dog 기본 생성자 호출" << std::endl;
  type = "Dog";
}

Dog::Dog(const Dog& copy) : Animal(copy) {
  std::cout << "Dog 복사 생성자 호출" << std::endl;
}

Dog::~Dog(void) { std::cout << "Dog 소멸자 호출" << std::endl; }

Dog& Dog::operator=(const Dog& src) {
  Animal::operator=(src);
  std::cout << "Dog 대입 연산자 호출" << std::endl;
  return *this;
}

void Dog::makeSound(void) const { std::cout << "멍멍" << std::endl; }