/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hujeong <hujeong@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/15 01:33:43 by hujeong           #+#    #+#             */
/*   Updated: 2023/07/15 01:42:49 by hujeong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>

int main(void) {
  std::string str = "HI THIS IS BRAIN";
  std::string* ptr = &str;
  std::string& ref = str;

  std::cout << &str << std::endl;
  std::cout << ptr << std::endl;
  std::cout << &ref << std::endl;

  std::cout << str << std::endl;
  std::cout << *ptr << std::endl;
  std::cout << ref << std::endl;
}