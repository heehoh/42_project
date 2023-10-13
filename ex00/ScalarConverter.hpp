/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hujeong <hujeong@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/12 19:19:04 by hujeong           #+#    #+#             */
/*   Updated: 2023/10/13 22:06:04 by hujeong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCALARCONVERTER_HPP
#define SCALARCONVERTER_CPP

#include <sstream>
#include <string>

class ScalarConverter {
 private:
  static std::stringstream ss;
  ScalarConverter(const ScalarConverter& other);
  ScalarConverter& operator=(const ScalarConverter& other);

 public:
  ScalarConverter();
  ~ScalarConverter();
  void convert(std::string literal);
};

#endif