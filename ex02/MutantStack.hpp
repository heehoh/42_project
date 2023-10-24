/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hujeong <hujeong@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/24 20:03:29 by hujeong           #+#    #+#             */
/*   Updated: 2023/10/25 01:23:17 by hujeong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MUTANTSTACK_HPP
#define MUTANTSTACK_HPP

#include <stack>

template <typename T>
class MutantStack : public std::stack<T> {
 public:
  typedef typename std::stack<T>::container_type::iterator iterator;
  typedef
      typename std::stack<T>::container_type::reverse_iterator reverse_iterator;

  MutantStack<T>() : std::stack<T>() {}
  MutantStack<T>(const MutantStack& other) : std::stack<T>(other) {}
  MutantStack<T>& operator=(const MutantStack& other) {
    if (this != &other) {
      std::stack<T>::operator=(other);
    }
    return *this;
  }
  ~MutantStack() {}

  iterator begin() { return this->c.begin(); }
  iterator end() { return this->c.end(); }

  reverse_iterator rbegin() { return this->c.rbegin(); }
  reverse_iterator rend() { return this->c.rend(); }
};

#endif
