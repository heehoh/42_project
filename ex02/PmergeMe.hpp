/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hujeong <hujeong@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/26 20:35:04 by hujeong           #+#    #+#             */
/*   Updated: 2023/12/01 22:15:34 by hujeong          ###   ########.fr       */
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

class PmergeMe {
 private:
  vector vector_;
  // int jacobsthalIndex_;
  int jacobsthalNum_[30];
  PmergeMe();
  PmergeMe(const PmergeMe &);
  const PmergeMe &operator=(const PmergeMe &);
  void setJacobsthalNum();

  // 재귀 단계에서 pair쌍을 만들고, pair를 mainChain, subChain 기준으로 나눠줌.
  void comparePair(int num, int size);

  // 만들어진 벡터를 기준으로 mainChain과 subChain을 만들고
  // subChain을 mainChain에 insertion
  void insertion(int num, int size);

 public:
  PmergeMe(std::vector<std::string> &arguments);
  ~PmergeMe();
  void sortVector();
  void printVector();
  void mergeInsertion(int numOfElement, int sizeOfElement);
};

#endif