/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hujeong <hujeong@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/17 06:42:26 by hujeong           #+#    #+#             */
/*   Updated: 2023/07/18 19:03:00 by hujeong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

#include "Harl.hpp"

int main(int ac, char **av) {
  Harl harl;

  if (ac != 2) {
    std::cout << "Usage: ./ex06 <level>" << std::endl;
    return 1;
  }
  harl.complain(av[1]);
  return 0;
}