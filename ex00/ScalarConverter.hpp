/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hujeong <hujeong@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/12 19:19:04 by hujeong           #+#    #+#             */
/*   Updated: 2023/10/14 16:12:00 by hujeong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCALARCONVERTER_HPP
#define SCALARCONVERTER_CPP

#include <sstream>
#include <string>

class ScalarConverter {
 private:
  static char c_;
  static int i_;
  static float f_;
  static double d_;
  ScalarConverter(const ScalarConverter&);
  ScalarConverter& operator=(const ScalarConverter&);
  ScalarConverter();
  ~ScalarConverter();

 public:
  static void convert(std::string literal);
};

#endif