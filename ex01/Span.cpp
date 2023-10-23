/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hujeong <hujeong@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 10:54:37 by hujeong           #+#    #+#             */
/*   Updated: 2023/10/24 00:55:27 by hujeong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

Span::Span() : size_(0) {}
Span::Span(unsigned int N) : size_(N) {}
Span::Span(const Span &other) : size_(other.size_) { v_ = other.v_; }

Span &Span::operator=(const Span &other) {
  if (this == &other) return *this;
  v_ = other.v_;
  size_ = other.size_;
  return *this;
}
Span::~Span() {}

void Span::addNumber(int num) {
  if (v_.size() == size_) throw OutOfRange();
  v_.push_back(num);
}

unsigned int Span::shortestSpan() {
  if (v_.size() < 2) throw TooFewElements();
  int min = INT_MAX;
  std::sort(v_.begin(), v_.end());
  for (vector_t::iterator it = v_.begin(); it != v_.end() - 1; ++it) 
    if (*(it + 1) - *it < min) min = *(it + 1) - *it;
  return min;
}

unsigned int Span::longestSpan() {
  if (v_.size() < 2) throw TooFewElements();
  return *std::max_element(v_.begin(), v_.end()) -
         *std::min_element(v_.begin(), v_.end());
}
