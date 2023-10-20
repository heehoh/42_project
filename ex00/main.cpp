/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hujeong <hujeong@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 09:49:20 by hujeong           #+#    #+#             */
/*   Updated: 2023/10/19 07:41:45 by hujeong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

#include "whatever.hpp"

int main() {
  int a = 2;
  int b = 3;

  std::cout << "a: " << a << ", b: " << b << std::endl;
  std::cout << "swap(a, b): " << std::endl;
  swap(a, b);
  std::cout << "a: " << a << ", b: " << b << std::endl;
  std::cout << "min(a, b): " << min(a, b) << std::endl;
  std::cout << "max(a, b): " << max(a, b) << std::endl;

  const char *c = "chaine1";
  const char *d = "chaine2";
  char *e = new char[7];
  char *f = new char[7];
  std::strcpy(e, c);
  std::strcpy(f, d);

  std::cout << "c: " << c << ", d: " << d << std::endl;
  std::cout << "swap(c, d): " << std::endl;
  swap(c, d);
  std::cout << "c: " << c << ", d: " << d << std::endl;
  std::cout << "min(c, d): " << min(c, d) << std::endl;
  std::cout << "max(c, d): " << max(c, d) << std::endl;


  std::cout << "e: " << e << ", f: " << f << std::endl;
  std::cout << "swap(e, f): " << std::endl;
  swap(e, f);
  std::cout << "e: " << e << ", f: " << f << std::endl;
  std::cout << "min(e, f): " << min(e, f) << std::endl;
  std::cout << "max(e, f): " << max(e, f) << std::endl;
  
  return 0;
}