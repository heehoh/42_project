/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hujeong <hujeong@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/12 19:19:02 by hujeong           #+#    #+#             */
/*   Updated: 2023/10/15 21:27:20 by hujeong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

#include <iostream>
#include <sstream>

ScalarConverter::ScalarConverter() {}
ScalarConverter::ScalarConverter(const ScalarConverter &) {}
ScalarConverter &ScalarConverter::operator=(const ScalarConverter &) {
  return *this;
}
ScalarConverter::~ScalarConverter() {}

void ScalarConverter::convert(std::string input) {
  std::stringstream ss;
  ss << input;

  std::cout << "char: " << input << "\nint: " << input << "\nfloat: " << input
            << "\ndouble: " << input << std::endl;
}