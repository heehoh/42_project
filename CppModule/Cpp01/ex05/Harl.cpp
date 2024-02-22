/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hujeong <hujeong@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/17 06:42:18 by hujeong           #+#    #+#             */
/*   Updated: 2023/07/21 15:22:02 by hujeong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

#include <iostream>

Harl::Harl() {
  _func[0] = &Harl::debug;
  _func[1] = &Harl::info;
  _func[2] = &Harl::warning;
  _func[3] = &Harl::error;
}

void Harl::complain(std::string level) {
  int i = 1 * (level == "DEBUG") + 2 * (level == "INFO") +
          3 * (level == "WARNING") + 4 * (level == "ERROR");
  if (i == 0)
    std::cout << "Invalid level" << std::endl;
  else
    (this->*_func[i - 1])();
}

void Harl::debug(void) { std::cout << "DEBUG MESSAGE" << std::endl; }
void Harl::info(void) { std::cout << "INFO MESSAGE" << std::endl; }
void Harl::warning(void) { std::cout << "WARNING MESSAGE" << std::endl; }
void Harl::error(void) { std::cout << "ERROR MESSAGE" << std::endl; }