/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hujeong <hujeong@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/22 21:13:54 by hujeong           #+#    #+#             */
/*   Updated: 2023/10/25 01:39:28 by hujeong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cstdlib>
#include <iostream>
#include <vector>

#include "Span.hpp"

int main() {
  Span sp = Span(5);
  sp.addNumber(6);
  sp.addNumber(3);
  sp.addNumber(17);
  sp.addNumber(9);
  sp.addNumber(11);
  std::cout << sp.shortestSpan() << std::endl;
  std::cout << sp.longestSpan() << std::endl;

  std::cout << "\n==========10000개 테스트============" << std::endl;
  Span sp2(10000);
  Span easySp(10000);
  std::vector<int> v(10000);

  srand(time(NULL));
  for (int i = 0; i < 10000; ++i) {
    v[i] = rand();
    sp2.addNumber(v[i]);
  }
  try {
    std::cout << sp2.shortestSpan() << std::endl;
    std::cout << sp2.longestSpan() << std::endl;
    sp2.addNumber(42);
  } catch (std::exception &e) {
    std::cout << e.what() << std::endl;
  }
  try {
    easySp.easyAddNumber<std::vector<int> >(v.begin(), v.end());
    std::cout << easySp.shortestSpan() << std::endl;
    std::cout << easySp.longestSpan() << std::endl;
    easySp.addNumber(42);
  } catch (std::exception &e) {
    std::cout << e.what() << std::endl;
  }
  return 0;
}