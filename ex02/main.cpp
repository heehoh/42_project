/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hujeong <hujeong@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/22 21:13:51 by hujeong           #+#    #+#             */
/*   Updated: 2023/10/25 01:58:53 by hujeong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <deque>
#include <iostream>
#include <list>
#include <vector>

#include "MutantStack.hpp"

int main() {
  MutantStack<int> mstack;
  mstack.push(5);
  mstack.push(17);
  std::cout << mstack.top() << std::endl;
  mstack.pop();
  std::cout << mstack.size() << std::endl;
  mstack.push(3);
  mstack.push(5);
  mstack.push(737);
  //[...]
  mstack.push(0);
  MutantStack<int>::iterator it = mstack.begin();
  MutantStack<int>::iterator ite = mstack.end();
  ++it;
  --it;
  while (it != ite) {
    std::cout << *it << std::endl;
    ++it;
  }
  std::stack<int> s(mstack);

  std::cout << "\n==========반복자 테스트============" << std::endl;

  std::cout << "뮤턴트 스택: ";
  MutantStack<int> s2;
  s2.push(5);
  s2.push(17);
  s2.push(3);
  s2.push(5);
  s2.push(737);
  s2.push(0);
  for (MutantStack<int>::iterator it = s2.begin(); it != s2.end(); ++it) {
    std::cout << *it << ' ';
  }
  std::cout << std::endl;

  std::cout << "벡터: ";
  std::vector<int> v;
  v.push_back(5);
  v.push_back(17);
  v.push_back(3);
  v.push_back(5);
  v.push_back(737);
  v.push_back(0);
  for (std::vector<int>::iterator it = v.begin(); it != v.end(); ++it) {
    std::cout << *it << ' ';
  }
  std::cout << std::endl;

  std::cout << "리스트: ";
  std::list<int> l;
  l.push_back(5);
  l.push_back(17);
  l.push_back(3);
  l.push_back(5);
  l.push_back(737);
  l.push_back(0);

  for (std::list<int>::iterator it = l.begin(); it != l.end(); ++it) {
    std::cout << *it << ' ';
  }
  std::cout << std::endl;

  std::cout << "덱: ";
  std::deque<int> d;
  d.push_back(5);
  d.push_back(17);
  d.push_back(3);
  d.push_back(5);
  d.push_back(737);
  d.push_back(0);

  for (std::deque<int>::iterator it = d.begin(); it != d.end(); ++it) {
    std::cout << *it << ' ';
  }
  std::cout << std::endl;

  std::cout << "\n==========역 반복자 테스트============" << std::endl;

  std::cout << "뮤턴트 스택: ";
  for (MutantStack<int>::reverse_iterator it = s2.rbegin(); it != s2.rend();
       ++it) {
    std::cout << *it << ' ';
  }
  std::cout << std::endl;

  std::cout << "벡터: ";
  for (std::vector<int>::reverse_iterator it = v.rbegin(); it != v.rend();
       ++it) {
    std::cout << *it << ' ';
  }
  std::cout << std::endl;

  std::cout << "리스트: ";
  for (std::list<int>::reverse_iterator it = l.rbegin(); it != l.rend(); ++it) {
    std::cout << *it << ' ';
  }
  std::cout << std::endl;

  std::cout << "덱: ";
  for (std::deque<int>::reverse_iterator it = d.rbegin(); it != d.rend();
       ++it) {
    std::cout << *it << ' ';
  }
  std::cout << std::endl;
  return 0;
}