/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hujeong <hujeong@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/28 22:55:29 by hujeong           #+#    #+#             */
/*   Updated: 2023/08/01 12:27:18 by hujeong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>

class Fixed {
 public:
  Fixed(void);
  Fixed(const Fixed& src);
  ~Fixed(void);
  Fixed& operator=(const Fixed& src);

  int getRawBits(void) const;
  void setRawBits(int const raw);

 private:
  int _value;
  static const int _bits = 8;
};

#endif