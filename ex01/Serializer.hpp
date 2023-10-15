/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hujeong <hujeong@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/15 14:52:40 by hujeong           #+#    #+#             */
/*   Updated: 2023/10/15 15:04:15 by hujeong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SERIALIZER_HPP
#define SERIALIZER_HPP

#include <cstdint>

struct Data;

class Serializer {
 private:
  Serializer();
  Serializer(const Serializer&);
  Serializer& operator=(const Serializer&);
  ~Serializer();

 public:
  static uintptr_t serialize(Data* ptr);
  static Data* deserailize(uintptr_t raw);
};

#endif