/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hujeong <hujeong@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/28 22:55:29 by hujeong           #+#    #+#             */
/*   Updated: 2023/09/04 22:18:39 by hujeong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>

class Fixed {
 public:
  Fixed(void);
  Fixed(const int value);
  Fixed(const float value);
  Fixed(const Fixed& src);
  ~Fixed(void);
  Fixed& operator=(const Fixed& src);
  bool operator<(const Fixed& src) const;
  bool operator>(const Fixed& src) const;
  bool operator<=(const Fixed& src) const;
  bool operator>=(const Fixed& src) const;
  bool operator==(const Fixed& src) const;
  bool operator!=(const Fixed& src) const;
  Fixed operator+(const Fixed& src);
  Fixed operator-(const Fixed& src);
  Fixed operator*(const Fixed& src);
  Fixed operator/(const Fixed& src);
  Fixed& operator++(void);
  Fixed operator++(int);
  Fixed& operator--(void);
  Fixed operator--(int);

  int getRawBits(void) const;
  void setRawBits(int const raw);
  float toFloat(void) const;
  int toInt(void) const;
  static Fixed& min(Fixed& a, Fixed& b);
  static const Fixed& min(const Fixed& a, const Fixed& b);
  static Fixed& max(Fixed& a, Fixed& b);
  static const Fixed& max(const Fixed& a, const Fixed& b);

 private:
  int _value;
  static const int _bits = 8;
};

std::ostream& operator<<(std::ostream& os, const Fixed& fixed);

#endif