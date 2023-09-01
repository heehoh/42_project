/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsp.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hujeong <hujeong@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/31 15:09:09 by hujeong           #+#    #+#             */
/*   Updated: 2023/09/01 15:07:14 by hujeong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

int crossProduct(Point &a, Point &b, Point &c) {
  Fixed vec1_x, vec1_y, vec2_x, vec2_y;
  vec1_x = b.getX() - a.getX();
  vec1_y = b.getY() - a.getY();
  vec2_x = c.getX() - a.getX();
  vec2_y = c.getY() - a.getY();
  return (vec1_x * vec2_y - vec1_y * vec2_x).getRawBits();
}

bool bsp(Point &a, Point &b, Point &c, Point &point) {
  if (crossProduct(a, b, c) * crossProduct(a, b, point) <= 0) return false;
  if (crossProduct(b, c, a) * crossProduct(b, c, point) <= 0) return false;
  if (crossProduct(c, a, b) * crossProduct(c, a, point) <= 0) return false;
  return true;
}
