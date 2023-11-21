/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hujeong <hujeong@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 21:25:55 by hujeong           #+#    #+#             */
/*   Updated: 2023/11/21 22:08:32 by hujeong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

#include <iostream>
#include <sstream>

RPN::RPN() {}
RPN::~RPN() {}
RPN::RPN(const RPN &) {}
const RPN &RPN::operator=(const RPN &) { return *this; }

void RPN::addParam(const std::string &param) {
  if (param.size() == 1 && param[0] >= '0' && param[0] <= '9') {
    std::stringstream ss(param);
    int val;
    ss >> val;
    _s.push(val);
  } else {
    if (_s.empty()) throw std::runtime_error("Error");
    int a = _s.top();
    _s.pop();
    if (_s.empty()) throw std::runtime_error("Error");
    int b = _s.top();
    _s.pop();

    if (param == "+") {
      _s.push(a + b);
    } else if (param == "-") {
      _s.push(a - b);
    } else if (param == "*") {
      _s.push(a * b);
    } else if (param == "/") {
      _s.push(a / b);
    } else {
      throw std::runtime_error("Error");
    }
  }
}

void RPN::showResult() {
  if (_s.size() != 1) throw std::runtime_error("Error");
  std::cout << _s.top() << std::endl;
}