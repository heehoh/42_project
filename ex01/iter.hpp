/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hujeong <hujeong@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/19 07:51:21 by hujeong           #+#    #+#             */
/*   Updated: 2023/10/21 22:56:56 by hujeong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITER_HPP
#define ITER_HPP

template <typename T>
void iter(T *arr, int len, void (*f)(T const &)) {
  for (int i = 0; i < len; i++) f(arr[i]);
}

template <typename T>
void iter(T *arr, int len, void (*f)(T &)) {
  for (int i = 0; i < len; ++i) f(arr[i]);
}

#endif