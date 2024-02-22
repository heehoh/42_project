/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hujeong <hujeong@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/20 12:54:00 by hujeong           #+#    #+#             */
/*   Updated: 2023/10/21 22:43:18 by hujeong          ###   ########.fr       */
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
  Array() : arr_(NULL), size_(0) {}
  Array(unsigned int n) : arr_(n ? new T[n] : NULL), size_(n) {}
  Array(const Array &other)
      : arr_(other.size_ ? new T[other.size_] : NULL), size_(other.size_) {
    for (unsigned int i = 0; i < size_; i++) {
      arr_[i] = other.arr_[i];
    }
  }
  Array &operator=(const Array &other) {
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
  ~Array() {
    if (size_ != 0) delete[] arr_;
  }
  class OutOfBoundsException : public std::exception {
   public:
    virtual const char *what() const throw() {
      return "배열 범위를 벗어났습니다.";
    }
  };

  T &operator[](unsigned int i) {
    if (i >= size_ || i < 0) {
      throw OutOfBoundsException();
    }
    return arr_[i];
  }
  unsigned int size() const { return size_; }
};

#endif