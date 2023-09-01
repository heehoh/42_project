/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hujeong <hujeong@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/31 15:09:46 by hujeong           #+#    #+#             */
/*   Updated: 2023/08/31 22:07:35 by hujeong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef POINT_HPP
#define POINT_HPP

#include "Fixed.hpp"

class Point {
 public:
  Point(void);
  Point( Point& point);
  Point(const float x, const float y);
  Point& operator=( Point& point);

  ~Point(void);
  Fixed& getX(void);
  Fixed& getY(void);
  void setX(const float x);
  void setY(const float y);

 private:
  Fixed x;
  Fixed y;
};

#endif