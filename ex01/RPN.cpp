/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hujeong <hujeong@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 21:25:55 by hujeong           #+#    #+#             */
/*   Updated: 2023/11/26 18:26:23 by hujeong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

#include <iostream>
#include <sstream>

RPN::RPN() {}
RPN::~RPN() {}
RPN::RPN(const RPN &) {}
const RPN &RPN::operator=(const RPN &) { return *this; }

void RPN::calculate(const std::string &input) {
  std::stringstream ss(input);
  std::string param;
  while (ss >> param) {
    if (param.size() == 1 && param[0] >= '0' && param[0] <= '9') {
      std::stringstream ss1(param);
      double val;
      ss1 >> val;
      stack_.push(val);
    } else {
      if (stack_.empty()) throw std::runtime_error("Error");
      double a = stack_.top();
      stack_.pop();
      if (stack_.empty()) throw std::runtime_error("Error");
      double b = stack_.top();
      stack_.pop();

      if (param == "+") {
        stack_.push(b + a);
      } else if (param == "-") {
        stack_.push(b - a);
      } else if (param == "*") {
        stack_.push(a * b);
      } else if (param == "/") {
        stack_.push(b / a);
      } else {
        throw std::runtime_error("Error");
      }
    }
  }
  showResult();
}

void RPN::showResult() {
  if (stack_.size() != 1) throw std::runtime_error("Error");
  std::cout << stack_.top() << std::endl;
}