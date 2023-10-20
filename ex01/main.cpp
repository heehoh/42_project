/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hujeong <hujeong@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/19 07:55:10 by hujeong           #+#    #+#             */
/*   Updated: 2023/10/20 11:05:33 by hujeong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

#include "iter.hpp"

template <typename T>
void print(T &x) {
  std::cout << x << " ";
}

int main() {
  int intArr[5] = {1, 2, 3, 4, 5};
  std::string strArr[5] = {"a", "b", "c", "d", "e"};

  std::cout << "intArr: ";
  iter(intArr, 5, print);
  std::cout << std::endl;

  std::cout << "strArr: ";
  iter(strArr, 5, print);
  std::cout << std::endl;

  return 0;
}