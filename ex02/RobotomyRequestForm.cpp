/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hujeong <hujeong@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/08 21:19:15 by hujeong           #+#    #+#             */
/*   Updated: 2023/10/10 13:39:25 by hujeong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"

#include <unistd.h>

#include <cstdlib>
#include <ctime>
#include <iostream>

RobotomyRequestForm::RobotomyRequestForm()
    : AForm("RobotomyRequest", 72, 45), target_("") {}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& other)
    : AForm("RobotomyRequest", 72, 45), target_(other.target_) {}

RobotomyRequestForm& RobotomyRequestForm::operator=(
    const RobotomyRequestForm& other) {
  if (this == &other) return *this;
  return *this;
}

RobotomyRequestForm::~RobotomyRequestForm() {}

RobotomyRequestForm::RobotomyRequestForm(const std::string& target)
    : AForm("RobotomyRequest", 72, 45), target_(target) {}

const std::string& RobotomyRequestForm::getTarget() const { return target_; }

void RobotomyRequestForm::execute(Bureaucrat const& executor) const {
  AForm::execute(executor);
  std::cout << "로봇 만드는 중.";
  for (int i = 0; i < 5; i++) {
    std::cout << ".";
    std::cout.flush();
    usleep(500000);
  }
  std::cout << std::endl;
  srand(time(NULL));
  if (rand() % 2)
    std::cout << target_ << "이(가) 성공적으로 완성되었습니다! 🤖🤖"
              << std::endl;
  else
    std::cout << target_ << "이(가) 생성이 실패했습니다! 💥💥" << std::endl;
}