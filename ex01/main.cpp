/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hujeong <hujeong@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/15 14:51:54 by hujeong           #+#    #+#             */
/*   Updated: 2023/10/18 03:21:45 by hujeong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// reinterpret_cast 사용해보기

#include <iostream>

#include "Serializer.hpp"

int main() {
  Data data;
  data.i = 42;

  std::cout << "형변환 전 i: " << data.i << std::endl;

  uintptr_t raw = Serializer::serialize(&data);
  Data* ptr = Serializer::deserialize(raw);

  std::cout << "형변환 후 i: " << ptr->i << std::endl;

  return 0;
}