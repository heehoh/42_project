/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hujeong <hujeong@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/09 15:11:31 by hujeong           #+#    #+#             */
/*   Updated: 2023/10/08 21:57:14 by hujeong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

#include "Bureaucrat.hpp"

int main() {
  try {
    std::cout << "---------관료 생성--------" << std::endl;
    Bureaucrat b1("관료 1", 50);
    std::cout << b1 << std::endl;
    std::cout << "---------관료 생성 에러--------" << std::endl;
    Bureaucrat b_err("관료 에러", 0);
    std::cout << b_err;
  } catch (std::exception& e) {
    std::cout << e.what() << std::endl;
  }
  try {
    std::cout << "\n---------관료 생성 에러--------" << std::endl;
    Bureaucrat b_err("관료 에러", 151);
    std::cout << b_err;
  } catch (std::exception& e) {
    std::cout << e.what() << std::endl;
  }
  try {
    std::cout << "\n---------관료 생성--------" << std::endl;
    Bureaucrat b2("관료 2", 1);
    std::cout << b2;
    std::cout << "관료 2의 등급을 상향시킵니다." << std::endl;
    b2.incrementGrade();
    std::cout << b2;
  } catch (std::exception& e) {
    std::cout << e.what() << std::endl;
  }

  try {
    std::cout << "\n---------관료 생성--------" << std::endl;
    Bureaucrat b3("관료 3", 150);
    std::cout << b3;
    std::cout << "관료 3의 등급을 하향시킵니다." << std::endl;
    b3.decrementGrade();
    std::cout << b3;
  } catch (std::exception& e) {
    std::cout << e.what() << std::endl;
  }

  return 0;
}