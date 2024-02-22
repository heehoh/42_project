/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hujeong <hujeong@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/15 14:51:54 by hujeong           #+#    #+#             */
/*   Updated: 2023/10/18 03:54:18 by hujeong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// reinterpret_cast 사용해보기

#include <iostream>

#include "Serializer.hpp"

int main() {
  Data data;
  data.i = 42;


  std::cout << "----데이터 직렬화 전----\ndata의 주소: "  << &data <<  "\ni의 값: " << data.i << std::endl;

  std::cout << "\n-----데이터 직렬화-----" << std::endl;
  uintptr_t raw = Serializer::serialize(&data);
  std::cout << std::hex << std::showbase << "data 직렬화한 값: " << raw << std::endl;
  std::cout << "\n-----데이터 역직렬화 후-----" << std::endl;
  Data* ptr = Serializer::deserialize(raw);

  std::cout << std::dec << "역직렬화시킨 data의 주소: " <<  ptr << "\ni의 값: " << ptr->i << std::endl;

  return 0;
}