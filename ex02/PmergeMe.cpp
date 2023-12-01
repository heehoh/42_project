/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hujeong <hujeong@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/26 20:35:01 by hujeong           #+#    #+#             */
/*   Updated: 2023/12/01 22:17:16 by hujeong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

PmergeMe::PmergeMe() {}
PmergeMe::PmergeMe(const PmergeMe &) {}
const PmergeMe &PmergeMe::operator=(const PmergeMe &) { return *this; }
PmergeMe::~PmergeMe() {}

void numberCheck(const std::string &str) {
  size_t len = str.length();
  for (size_t i = 0; i < len; ++i) {
    if (i == 0 && str[0] == '+') continue;
    if (str[i] < '0' || str[i] > '9')
      throw std::runtime_error("Error: 인자가 숫자가 아닙니다.");
  }
}

void PmergeMe::setJacobsthalNum() {
  jacobsthalNum_[0] = 1;
  jacobsthalNum_[1] = 3;

  for (int i = 2; i < 30; ++i)
    jacobsthalNum_[i] = jacobsthalNum_[i - 1] + 2 * jacobsthalNum_[i - 2];
}

PmergeMe::PmergeMe(std::vector<std::string> &arguments) {
  size_t size = arguments.size();
  int value;
  for (size_t i = 0; i < size; ++i) {
    numberCheck(arguments[i]);
    std::stringstream ss;
    ss << arguments[i];
    ss >> value;
    vector_.push_back(value);
  }
  setJacobsthalNum();
}

void PmergeMe::comparePair(int num, int size) {
  vIterator it = vector_.begin();

  for (int i = 0; i < num - 1; i += 2) {
    vIterator first = it + i * size;
    vIterator second = it + (i + 1) * size;
    if (*first < *second) std::swap_ranges(first, second, second);
  }
}

// void PmergeMe::insertion(int num, int size) {
//   vector mainChain;
//   vector subChain;

// }

void PmergeMe::mergeInsertion(int numOfElement, int sizeOfElement) {
  if (numOfElement > 1) {
    comparePair(numOfElement, sizeOfElement);
    mergeInsertion(numOfElement / 2, sizeOfElement * 2);
    insertion(numOfElement, sizeOfElement);
  }
}

void PmergeMe::sortVector() { mergeInsertion(vector_.size(), 1); }

void PmergeMe::printVector() {
  for (std::vector<int>::iterator it = vector_.begin(); it != vector_.end();
       ++it) {
    std::cout << *it << " ";
  }
  std::cout << std::endl;
}