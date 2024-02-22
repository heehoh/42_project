/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hujeong <hujeong@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/21 14:48:59 by hujeong           #+#    #+#             */
/*   Updated: 2023/10/25 01:48:34 by hujeong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <deque>
#include <iostream>
#include <list>
#include <set>
#include <vector>

#include "easyfind.hpp"

int main() {
  std::vector<int> v;
  std::deque<int> d;
  std::list<int> l;
  std::set<int> s;
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
  s.insert(0);
  s.insert(1);
  s.insert(2);
  try {
    std::vector<int>::iterator i = easyfind(v, 0);
    std::cout << "vector: " << *i << std::endl;
    std::deque<int>::iterator j = easyfind(d, 1);
    std::cout << "deque: " << *j << std::endl;
    std::list<int>::iterator k = easyfind(l, 2);
    std::cout << "list: " << *k << std::endl;
    std::set<int>::iterator m = easyfind(s, 3);
    std::cout << "set: " << *m << std::endl;
  } catch (std::exception &e) {
    std::cout << "set에서 " << e.what() << std::endl;
  }
  for (std::vector<int>::iterator c = v.begin(); c != v.end(); ++c)
    std::cout << *c << " ";
  std::cout << std::endl;
}