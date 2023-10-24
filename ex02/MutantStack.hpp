/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hujeong <hujeong@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/24 20:03:29 by hujeong           #+#    #+#             */
/*   Updated: 2023/10/24 23:21:23 by hujeong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MUTANTSTACK_HPP
#define MUTANTSTACK_HPP

#include <stack>

template <typename T>
class MutantStack : public std::stack<T> {
 public:
  typedef typename std::stack<T>::iterator iterator;
  MutantStack() : stack() {}
  MutantStack(const MutantStack& other)
      : stack(dynamic_cast<const stack&>(other)) {}
  MutantStack& operator=(const MutantStack& other) {
    c = other.c;
    return *this;
  }
  ~MutantStack() {}

  iterator begin() { return this->c.begin(); }
  iterator end() { return this->c.end(); }

  iterator rbegin() { return this->c.rbegin(); }
  iterator rend() { return this->c.rend(); }
};

#endif