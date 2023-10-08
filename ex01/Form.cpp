/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hujeong <hujeong@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/04 19:57:24 by hujeong           #+#    #+#             */
/*   Updated: 2023/10/08 17:20:36 by hujeong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

#include <iostream>

#include "Bureaucrat.hpp"

Form::Form(const std::string& name, int gradeToSign, int gradeToExec)
    : name_(name),
      signed_(false),
      gradeToSign_(gradeToSign),
      gradeToExec_(gradeToExec) {
  if (gradeToSign_ < 1 || gradeToExec_ < 1)
    throw GradeTooHighException();
  else if (gradeToSign_ > 150 || gradeToExec_ > 150)
    throw GradeTooLowException();
}

Form::~Form() {}

const std::string& Form::getName() const { return name_; }
const bool& Form::getSigned() const { return signed_; }
const int& Form::getGradeToSign() const { return gradeToSign_; }
const int& Form::getGradeToExec() const { return gradeToExec_; }

void Form::beSigned(const Bureaucrat& bureaucrat) {
  if (bureaucrat.getGrade() > gradeToSign_) throw Form::GradeTooLowException();
  signed_ = true;
  std::cout << name_ << "이(가) 서명되었습니다" << std::endl;
}

const char* Form::GradeTooLowException::what() const throw() {
  return "등급이 낮습니다";
}

const char* Form::GradeTooHighException::what() const throw() {
  return "등급이 높습니다";
}

std::ostream& operator<<(std::ostream& os, const Form& form) {
  os << "서류 명칭: " << form.getName() << "\n서류 서명: "
     << (form.getSigned() == true ? "서명됨" : "서명되지 않음")
     << "\n서명 등급: " << form.getGradeToSign()
     << "\n실행 등급: " << form.getGradeToExec() << std::endl;
  return os;
}
