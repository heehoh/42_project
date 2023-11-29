/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hujeong <hujeong@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/26 20:35:04 by hujeong           #+#    #+#             */
/*   Updated: 2023/11/29 17:21:32 by hujeong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <algorithm>
#include <deque>
#include <iostream>
#include <sstream>
#include <vector>

class PmergeMe {
 private:
  std::deque<int> deque_;
  std::vector<int> vector_;
  int jacobsthalNum_[30];
  PmergeMe();
  PmergeMe(const PmergeMe &);
  const PmergeMe &operator=(const PmergeMe &);
  void setJacobsthalNum();

 public:
  PmergeMe(std::vector<std::string> &arguments);
  ~PmergeMe();
  void recursive(int pairCount, int pairSize);
  void comparePairwise(int pairSize);
  // void insertion();
  void sortVector();
  void sortDeque();
  void printVector();
  void printDeque();
};

#endif