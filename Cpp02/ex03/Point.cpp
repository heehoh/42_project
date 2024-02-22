/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hujeong <hujeong@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/31 15:09:36 by hujeong           #+#    #+#             */
/*   Updated: 2023/09/07 12:01:18 by hujeong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

Point::Point(void) : _x(0), _y(0) {}
Point::Point(Point& point) : _x(point._x), _y(point._y) {}
Point::Point(const float x, const float y) : _x(x), _y(y) {}
Point& Point::operator=(const Point& point) {
  _x = point._x;
  _y = point._y;
  return *this;
}
Point::~Point(void) {}

Fixed Point::getX(void) const { return _x; }
Fixed Point::getY(void) const { return _y; }
void Point::setX(const float x) { _x = x; }
void Point::setY(const float y) { _y = y; }