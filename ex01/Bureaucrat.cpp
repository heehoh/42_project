/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hujeong <hujeong@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/09 15:12:00 by hujeong           #+#    #+#             */
/*   Updated: 2023/10/08 21:53:15 by hujeong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

#include <iostream>

#include "Form.hpp"

Bureaucrat::Bureaucrat() : name_(""), grade_(1) {}

Bureaucrat::Bureaucrat(const Bureaucrat& other)
    : name_(other.name_), grade_(other.grade_) {}

Bureaucrat::Bureaucrat(const std::string& name, int grade)
    : name_(name), grade_(grade) {
  if (grade < 1)
    throw GradeTooHighException();
  else if (grade > 150)
    throw GradeTooLowException();
}

Bureaucrat::~Bureaucrat() {}

const std::string& Bureaucrat::getName() const { return name_; }
int Bureaucrat::getGrade() const { return grade_; }

void Bureaucrat::incrementGrade() {
  if (grade_ - 1 < 1) throw GradeTooHighException();
  --grade_;
}

void Bureaucrat::decrementGrade() {
  if (grade_ + 1 > 150) throw GradeTooLowException();
  ++grade_;
}

void Bureaucrat::signForm(Form& form) {
  try {
    std::cout << name_ << "이(가) " << form.getName() << "에 서명하려고 합니다"
              << std::endl;
    form.beSigned(*this);
  } catch (std::exception& e) {
    std::cout << name_ << "이(가) " << form.getName()
              << "에 서명하지 못했습니다. 관료 " << e.what() << std::endl;
  }
}

const char* Bureaucrat::GradeTooHighException::what() const throw() {
  return "관료 등급이 너무 높습니다. 관료 등급은 1등급이 최상 등급입니다.";
}

const char* Bureaucrat::GradeTooLowException::what() const throw() {
  return "관료 등급이 너무 낮습니다. 관료 등급은 150등급이 최하 등급입니다.";
}

std::ostream& operator<<(std::ostream& os, const Bureaucrat& bureaucrat) {
  os << "관료 이름: " << bureaucrat.getName()
     << "\n관료 등급: " << bureaucrat.getGrade() << std::endl;
  return os;
}