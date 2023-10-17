/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hujeong <hujeong@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/12 19:19:02 by hujeong           #+#    #+#             */
/*   Updated: 2023/10/18 00:18:33 by hujeong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

#include <cmath>
#include <iomanip>
#include <iostream>
#include <sstream>

Tinput ScalarConverter::t_;
std::stringstream ScalarConverter::ss_;
int ScalarConverter::dot_;
size_t ScalarConverter::precision_;

bool ScalarConverter::cImpossible_;
bool ScalarConverter::cNonDisplayable_;
bool ScalarConverter::iImpossible_;

char ScalarConverter::c_;
int ScalarConverter::i_;
float ScalarConverter::f_;
double ScalarConverter::d_;

ScalarConverter::ScalarConverter() {}
ScalarConverter::ScalarConverter(const ScalarConverter &) {}
ScalarConverter &ScalarConverter::operator=(const ScalarConverter &) {
  return *this;
}
ScalarConverter::~ScalarConverter() {}

void ScalarConverter::convertChar(int i) {
  if (std::isgraph(i)) {
    c_ = static_cast<char>(i_);
  } else
    cNonDisplayable_ = true;
}

void ScalarConverter::convertChar(double d) {
  if (d == static_cast<int>(d)) {
    cImpossible_ = false;
    convertChar(static_cast<int>(d));
  } else
    cImpossible_ = true;
}

void ScalarConverter::convertInt(double d) {
  if (d > INT_MAX || d < INT_MIN) {
    iImpossible_ = true;
  } else
    i_ = static_cast<int>(d);
}

bool ScalarConverter::isNaN(std::string &input) {
  if (input.empty()) return true;
  for (size_t i = 0; i < input.size(); ++i) {
    if (i == 0) {
      if (input[0] == '.')
        return true;
      else if (input[0] == '-' || input[0] == '+')
        continue;
    } else if (input[i] == '.') {
      ++dot_;
      precision_ = input.size() - i - 1;
      if (dot_ == 2) return true;
    } else if (!std::isdigit(input[i]))
      return true;
  }
  return false;
}

bool ScalarConverter::isInt(std::string &input) {
  std::stringstream ss1;
  std::stringstream ss2;
  int num;
  ss1 << input;
  ss1 >> num;

  ss2 << num;
  if (input == ss2.str()) return true;
  return false;
}

void ScalarConverter::checkInput(std::string &input) {
  cNonDisplayable_ = false;
  cImpossible_ = false;
  iImpossible_ = false;
  if (isNaN(input))
    t_ = NAN_T;
  else if (input.size() == 1 && !std::isdigit(input[0]))
    t_ = CHAR_T;
  else if (isInt(input))
    t_ = INT_T;
  else
    t_ = DOUBLE_T;
}

void ScalarConverter::convertFromChar() {
  ss_ >> c_;
  i_ = static_cast<int>(c_);
  f_ = static_cast<float>(c_);
  d_ = static_cast<double>(c_);
}

void ScalarConverter::convertFromInt() {
  ss_ >> i_;
  convertChar(i_);
  f_ = static_cast<float>(i_);
  d_ = static_cast<double>(i_);
}

void ScalarConverter::convertFromDouble() {
  ss_ >> d_;
  convertChar(static_cast<float>(d_));
  convertInt(static_cast<float>(d_));
  f_ = static_cast<float>(d_);
}

void ScalarConverter::printChar() {
  std::cout << "char: ";
  if (t_ == NAN_T || cImpossible_)
    std::cout << "impossible" << std::endl;
  else if (cNonDisplayable_)
    std::cout << "Non displayable" << std::endl;
  else
    std::cout << c_ << std::endl;
}

void ScalarConverter::printInt() {
  std::cout << "int: ";
  if (t_ == NAN_T || iImpossible_)
    std::cout << "impossible" << std::endl;
  else
    std::cout << i_ << std::endl;
}

void ScalarConverter::printFloat() {
  std::cout << "float: ";
  if (t_ == NAN_T)
    std::cout << "nanf" << std::endl;
  else
    std::cout << std::fixed << std::setprecision(precision_) << f_ << "f"
              << std::endl;
}

void ScalarConverter::printDouble() {
  std::cout << "double: ";
  if (t_ == NAN_T)
    std::cout << "nan" << std::endl;
  else
    std::cout << std::fixed << std::setprecision(precision_) << d_ << std::endl;
}

void ScalarConverter::convert(std::string &input) {
  dot_ = 0;
  precision_ = 1;
  ss_ << input;
  checkInput(input);
  switch (t_) {
    case CHAR_T:
      convertFromChar();
      break;
    case INT_T:
      convertFromInt();
      break;
    case DOUBLE_T:
      convertFromDouble();
      break;
    default:
      break;
  }
  printChar();
  printInt();
  printFloat();
  printDouble();
}