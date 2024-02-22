/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hujeong <hujeong@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/02 14:31:01 by hujeong           #+#    #+#             */
/*   Updated: 2023/09/03 12:21:04 by hujeong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat(void) : Animal() {
  std::cout << "Cat 기본 생성자 호출" << std::endl;
  type = "Cat";
}

Cat::Cat(const Cat& copy) : Animal(copy) {
  std::cout << "Cat 복사 생성자 호출" << std::endl;
}

Cat::~Cat(void) { std::cout << "Cat 소멸자 호출" << std::endl; }

Cat& Cat::operator=(const Cat& src) {
  Animal::operator=(src);
  std::cout << "Cat 대입 연산자 호출" << std::endl;
  return *this;
}

void Cat::makeSound(void) const { std::cout << "냥냥" << std::endl; }