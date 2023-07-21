/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hujeong <hujeong@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/17 06:42:18 by hujeong           #+#    #+#             */
/*   Updated: 2023/07/18 19:17:18 by hujeong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

#include <iostream>

enum {
  DEBUG,
  INFO,
  WARNING,
  ERROR,
};

Harl::Harl() {
  _level[0] = "DEBUG";
  _level[1] = "INFO";
  _level[2] = "WARNING";
  _level[3] = "ERROR";
  _func[0] = &Harl::debug;
  _func[1] = &Harl::info;
  _func[2] = &Harl::warning;
  _func[3] = &Harl::error;
}

void Harl::complain(std::string level) {
  int i;
  for (i = 0; i < 4; i++) {
    if (_level[i] == level) {
      break;
    }
  }
  switch (i) {
    case DEBUG:
      (this->*_func[0])();
    case INFO:
      (this->*_func[1])();
    case WARNING:
      (this->*_func[2])();
    case ERROR:
      (this->*_func[3])();
      return;
    default:
      std::cout << "Invalid level" << std::endl;
      return;
  }
}

void Harl::debug(void) { std::cout << "DEBUG" << std::endl; }
void Harl::info(void) { std::cout << "INFO" << std::endl; }
void Harl::warning(void) { std::cout << "WARNING" << std::endl; }
void Harl::error(void) { std::cout << "ERROR" << std::endl; }