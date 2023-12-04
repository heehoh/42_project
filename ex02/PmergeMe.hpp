/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hujeong <hujeong@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/26 20:35:04 by hujeong           #+#    #+#             */
/*   Updated: 2023/12/04 18:49:18 by hujeong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <algorithm>
#include <ctime>
#include <deque>
#include <iostream>
#include <sstream>
#include <vector>

typedef std::vector<int> vector;
typedef vector::iterator vIterator;
typedef std::deque<int> deque;
typedef deque::iterator dIterator;

class PmergeMe {
 private:
  vector vector_;
  deque deque_;
  clock_t vectorSortTime_;
  clock_t dequeSortTime_;

  int jacobsthalIndex_;
  int jacobsthalNum_[30];
  int numOfInsert_;

  PmergeMe();
  PmergeMe(const PmergeMe &);
  const PmergeMe &operator=(const PmergeMe &);
  void setJacobsthalNum();
  int getNextIndex(int index);

  void mergeInsertion(int numOfElement, int sizeOfElement);
  void comparePair(int num, int size);
  void setChains(int num, int size, vector &main, vector &sub);
  void insertion(int num, int size, vector &main, vector &sub);
  void binarySearchInsert(vector &mainChain, vector &subChain, size_t idx,
                          size_t size);

  void dequeMergeInsertion(int numOfElement, int sizeOfElement);
  void dequeComparePair(int num, int size);
  void setChains(int num, int size, deque &main, deque &sub);
  void insertion(int num, int size, deque &main, deque &sub);
  void binarySearchInsert(deque &mainChain, deque &subChain, size_t idx,
                          size_t size);

 public:
  PmergeMe(std::vector<std::string> &arguments);
  ~PmergeMe();
  void sortVector();
  void sortDeque();

  void printVector();
  void printDeque();

  void isSort();
  void isDequeSort();

  void printTime();
};

#endif
