/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hujeong <hujeong@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/20 12:54:00 by hujeong           #+#    #+#             */
/*   Updated: 2023/10/21 14:36:12 by hujeong          ###   ########.fr       */
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
Array<T>::Array() : arr_(NULL), size_(0) {}

template <typename T>
Array<T>::Array(unsigned int n) : arr_(n ? new T[n] : NULL), size_(n) {}

template <typename T>
Array<T>::Array(const Array &other)
    : arr_(other.size_ ? new T[other.size_] : NULL), size_(other.size_) {
  for (unsigned int i = 0; i < size_; i++) {
    arr_[i] = other.arr_[i];
  }
}

template <typename T>
Array<T> &Array<T>::operator=(const Array &other) {
  if (this == &other) {
    return *this;
  }
  if (size_ != 0) delete[] arr_;
  if (other.size_ == 0) {
    arr_ = NULL;
    size_ = 0;
    return *this;
  }
  arr_ = new T[other.size_];
  size_ = other.size_;
  for (unsigned int i = 0; i < size_; i++) {
    arr_[i] = other.arr_[i];
  }
  return *this;
}

template <typename T>
Array<T>::~Array() {
  if (size_ != 0) delete[] arr_;
}

template <typename T>
T &Array<T>::operator[](unsigned int i) {
  if (i >= size_ || i < 0) {
    throw OutOfBoundsException();
  }
  return arr_[i];
}

template <typename T>
unsigned int Array<T>::size() const {
  return size_;
}

template <typename T>
const char *Array<T>::OutOfBoundsException::what() const throw() {
  return "배열 범위를 벗어났습니다.";
}

#endif