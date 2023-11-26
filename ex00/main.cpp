/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hujeong <hujeong@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 15:37:06 by hujeong           #+#    #+#             */
/*   Updated: 2023/11/25 20:18:21 by hujeong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

int main(int argc, char **argv) {
  if (argc != 2) {
    std::cout << "사용법 : ./btc input파일" << std::endl;
    return 0;
  }
  try {
    BitcoinExchange btc(argv[1]);
    btc.parseInput();
  } catch (std::exception &e) {
    std::cout << e.what() << std::endl;
  }
  return 0;
}