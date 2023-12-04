/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hujeong <hujeong@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/26 20:35:01 by hujeong           #+#    #+#             */
/*   Updated: 2023/12/04 18:50:18 by hujeong          ###   ########.fr       */
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
    if (i == 0 && (str[0] == '+' || str[0] == '-')) continue;
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
    if (value <= 0) throw std::runtime_error("Error: 인자는 양수여야 합니다.");
    vector_.push_back(value);
    deque_.push_back(value);
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
    if (mainChain[mid * size] < *subIt) {
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
}

void PmergeMe::sortVector() {
  clock_t start = clock();
  mergeInsertion(vector_.size(), 1);
  vectorSortTime_ = clock() - start;
}

void PmergeMe::printVector() {
  for (vIterator it = vector_.begin(); it != vector_.end(); ++it)
    std::cout << *it << " ";
  std::cout << std::endl;
}

void PmergeMe::isSort() {
  for (size_t i = 0; i < vector_.size() - 1; ++i) {
    if (vector_[i] > vector_[i + 1]) {
      std::cout << "정렬되지 않음 !!" << std::endl;
      return;
    }
  }
  std::cout << "정렬 완료 !" << std::endl;
}

void PmergeMe::dequeComparePair(int num, int size) {
  dIterator it = deque_.begin();

  for (int i = 0; i < num - 1; i += 2) {
    dIterator first = it + i * size;
    dIterator second = it + (i + 1) * size;
    if (*first < *second) std::swap_ranges(first, second, second);
  }
}

void PmergeMe::setChains(int num, int size, deque &main, deque &sub) {
  dIterator it = deque_.begin();

  for (int i = 0; i < num; ++i) {
    if (i == num - 1 || i % 2 == 1)
      sub.insert(sub.end(), it + i * size, it + (i + 1) * size);
    else if (i % 2 == 0)
      main.insert(main.end(), it + i * size, it + (i + 1) * size);
  }
}

void PmergeMe::binarySearchInsert(deque &mainChain, deque &subChain, size_t idx,
                                  size_t size) {
  int left = 0;
  int right = idx + numOfInsert_;
  dIterator subIt = subChain.begin() + idx * size;
  dIterator mainIt = mainChain.begin();
  if (idx == 0) {
    mainChain.insert(mainIt, subIt, subIt + size);
    return;
  }

  while (left <= right) {
    int mid = left + (right - left) / 2;
    if (mainChain[mid * size] < *subIt) {
      left = mid + 1;
    } else {
      right = mid - 1;
    }
  }

  mainChain.insert(mainIt + left * size, subIt, subIt + size);
  ++numOfInsert_;
}

void PmergeMe::insertion(int num, int size, deque &main, deque &sub) {
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
    deque_[i] = main[i];
  }
}

void PmergeMe::dequeMergeInsertion(int numOfElement, int sizeOfElement) {
  if (numOfElement == 1) return;
  deque mainChain;
  deque subChain;
  dequeComparePair(numOfElement, sizeOfElement);
  dequeMergeInsertion(numOfElement / 2, sizeOfElement * 2);
  insertion(numOfElement, sizeOfElement, mainChain, subChain);
}

void PmergeMe::sortDeque() {
  clock_t start = clock();
  dequeMergeInsertion(deque_.size(), 1);
  dequeSortTime_ = clock() - start;
}

void PmergeMe::printDeque() {
  for (dIterator it = deque_.begin(); it != deque_.end(); ++it)
    std::cout << *it << " ";
  std::cout << std::endl;
}

void PmergeMe::isDequeSort() {
  for (size_t i = 0; i < deque_.size() - 1; ++i) {
    if (deque_[i] > deque_[i + 1]) {
      std::cout << "정렬되지 않음 !!" << std::endl;
      return;
    }
  }
  std::cout << "정렬 완료 !" << std::endl;
}

void PmergeMe::printTime() {
  std::cout << "벡터 정렬 시간: " << vectorSortTime_ << "ms" << std::endl;
  std::cout << "덱 정렬 시간: " << dequeSortTime_ << "ms" << std::endl;
}