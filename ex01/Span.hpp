/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hujeong <hujeong@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 10:54:29 by hujeong           #+#    #+#             */
/*   Updated: 2023/10/23 22:23:08 by hujeong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPAN_HPP
#define SPAN_HPP

#include <set>

typedef std::set<int> set_t;

class Span {
 private:
  set_t s_;
  unsigned int size_;
  class OutOfRange : public std::exception {
   public:
    virtual const char *what() const throw() {
      return "Span의 저장공간이 가득 찼습니다.";
    }
  };
  class TooFewElements : public std::exception {
   public:
    virtual const char *what() const throw() {
      return "Span에 저장된 수가 2개 미만입니다.";
    }
  };
  class AlreadyElementExist : public std::exception {
   public:
    virtual const char *what() const throw() {
      return "Span에 이미 값이 존재합니다.";
    }
  };

 public:
  // Span();
  Span(unsigned int N);
  // Span(Span &other);
  // Span &operator=(Span &other);
  ~Span();
  void addNumber(int num);
  unsigned int shortestSpan();
  unsigned int longestSpan();
  template <typename T>
  void easyAddNumber(typename T::iterator begin, typename T::iterator end) {
    for (typename T::iterator it = begin; it != end; ++it) s_.insert(*it);
  }
};

#endif