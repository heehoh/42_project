/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hujeong <hujeong@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 10:54:37 by hujeong           #+#    #+#             */
/*   Updated: 2023/10/23 22:23:01 by hujeong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

// Span::Span() : size_(0) {}
Span::Span(unsigned int N) : size_(N) {}
void Span::addNumber(int num) {
  if (s_.size() == size_) throw OutOfRange();
  size_t size = s_.size();
  s_.insert(num);
  if (size == s_.size()) throw AlreadyElementExist();
}
// Span::Span(Span &other) : size_(other.size_) { s_ = other.s_; }
// Span &Span::operator=(Span &other) {
//   s_ = other.s_;
//   size_ = other.size_;
//   return *this;
// }
Span::~Span() {}

unsigned int Span::shortestSpan() {
  if (s_.size() < 2) throw TooFewElements();
  set_t::iterator it = s_.begin();
  ++it;
  int min = *it - *s_.begin();
  for (set_t::iterator itr = s_.begin(); itr != s_.end(); ++itr) {
    set_t::iterator itr2 = itr;
    ++itr2;
    if (itr2 == s_.end()) break;
    if (*itr2 - *itr < min) min = *itr2 - *itr;
  }
  return min;
}

unsigned int Span::longestSpan() {
  if (s_.size() < 2) throw TooFewElements();
  return *s_.rbegin() - *s_.begin();
}
