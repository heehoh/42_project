/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hujeong <hujeong@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/26 20:35:01 by hujeong           #+#    #+#             */
/*   Updated: 2023/12/03 22:03:27 by hujeong          ###   ########.fr       */
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

int PmergeMe::getNextIndex(int index) {
  if (index == 0) return 1;
  if (index == 1) return 3;
  if (index - 1 == jacobsthalNum_[jacobsthalIndex_]) {
    ++jacobsthalIndex_;
    return jacobsthalNum_[jacobsthalIndex_ + 1];
  }
  return index - 1;
}

void PmergeMe::binarySearchInsert(vector &mainChain, vector &subChain,
                                  size_t idx, size_t size) {
  int left = 0;
  int right = idx + numOfInsert_;
  vIterator subIt = subChain.begin() + idx * size;
  vIterator mainIt = mainChain.begin();
  if (idx == 0) {
    mainChain.insert(mainIt, subIt, subIt + size);
    return;
  }

  while (left <= right) {
    int mid = left + (right - left) / 2;
    if (mainChain[left * size] < *subIt) {
      left = mid + 1;
    } else {
      right = mid - 1;
    }
  }

  mainChain.insert(mainIt + left * size, subIt, subIt + size);
  ++numOfInsert_;
}

void PmergeMe::setChains(int num, int size, vector &main, vector &sub) {
  vIterator it = vector_.begin();

  for (int i = 0; i < num; ++i) {
    if (i == num - 1 || i % 2 == 1)
      sub.insert(sub.end(), it + i * size, it + (i + 1) * size);
    else if (i % 2 == 0)
      main.insert(main.end(), it + i * size, it + (i + 1) * size);
  }
  // std::cout << "서브 체인: ";
  // for (size_t i = 0; i < sub.size(); ++i) std::cout << sub[i] << " ";
  // std::cout << std::endl;
}

void PmergeMe::insertion(int num, int size, vector &main, vector &sub) {
  int idx = 0;
  jacobsthalIndex_ = 0;
  numOfInsert_ = 0;
  int subChainNum = num / 2 + num % 2;
  setChains(num, size, main, sub);
  for (int i = 0; i < subChainNum; ++i) {
    idx = getNextIndex(idx);
    if (idx >= subChainNum) idx = subChainNum;
    binarySearchInsert(main, sub, idx - 1, size);
  }
  for (size_t i = 0; i < main.size(); ++i) {
    vector_[i] = main[i];
  }
}

void PmergeMe::mergeInsertion(int numOfElement, int sizeOfElement) {
  if (numOfElement == 1) return;
  vector mainChain;
  vector subChain;
  comparePair(numOfElement, sizeOfElement);
  mergeInsertion(numOfElement / 2, sizeOfElement * 2);
  insertion(numOfElement, sizeOfElement, mainChain, subChain);
  for (size_t i = 0; i < vector_.size(); ++i) {
    std::cout << vector_[i] << " ";
  }
  std::cout << std::endl;
}

void PmergeMe::sortVector() { mergeInsertion(vector_.size(), 1); }

void PmergeMe::printVector() {
  for (std::vector<int>::iterator it = vector_.begin(); it != vector_.end();
       ++it) {
    std::cout << *it << " ";
  }
  std::cout << std::endl;
}