/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hujeong <hujeong@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/02 16:41:49 by hujeong           #+#    #+#             */
/*   Updated: 2023/09/02 16:44:26 by hujeong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongCat.hpp"

WrongCat::WrongCat(void) : WrongAnimal() {
  std::cout << "WrongCat 기본 생성자 호출" << std::endl;
}

WrongCat::WrongCat(const WrongCat& copy) : WrongAnimal(copy) {
  std::cout << "WrongCat 복사 생성자 호출" << std::endl;
}

WrongCat::~WrongCat(void) { std::cout << "WrongCat 소멸자 호출" << std::endl; }

WrongCat& WrongCat::operator=(const WrongCat& src) {
  std::cout << "WrongCat 대입 연산자 호출" << std::endl;
  type = src.getType();
  return *this;
}

void WrongCat::makeSound(void) const {
  std::cout << "WrongCat 울음소리" << std::endl;
}