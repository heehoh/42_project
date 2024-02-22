/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hujeong <hujeong@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/09 15:11:31 by hujeong           #+#    #+#             */
/*   Updated: 2023/10/08 17:21:08 by hujeong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

#include "Bureaucrat.hpp"
#include "Form.hpp"

int main() {
  std::cout << "-------서류 생성--------" << std::endl;
  try {
    Form file1("1등급 서류", 1, 1);
    std::cout << file1;
    Form errFile("에러 서류", 151, 1);
  } catch (std::exception& e) {
    std::cout << "서류 " << e.what() << std::endl;
  }
  try {
    Form errFile("에러 서류", 0, 1);
  } catch (std::exception& e) {
    std::cout << "서류 " << e.what() << std::endl;
  }
  std::cout << "\n-------서류 생성 및 서명--------" << std::endl;
  Bureaucrat highB("1등급 관료", 1);
  Bureaucrat lowB("150등급 관료", 150);
  Form highFile("1등급 서류", 1, 1);
  Form lowFile("150등급 서류", 150, 150);

  highB.signForm(lowFile);
  std::cout << std::endl;
  lowB.signForm(lowFile);
  std::cout << std::endl;

  std::cout << lowFile << std::endl;
  lowB.signForm(highFile);
  std::cout << "\n" << highFile << std::endl;
  highB.signForm(highFile);
  std::cout << "\n" << highFile << std::endl;
  return 0;
}