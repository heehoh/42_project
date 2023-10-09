/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hujeong <hujeong@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/08 21:19:15 by hujeong           #+#    #+#             */
/*   Updated: 2023/10/09 09:36:09 by hujeong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"

#include <unistd.h>

#include <cstdlib>
#include <iostream>

RobotomyRequest::RobotomyRequest()
    : AForm("RobotomyRequest", 72, 45), target_("") {}

RobotomyRequest::RobotomyRequest(const RobotomyRequest& other)
    : AForm("RobotomyRequest", 72, 45), target_(other.target_) {}

RobotomyRequest& RobotomyRequest::operator=(const RobotomyRequest& other) {
  signed_ = other.signed_;
  return *this;
}

RobotomyRequest::~RobotomyRequest() {}

RobotomyRequest::RobotomyRequest(const std::string& target)
    : AForm("RobotomyRequest", 72, 45), target_(target) {}

const std::string& RobotomyRequest::getTarget() const { return target_; }

void RobotomyRequest::execute(Bureaucrat const& executor) const {
  std::cout << "로봇 만드는 중.";
  for (int i = 0; i < 5; i++) {
    std::cout << ".";
    std::cout.flush();
    usleep(500000);
  }
  std::cout << std::endl;
  if (rand() % 2)
    std::cout << target_ << "성공적으로 완성되었습니다!" << std::endl;
  else
    std::cout << target_ << "생성이 실패했습니다!" << std::endl;
}