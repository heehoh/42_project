/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hujeong <hujeong@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/28 22:56:10 by hujeong           #+#    #+#             */
/*   Updated: 2023/07/31 02:00:33 by hujeong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

#include <iostream>

Fixed::Fixed(void) : _value(0) {
  std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const int value) {
  std::cout << "Int constructor called" << std::endl;
  _value = value << _bits;
}

Fixed::Fixed(const float value) {
  std::cout << "Float constructor called" << std::endl;
  _value = roundf(value * (1 << _bits));
}

Fixed::Fixed(const Fixed& src) {
  std::cout << "Copy constructor called" << std::endl;
  _value = src.getRawBits();
}

Fixed::~Fixed(void) { std::cout << "Destructor called" << std::endl; }

Fixed& Fixed::operator=(const Fixed& src) {
  std::cout << "Copy assignment operator called" << std::endl;
  _value = src.getRawBits();
  return *this;
}

std::ostream& Fixed::operator<<(const Fixed& fixed) {
  std::ostream& os = std::cout;
  os << fixed.toFloat();
  return os;
}

int Fixed::getRawBits(void) const {
  std::cout << "getRawBits member function called" << std::endl;
  return _value;
}

void Fixed::setRawBits(int const raw) {
  std::cout << "setRawBits member function called" << std::endl;
  _value = raw;
}

float Fixed::toFloat(void) const { return (float)_value / (1 << _bits); }

int Fixed::toInt(void) const { return _value >> _bits; }