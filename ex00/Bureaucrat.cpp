/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hujeong <hujeong@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/09 15:12:00 by hujeong           #+#    #+#             */
/*   Updated: 2023/10/03 21:42:59 by hujeong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

#include <iostream>

Bureaucrat::Bureaucrat(const std::string& name, int grade) : name_(name) {
  if (grade < 1)
    throw GradeTooHighException();
  else if (grade > 150)
    throw GradeTooLowException();
  grade_ = grade;
}

Bureaucrat::Bureaucrat(const Bureaucrat& other)
    : name_(other.name_), grade_(other.grade_) {}

Bureaucrat::~Bureaucrat() {}

Bureaucrat& Bureaucrat::operator=(const Bureaucrat& other) {
  grade_ = other.grade_;
  return *this;
}

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

const char* Bureaucrat::GradeTooHighException::what() const throw() {
  return "관료 등급 상한 에러: 관료 등급은 1등급이 최상 등급입니다.";
}

const char* Bureaucrat::GradeTooLowException::what() const throw() {
  return "관료 등급 하한 에러: 관료 등급은 150등급이 최하 등급입니다.";
}

std::ostream& operator<<(std::ostream& os, const Bureaucrat& bureaucrat) {
  os << "관료 이름: " << bureaucrat.getName()
     << ", 관료 등급: " << bureaucrat.getGrade() << std::endl;
  return os;
}