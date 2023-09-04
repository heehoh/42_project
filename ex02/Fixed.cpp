/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hujeong <hujeong@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/28 22:56:10 by hujeong           #+#    #+#             */
/*   Updated: 2023/09/04 23:23:38 by hujeong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed(void) : _value(0) {
  std::cout << "Fixed 기본 생성자 호출" << std::endl;
}
Fixed::Fixed(const int value) {
  std::cout << "Fixed int 기본 생성자 호출" << std::endl;
  _value = value << _bits;
}
Fixed::Fixed(const float value) {
  std::cout << "Fixed float 기본 생성자 호출" << std::endl;
  _value = roundf(value * (1 << _bits));
}

Fixed::Fixed(const Fixed& src) {
  std::cout << "Fixed 복사 생성자 호출" << std::endl;
  _value = src._value;
}

Fixed::~Fixed(void) { std::cout << "Fixed 소멸자 호출" << std::endl; }

Fixed& Fixed::operator=(const Fixed& src) {
  std::cout << "Fixed 복사 대입 연산자 호출" << std::endl;
  _value = src._value;
  return *this;
}

bool Fixed::operator<(const Fixed& src) const {
  if (_value < src._value) return true;
  return false;
}

bool Fixed::operator<=(const Fixed& src) const {
  if (_value <= src._value) return true;
  return false;
}

bool Fixed::operator>(const Fixed& src) const {
  if (_value > src._value) return true;
  return false;
}

bool Fixed::operator>=(const Fixed& src) const {
  if (_value >= src._value) return true;
  return false;
}

bool Fixed::operator==(const Fixed& src) const {
  if (_value == src._value) return true;
  return false;
}

bool Fixed::operator!=(const Fixed& src) const {
  if (_value != src._value) return true;
  return false;
}

Fixed Fixed::operator+(const Fixed& src) {
  Fixed temp;
  temp.setRawBits(_value + src._value);
  return temp;
}

Fixed Fixed::operator-(const Fixed& src) {
  Fixed temp;
  temp.setRawBits(_value - src._value);
  return temp;
}

Fixed Fixed::operator*(const Fixed& src) {
  Fixed temp;
  temp.setRawBits((_value * src._value) >> _bits);
  return temp;
}

Fixed Fixed::operator/(const Fixed& src) {
  Fixed temp;
  temp.setRawBits((_value << _bits) / src._value);
  return temp;
}

Fixed& Fixed::operator++(void) {
  ++_value;
  return *this;
}

Fixed Fixed::operator++(int) {
  Fixed temp(*this);
  _value++;
  return temp;
}

Fixed& Fixed::operator--(void) {
  --_value;
  return *this;
}

Fixed Fixed::operator--(int) {
  Fixed temp(*this);
  _value--;
  return temp;
}

Fixed& Fixed::min(Fixed& a, Fixed& b) {
  if (a < b) return a;
  return b;
}

const Fixed& Fixed::min(const Fixed& a, const Fixed& b) {
  if (a < b) return a;
  return b;
}

Fixed& Fixed::max(Fixed& a, Fixed& b) {
  if (a > b) return a;
  return b;
}

const Fixed& Fixed::max(const Fixed& a, const Fixed& b) {
  if (a > b) return a;
  return b;
}

int Fixed::getRawBits(void) const {
  std::cout << "Fixed getRawBits 메소드 호출" << std::endl;
  return _value;
}

void Fixed::setRawBits(int const raw) {
  std::cout << "Fixed setRawBits 메소드 호출" << std::endl;
  _value = raw;
}

float Fixed::toFloat(void) const { return (float)_value / (1 << _bits); }

int Fixed::toInt(void) const { return _value >> _bits; }

std::ostream& operator<<(std::ostream& os, const Fixed& fixed) {
  os << fixed.toFloat();
  return os;
}