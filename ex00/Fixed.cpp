/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hujeong <hujeong@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/28 22:56:10 by hujeong           #+#    #+#             */
/*   Updated: 2023/08/08 06:49:28 by hujeong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed(void) : _value(0) { std::cout << "기본 생성자 호출" << std::endl; }

Fixed::Fixed(const Fixed& src) {
  std::cout << "복사 생성자 호출" << std::endl;
  _value = src.getRawBits();
}

Fixed::~Fixed(void) { std::cout << "소멸자 호출" << std::endl; }

Fixed& Fixed::operator=(const Fixed& src) {
  std::cout << "복사 대입 연산자 호출" << std::endl;
  _value = src.getRawBits();
  return *this;
}

int Fixed::getRawBits(void) const {
  std::cout << "getRawBits 메소드 호출" << std::endl;
  return _value;
}

void Fixed::setRawBits(int const raw) {
  std::cout << "setRawBits 메소드 호출" << std::endl;
  _value = raw;
}