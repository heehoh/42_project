/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hujeong <hujeong@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/11 21:12:50 by hujeong           #+#    #+#             */
/*   Updated: 2023/10/14 15:56:47 by hujeong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"

#include <iostream>

#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

Intern::Intern() {}
Intern::Intern(const Intern&) {}
Intern& Intern::operator=(const Intern&) { return *this; }
Intern::~Intern() {}

AForm* Intern::makeForm(const std::string& name, const std::string& target) {
  AForm* form;
  int i = 1 * (name == "shrubbery creation") +
          2 * (name == "robotomy request") +
          3 * (name == "presidential pardon");
  switch (i) {
    case 1:
      form = new ShrubberyCreationForm(target);
      break;
    case 2:
      form = new RobotomyRequestForm(target);
      break;
    case 3:
      form = new PresidentialPardonForm(target);
      break;
    default:
      throw "인턴은 " + name + "을(를) 만들지 못합니다";
  }
  std::cout << "인턴은 " << form->getName() << "을(를) 만들었습니다"
            << std::endl;
  return form;
}