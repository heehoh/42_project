/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hujeong <hujeong@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/13 21:52:49 by hujeong           #+#    #+#             */
/*   Updated: 2023/10/17 22:57:40 by hujeong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <sstream>

#include "ScalarConverter.hpp"

int main(int ac, char **av) {
  if (ac != 2)
    std::cout << "사용법 : ./convert [인자]" << std::endl;
  else {
    std::string str;
    str = av[1];
    ScalarConverter::convert(str);
  }
  return 0;
}