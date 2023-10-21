/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   whatever.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hujeong <hujeong@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 09:49:31 by hujeong           #+#    #+#             */
/*   Updated: 2023/10/20 12:02:18 by hujeong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WHATEVER_HPP
#define WHATEVER_HPP

#include <cstring>

template <typename T>
T swap(T &a, T &b) {
  T tmp = a;
  a = b;
  b = tmp;
  return (a);
}

template <typename T>
T min(T &a, T &b) {
  return (a < b ? a : b);
}

template <>
const char *min<const char *>(const char *&a, const char *&b) {
  return (std::strlen(a) < std::strlen(b) ? a : b);
}

template <>
char *min<char *>(char *&a, char *&b) {
  return (std::strcmp(a, b) < 0 ? a : b);
}

template <typename T>
T max(T &a, T &b) {
  return (a > b ? a : b);
}

template <>
const char *max<const char *>(const char *&a, const char *&b) {
  return (std::strlen(a) > std::strlen(b) ? a : b);
}

template <>
char *max<char *>(char *&a, char *&b) {
  return (std::strcmp(a, b) > 0 ? a : b);
}

#endif