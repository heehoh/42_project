/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hujeong <hujeong@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/31 15:09:36 by hujeong           #+#    #+#             */
/*   Updated: 2023/08/31 22:07:35 by hujeong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

Point::Point(void) : x(0), y(0) {}
Point::Point(Point& point) {
  x = point.getX();
  y = point.getY();
}
Point::Point(const float x, const float y) : x(x), y(y) {}
Point& Point::operator=(Point& point) {
  x = point.getX();
  y = point.getY();
  return *this;
}
Point::~Point(void) {}

Fixed& Point::getX(void) { return x; }
Fixed& Point::getY(void) { return y; }

void Point::setX(const float x) { this->x = x; }
void Point::setY(const float y) { this->y = y; }