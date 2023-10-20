/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hujeong <hujeong@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 09:49:20 by hujeong           #+#    #+#             */
/*   Updated: 2023/10/20 12:04:09 by hujeong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

#include "whatever.hpp"

int main() {
  int a = 2;
  int b = 3;

  std::cout << "----- int 템플릿 함수 -----" << std::endl;
  std::cout << "a: " << a << ", b: " << b << std::endl;
  std::cout << "swap 함수 호출" << std::endl;
  swap(a, b);
  std::cout << "a: " << a << ", b: " << b << std::endl;

  std::cout << "\n----- int min, max 함수는 크기를 비교합니다. -----"
            << std::endl;
  std::cout << "min(a, b): " << min(a, b) << std::endl;
  std::cout << "max(a, b): " << max(a, b) << std::endl;

  const char *c = "abcde";
  const char *d = "f";
  char *e = new char[7];
  char *f = new char[7];
  std::strcpy(e, c);
  std::strcpy(f, d);

  std::cout << "\n----- const char * 템플릿 함수 -----" << std::endl;
  std::cout << "c: " << c << ", d: " << d << std::endl;
  std::cout << "swap 함수 호출" << std::endl;
  swap(c, d);
  std::cout << "c: " << c << ", d: " << d << std::endl;
  std::cout
      << "\n---- const char * min, max 함수는 문자열 길이를 비교합니다! ----"
      << std::endl;
  std::cout << "min(c, d): " << min(c, d) << std::endl;
  std::cout << "max(c, d): " << max(c, d) << std::endl;

  std::cout << "\n----- char * 템플릿 함수 -----" << std::endl;
  std::cout << "e: " << e << ", f: " << f << std::endl;
  std::cout << "swap 함수 호출" << std::endl;
  swap(e, f);
  std::cout << "e: " << e << ", f: " << f << std::endl;
  std::cout << "\n---- char * min, max 함수는 사전편찬 순서를 비교합니다! ----"
            << std::endl;
  std::cout << "min(e, f): " << min(e, f) << std::endl;
  std::cout << "max(e, f): " << max(e, f) << std::endl;

  return 0;
}