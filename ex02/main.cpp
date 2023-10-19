/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hujeong <hujeong@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/15 15:12:42 by hujeong           #+#    #+#             */
/*   Updated: 2023/10/18 03:57:48 by hujeong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cstdlib>
#include <iostream>

#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

Base* generate() {
  srand(time(NULL));
  int i = rand() % 3;
  if (i == 0) {
    std::cout << "A 생성" << std::endl;
    return new A();
  } else if (i == 1) {
    std::cout << "B 생성" << std::endl;
    return new B();
  } else {
    std::cout << "C 생성" << std::endl;
    return new C();
  }
}

void identify(Base* p) {
  std::cout << "포인터 다운캐스팅: ";
  if (dynamic_cast<A*>(p)) {
    std::cout << "A" << std::endl;
  } else if (dynamic_cast<B*>(p)) {
    std::cout << "B" << std::endl;
  } else if (dynamic_cast<C*>(p)) {
    std::cout << "C" << std::endl;
  }
}

void identify(Base& p) {
  std::cout << "참조 다운캐스팅: ";
  try {
    (void)dynamic_cast<A&>(p);
    std::cout << "A" << std::endl;
  } catch (std::exception&) {
  }
  try {
    (void)dynamic_cast<B&>(p);
    std::cout << "B" << std::endl;
  } catch (std::exception&) {
  }
  try {
    (void)dynamic_cast<C&>(p);
    std::cout << "C" << std::endl;
  } catch (std::exception&) {
  }
}

int main() {
  Base* base = generate();
  identify(base);
  identify(*base);
  delete base;
  return 0;
}