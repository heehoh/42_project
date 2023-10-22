/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hujeong <hujeong@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/21 14:48:59 by hujeong           #+#    #+#             */
/*   Updated: 2023/10/22 21:21:12 by hujeong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <deque>
#include <iostream>
#include <list>
#include <vector>

#include "easyfind.hpp"

int main() {
  std::vector<int> v;
  std::deque<int> d;
  std::list<int> l;
  v.push_back(0);
  v.push_back(1);
  v.push_back(2);
  v.push_back(3);
  v.push_back(4);
  d.push_back(0);
  d.push_back(1);
  d.push_back(2);
  l.push_back(0);
  l.push_back(1);
  l.push_back(2);
  try {
    std::vector<int>::iterator i = easyfind(v, 10);
    std::cout << *i << std::endl;
  } catch (std::exception &e) {
    std::cout << "벡터에서 " << e.what() << std::endl;
  }
  for (std::vector<int>::iterator c = v.begin(); c != v.end(); ++c)
    std::cout << *c << " ";
  std::cout << std::endl;
}