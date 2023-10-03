/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hujeong <hujeong@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/09 15:11:31 by hujeong           #+#    #+#             */
/*   Updated: 2023/10/03 21:47:15 by hujeong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

#include "Bureaucrat.hpp"

int main() {
  try {
    Bureaucrat b1("관료 1", 1);
    std::cout << b1;
    std::cout << "관료 1을 등급을 상향시킵니다." << std::endl;
    b1.incrementGrade();
    std::cout << b1;
  } catch (std::exception& e) {
    std::cout << e.what() << std::endl;
  }

  try {
    Bureaucrat b2("관료 2", 150);
    std::cout << b2;
    std::cout << "관료 2를 등급을 하향시킵니다." << std::endl;
    b2.decrementGrade();
    std::cout << b2;
  } catch (std::exception& e) {
    std::cout << e.what() << std::endl;
  }

  return 0;
}