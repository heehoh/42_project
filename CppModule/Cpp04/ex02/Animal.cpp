/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hujeong <hujeong@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/02 14:35:10 by hujeong           #+#    #+#             */
/*   Updated: 2023/10/01 14:11:23 by hujeong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

Animal::Animal(void) : type("Animal") {
  std::cout << "Animal 기본 생성자 호출" << std::endl;
}
Animal::Animal(const Animal& copy) : type(copy.getType()) {
  std::cout << "Animal 복사 생성자 호출" << std::endl;
}
Animal::~Animal(void) { std::cout << "Animal 소멸자 호출" << std::endl; }
Animal& Animal::operator=(const Animal& src) {
  std::cout << "Animal 대입 연산자 호출" << std::endl;
  this->type = src.type;
  return *this;
}

std::string Animal::getType(void) const { return this->type; }