/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hujeong <hujeong@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/26 20:35:01 by hujeong           #+#    #+#             */
/*   Updated: 2023/11/29 14:44:09 by hujeong          ###   ########.fr       */
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

PmergeMe::PmergeMe(std::vector<std::string> &arguments) {
  size_t size = arguments.size();
  int value;
  for (size_t i = 0; i < size; ++i) {
    numberCheck(arguments[i]);
    std::stringstream ss;
    ss << arguments[i];
    ss >> value;
    vector_.push_back(value);
    deque_.push_back(value);
  }
  std::fill(jacobsthalNum_, jacobsthalNum_ + 30, 0);
}

void PmergeMe::comparePairwise(int pairCount, int pairElementSize) {
  std::vector<int>::iterator it = vector_.begin();
  int size = vector_.size();

  for (int i = 0; i < size; i += pairElementSize * 2) {
    if (*(it + i) < *(it + i + pairElementSize))
      std::swap_ranges(it + i, it + i + pairElementSize,
                       it + i + pairElementSize);
  }
}

void PmergeMe::recursive(int pairCount, int pairElementSize) {
  // compare pairwise
  // recursive
  // insertion
}

void PmergeMe::sortDeque() {}

void PmergeMe::printVector() {
  for (std::vector<int>::iterator it = vector_.begin(); it != vector_.end();
       ++it) {
    std::cout << *it << " ";
  }
  std::cout << std::endl;
}

void PmergeMe::printDeque() {
  for (std::deque<int>::iterator it = deque_.begin(); it != deque_.end();
       ++it) {
    std::cout << *it << " ";
  }
  std::cout << std::endl;
}
