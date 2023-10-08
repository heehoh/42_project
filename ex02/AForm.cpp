/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hujeong <hujeong@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/04 19:57:24 by hujeong           #+#    #+#             */
/*   Updated: 2023/10/08 21:32:49 by hujeong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"

#include <iostream>

#include "Bureaucrat.hpp"

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
