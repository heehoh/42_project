/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hujeong <hujeong@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/12 19:19:04 by hujeong           #+#    #+#             */
/*   Updated: 2023/10/15 14:31:44 by hujeong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCALARCONVERTER_HPP
#define SCALARCONVERTER_HPP

#include <string>

class ScalarConverter {
 private:
  ScalarConverter(const ScalarConverter&);
  ScalarConverter& operator=(const ScalarConverter&);
  ScalarConverter();
  ~ScalarConverter();

 public:
  static void convert(std::string input);
};

#endif