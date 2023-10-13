/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hujeong <hujeong@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/13 21:52:49 by hujeong           #+#    #+#             */
/*   Updated: 2023/10/13 22:10:16 by hujeong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <sstream>
#include <string>

int main(int argc, char **argv) {
  std::stringstream ss;

  std::string str = "7.1.1";

  int num = 0;
  double ll;

  ss << str;
  // ss >> num;
  ss >> ll;
  // ss >> ll;
  // ss >> ll;
  std::cout << num << std::endl;
  std::cout << ll << std::endl;
  return 0;
}