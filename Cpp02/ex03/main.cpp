/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hujeong <hujeong@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/31 15:09:57 by hujeong           #+#    #+#             */
/*   Updated: 2023/09/01 15:06:17 by hujeong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

bool bsp(Point &a, Point &b, Point &c, Point &point);

int main() {
  float x, y;
  Point a[4];
  bool result;
  std::cout << "========= bsp 시작 ==========" << std::endl;
  for (int i = 0; i < 4; i++) {
    if (i < 3)
      std::cout << "삼각형 " << i + 1 << "번째 꼭짓점을 입력하세요: ";
    else
      std::cout << "점을 입력하세요: ";
    std::cin >> x >> y;
    a[i].setX(x);
    a[i].setY(y);
  }
  result = bsp(a[0], a[1], a[2], a[3]);
  std::cout << "========= bsp 결과 ==========" << std::endl;
  if (result)
    std::cout << "점은 삼각형 안에 있습니다." << std::endl;
  else
    std::cout << "점은 삼각형 안에 없습니다." << std::endl;
  std::cout << "========= bsp 끝 ==========" << std::endl;
}