/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hujeong <hujeong@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/17 06:42:26 by hujeong           #+#    #+#             */
/*   Updated: 2023/08/06 11:08:01 by hujeong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

#include "Harl.hpp"

int main(int ac, char **av) {
  Harl harl;

  if (ac != 2) {
    std::cout << "Usage: ./harlFilter <level>" << std::endl;
    return 1;
  }
  harl.complain(av[1]);
  return 0;
}