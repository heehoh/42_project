/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hujeong <hujeong@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/21 14:49:11 by hujeong           #+#    #+#             */
/*   Updated: 2023/10/25 01:45:00 by hujeong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EASYFIND_HPP
#define EASYFIND_HPP

#include <algorithm>

template <typename T>
typename T::iterator easyfind(T& container, int valueToFind) {
  typename T::iterator it =
      std::find(container.begin(), container.end(), valueToFind);
  if (it == container.end()) throw std::runtime_error("값을 찾을 수 없습니다.");
  return it;
}

#endif