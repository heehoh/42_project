/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hujeong <hujeong@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/31 15:09:46 by hujeong           #+#    #+#             */
/*   Updated: 2023/09/07 12:07:03 by hujeong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef POINT_HPP
#define POINT_HPP

#include "Fixed.hpp"

class Point {
 public:
  Point(void);
  Point(Point& point);
  Point(const float x, const float y);
  Point& operator=(const Point& point);

  ~Point(void);
  Fixed getX(void) const;
  Fixed getY(void) const;
  void setX(const float x);
  void setY(const float y);

 private:
  Fixed _x;
  Fixed _y;
};

#endif