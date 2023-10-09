/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hujeong <hujeong@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/04 19:57:24 by hujeong           #+#    #+#             */
/*   Updated: 2023/10/09 00:53:22 by hujeong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"

#include <iostream>

#include "Bureaucrat.hpp"

AForm::AForm() : name_(""), signed_(false), gradeToSign_(0), gradeToExec_(0) {}

AForm::AForm(const AForm& other)
    : name_(other.name_),
      signed_(other.signed_),
      gradeToSign_(other.gradeToSign_),
      gradeToExec_(other.gradeToExec_) {}

AForm& AForm::operator=(const AForm& other) {
  signed_ = other.signed_;
  return *this;
}
AForm::~AForm() {}

AForm::AForm(const std::string& name, int gradeToSign, int gradeToExec)
    : name_(name),
      signed_(false),
      gradeToSign_(gradeToSign),
      gradeToExec_(gradeToExec) {
  if (gradeToSign_ < 1 || gradeToExec_ < 1)
    throw GradeTooHighException();
  else if (gradeToSign_ > 150 || gradeToExec_ > 150)
    throw GradeTooLowException();
}

const std::string& AForm::getName() const { return name_; }
const bool& AForm::getSigned() const { return signed_; }
const int& AForm::getGradeToSign() const { return gradeToSign_; }
const int& AForm::getGradeToExec() const { return gradeToExec_; }

void AForm::beSigned(const Bureaucrat& bureaucrat) {
  if (bureaucrat.getGrade() > gradeToSign_) throw AForm::GradeTooLowException();
  signed_ = true;
  std::cout << name_ << "이(가) 서명되었습니다" << std::endl;
}

const char* AForm::GradeTooLowException::what() const throw() {
  return "등급이 낮습니다";
}

const char* AForm::GradeTooHighException::what() const throw() {
  return "등급이 높습니다";
}

std::ostream& operator<<(std::ostream& os, const AForm& form) {
  os << "서류 명칭: " << form.getName() << "\n서류 서명: "
     << (form.getSigned() == true ? "서명됨" : "서명되지 않음")
     << "\n서명 등급: " << form.getGradeToSign()
     << "\n실행 등급: " << form.getGradeToExec() << std::endl;
  return os;
}
