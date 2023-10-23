/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hujeong <hujeong@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/22 21:13:54 by hujeong           #+#    #+#             */
/*   Updated: 2023/10/23 22:26:06 by hujeong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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

  std::vector<int> v;
  v.push_back(1);
  v.push_back(2);
  v.push_back(3);
  v.push_back(4);
  v.push_back(5);
  Span easySp = Span(5);
  easySp.easyAddNumber<std::vector<int> >(v.begin(), v.end());
  std::cout << easySp.shortestSpan() << std::endl;
  std::cout << easySp.longestSpan() << std::endl;
  return 0;
}