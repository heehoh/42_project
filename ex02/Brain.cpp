/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hujeong <hujeong@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/02 17:00:51 by hujeong           #+#    #+#             */
/*   Updated: 2023/09/02 17:54:36 by hujeong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.hpp"

Brain::Brain(void) {
  std::cout << "Brain 기본 생성자 호출" << std::endl;
  for (int i = 0; i < 100; i++) {
    ideas[i] = "";
  }
}

Brain::Brain(const Brain& copy) {
  std::cout << "Brain 복사 생성자 호출" << std::endl;
  for (int i = 0; i < 100; i++) {
    ideas[i] = copy.getIdea(i);
  }
}

Brain::~Brain(void) { std::cout << "Brain 소멸자 호출" << std::endl; }

Brain& Brain::operator=(const Brain& src) {
  std::cout << "Brain 대입 연산자 호출" << std::endl;
  for (int i = 0; i < 100; i++) {
    ideas[i] = src.getIdea(i);
  }
  return *this;
}

std::string Brain::getIdea(int index) const { return ideas[index]; }
void Brain::setIdea(int index, std::string idea) { ideas[index] = idea; }