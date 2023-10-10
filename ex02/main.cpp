/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hujeong <hujeong@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/09 15:11:31 by hujeong           #+#    #+#             */
/*   Updated: 2023/10/10 13:44:18 by hujeong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

#include <iostream>

#include "Bureaucrat.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

void delay() {
  for (int i = 0; i < 3; i++) {
    usleep(400000);
  }
  std::cout << std::endl;
}

int main() {
  Bureaucrat b1("1등급 관료", 1);
  Bureaucrat b2("150등급 관료", 150);

  PresidentialPardonForm f1("수감자1");
  RobotomyRequestForm f2("로봇1");
  ShrubberyCreationForm f3("마당");

  std::cout << "---------150 등급 관료가 서명합니다-------" << std::endl;
  delay();
  b2.signForm(f1);
  delay();
  b2.signForm(f2);
  delay();
  b2.signForm(f3);
  delay();
  std::cout << "\n---------150 등급 관료가 실행합니다-------" << std::endl;
  delay();
  b2.executeForm(f1);
  delay();
  b2.executeForm(f2);
  delay();
  b2.executeForm(f3);
  delay();
  std::cout << "\n---------1 등급 관료가 서명합니다-------" << std::endl;
  delay();
  b1.signForm(f1);
  delay();
  b1.signForm(f2);
  delay();
  b1.signForm(f3);
  delay();
  std::cout << "\n---------150 등급 관료가 실행합니다-------" << std::endl;
  delay();
  b2.executeForm(f1);
  delay();
  b2.executeForm(f2);
  delay();
  b2.executeForm(f3);
  delay();
  std::cout << "\n---------1 등급 관료가 실행합니다-------" << std::endl;
  delay();
  b1.executeForm(f1);
  delay();
  b1.executeForm(f2);
  delay();
  b1.executeForm(f3);
}