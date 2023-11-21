/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hujeong <hujeong@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 22:06:21 by hujeong           #+#    #+#             */
/*   Updated: 2023/11/21 22:12:24 by hujeong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

#include "RPN.hpp"

int main(int ac, char **argv) {
  if (ac != 2) {
    std::cout << "사용법: ./RPN \"수식\"" << std::endl;
  } else {
    try {
      RPN r;

    } catch (std::exception &e) {
      std::cout << e.what() << std::endl;
    }
  }
}