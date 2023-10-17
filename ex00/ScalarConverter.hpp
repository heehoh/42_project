/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hujeong <hujeong@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/12 19:19:04 by hujeong           #+#    #+#             */
/*   Updated: 2023/10/18 00:18:52 by hujeong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCALARCONVERTER_HPP
#define SCALARCONVERTER_HPP

#include <string>

enum Tinput { CHAR_T, INT_T, FLOAT_T, DOUBLE_T, NAN_T };
class ScalarConverter {
 private:
  static Tinput t_;
  static std::stringstream ss_;
  static int dot_;
  static size_t precision_;

  static bool cNonDisplayable_;
  static bool cImpossible_;
  static bool iImpossible_;

  static char c_;
  static int i_;
  static float f_;
  static double d_;

  ScalarConverter(const ScalarConverter &);
  ScalarConverter &operator=(const ScalarConverter &);
  ScalarConverter();
  ~ScalarConverter();
  static void checkInput(std::string &input);
  static bool isNaN(std::string &input);
  static bool isInt(std::string &input);

  static void convertChar(int i);
  static void convertChar(double d);
  static void convertInt(double d);

  static void convertFromChar();
  static void convertFromInt();
  static void convertFromDouble();

  static void printChar();
  static void printInt();
  static void printFloat();
  static void printDouble();

 public:
  static void convert(std::string &input);
};

#endif