/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hujeong <hujeong@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/02 17:00:51 by hujeong           #+#    #+#             */
/*   Updated: 2023/09/03 12:33:25 by hujeong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.hpp"

Brain::Brain(void) {
  std::cout << "Brain 기본 생성자 호출" << std::endl;
  for (int i = 0; i < 100; i++) {
    this->ideas[i] = "";
  }
}

Brain::Brain(const Brain& copy) {
  std::cout << "Brain 복사 생성자 호출" << std::endl;
  for (int i = 0; i < 100; i++) {
    this->ideas[i] = copy.ideas[i];
  }
}

Brain::~Brain(void) { std::cout << "Brain 소멸자 호출" << std::endl; }

Brain& Brain::operator=(const Brain& src) {
  std::cout << "Brain 대입 연산자 호출" << std::endl;
  for (int i = 0; i < 100; i++) {
    this->ideas[i] = src.ideas[i];
  }
  return *this;
}

void Brain::printIdeas(void) const {
  for (int i = 0; i < 100; i++) {
    if (this->ideas[i] != "") std::cout << this->ideas[i] << std::endl;
  }
}

void Brain::setIdea(int index, std::string idea) { this->ideas[index] = idea; }