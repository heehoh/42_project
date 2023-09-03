/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hujeong <hujeong@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/02 14:37:00 by hujeong           #+#    #+#             */
/*   Updated: 2023/09/03 13:21:21 by hujeong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOG_HPP
#define DOG_HPP

#include "Animal.hpp"
#include "Brain.hpp"

class Dog : public Animal {
 public:
  Dog(void);
  Dog(const Dog& copy);
  virtual ~Dog(void);

  virtual Dog& operator=(const Animal& src);  // Animal 대입 연산자 호출
  virtual Dog& operator=(const Dog& src);
  virtual void makeSound(void) const;

  void printIdeas(void) const;
  void setIdea(int index, std::string idea);

 private:
  Brain* brain;
};

#endif