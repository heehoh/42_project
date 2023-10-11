/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hujeong <hujeong@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/11 21:12:50 by hujeong           #+#    #+#             */
/*   Updated: 2023/10/11 21:50:32 by hujeong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"

#include <iostream>

#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

Intern::Intern() {}
Intern::Intern(const Intern& other) {}
Intern& Intern::operator=(const Intern& other) {}
Intern::~Intern() {}

AForm* Intern::makeShrubberyCreationForm(const std::string& name,
                                         const std::string& target) {
  if (name != "shrubbery creation") return;
  new ShrubberyCreationForm(target);
}

AForm* Intern::makeRobotomyRequestForm(const std::string& name,
                                       const std::string& target) {
  if (name != "robotomy request") return;
  return new RobotomyRequestForm(target);
}

AForm* Intern::makePresidentialPardonForm(const std::string& name,
                                          const std::string& target) {
  if (name != "presidential pardon") return;
  new PresidentialPardonForm(target);
}

const char* Intern::MakeFormException::what() const throw() {
  return "은(는) 만들 수 없습니다";
}

AForm* Intern::makeForm(const std::string& name, const std::string& target) {
  try {
    makeShrubberyCreationForm(name, target);
    makeRobotomyRequestForm(name, target);
    makePresidentialPardonForm(name, target);
    throw MakeFormException();
  } catch (std::exception& e) {
    std::cout << "인턴: " << name << e.what() << std::endl;
  }
}