/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hujeong <hujeong@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/17 06:42:18 by hujeong           #+#    #+#             */
/*   Updated: 2023/07/21 15:11:21 by hujeong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

#include <iostream>

enum {
  DEBUG = 1,
  INFO,
  WARNING,
  ERROR,
};

Harl::Harl() {
  _func[0] = &Harl::debug;
  _func[1] = &Harl::info;
  _func[2] = &Harl::warning;
  _func[3] = &Harl::error;
}

void Harl::complain(std::string level) {
  int i = 1 * (level == "DEBUG") + 2 * (level == "INFO") +
          3 * (level == "WARNING") + 4 * (level == "ERROR");
  switch (i) {
    case DEBUG:
      (this->*_func[0])();
      (this->*_func[1])();
      (this->*_func[2])();
      (this->*_func[3])();
      return ;
    case INFO:
      (this->*_func[1])();
      (this->*_func[2])();
      (this->*_func[3])();
      return ;
    case WARNING:
      (this->*_func[2])();
      (this->*_func[3])();
      return ;
    case ERROR:
      (this->*_func[3])();
      return;
    default:
      std::cout << "Invalid level" << std::endl;
      return;
  }
}

void Harl::debug(void) { std::cout << "DEBUG MESSAGE" << std::endl; }
void Harl::info(void) { std::cout << "INFO MESSAGE" << std::endl; }
void Harl::warning(void) { std::cout << "WARNING MESSAGE" << std::endl; }
void Harl::error(void) { std::cout << "ERROR MESSAGE" << std::endl; }