/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hujeong <hujeong@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/26 20:35:04 by hujeong           #+#    #+#             */
/*   Updated: 2023/12/04 01:55:18 by hujeong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <algorithm>
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
  int jacobsthalIndex_;
  int jacobsthalNum_[30];
  int numOfInsert_;

  PmergeMe();
  PmergeMe(const PmergeMe &);
  const PmergeMe &operator=(const PmergeMe &);
  void setJacobsthalNum();

  void binarySearchInsert(vector &mainChain, vector &subChain, size_t idx,
                          size_t size);

  // 재귀 단계에서 pair쌍을 만들고, pair를 mainChain, subChain 기준으로 나눠줌.
  void comparePair(int num, int size);
  // mainChain에 들어갈 subChain의 부분을 구해줌
  int getNextIndex(int index);
  // 만들어진 벡터를 기준으로 mainChain과 subChain을 만들고
  void setChains(int num, int size, vector &main, vector &sub);
  // subChain을 mainChain에 insertion
  void insertion(int num, int size, vector &main, vector &sub);

  void dequeComparePair(int num, int size);
  void dequeSetChains(int num, int size, deque &main, deque &sub);
  void dequeInsertion(int num, int size, deque &main, deque &sub);
  void dequeBinarySearchInsert(deque &mainChain, deque &subChain, size_t idx,
                               size_t size);



 public:
  PmergeMe(std::vector<std::string> &arguments);
  ~PmergeMe();
  void sortVector();
  void sortDeque();

  void printVector();
  void printDeque();
  
  void mergeInsertion(int numOfElement, int sizeOfElement);
  void dequeMergeInsertion(int numOfElement, int sizeOfElement);
  void isSort();
  void isDequeSort();
};

#endif

// size = mainChain.size();
// std::cout << "mainChain: ";
// for (int i = 0; i < size; ++i) std::cout << mainChain[i] << " ";
// std::cout << std::endl;

// size = subChain.size();
// std::cout << "subChain: ";
// for (int i = 0; i < size; ++i) std::cout << subChain[i] << " ";
// std::cout << std::endl;