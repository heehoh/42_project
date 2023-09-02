/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hujeong <hujeong@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/02 16:35:50 by hujeong           #+#    #+#             */
/*   Updated: 2023/09/02 16:43:44 by hujeong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal(void) : type("WrongAnimal") {
  std::cout << "WrongAnimal 기본 생성자 호출" << std::endl;
}

WrongAnimal::WrongAnimal(const WrongAnimal& copy) : type(copy.getType()) {
  std::cout << "WrongAnimal 복사 생성자 호출" << std::endl;
}

WrongAnimal::~WrongAnimal(void) {
  std::cout << "WrongAnimal 소멸자 호출" << std::endl;
}

WrongAnimal& WrongAnimal::operator=(const WrongAnimal& src) {
  std::cout << "WrongAnimal 대입 연산자 호출" << std::endl;
  type = src.getType();
  return *this;
}

std::string WrongAnimal::getType(void) const { return this->type; }

void WrongAnimal::makeSound(void) const {
  std::cout << "WrongAnimal 울음소리" << std::endl;
}
