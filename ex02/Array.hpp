/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hujeong <hujeong@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/20 12:54:00 by hujeong           #+#    #+#             */
/*   Updated: 2023/10/20 13:46:04 by hujeong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_HPP
#define ARRAY_HPP

template <typename T>
class Array {
 private:
  T *arr_;
  unsigned int size_;

 public:
  Array();
  Array(unsigned int n);
  Array(const Array &other);
  Array &operator=(const Array &other);
  ~Array();

  T &operator[](unsigned int i);
  unsigned int size() const;

  class OutOfBoundsException : public std::exception {
   public:
    virtual const char *what() const throw();
  };
};

template <typename T>
Array<T>::Array() : arr_(new T()), size_(0) {}

template <typename T>
Array<T>::Array(unsigned int n) : arr_(new T[]), _size(n) {}

template <typename T>

#endif