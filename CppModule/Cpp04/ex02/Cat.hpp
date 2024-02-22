/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hujeong <hujeong@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/02 14:31:23 by hujeong           #+#    #+#             */
/*   Updated: 2023/09/03 15:10:58 by hujeong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAT_HPP
#define CAT_HPP

#include "Animal.hpp"
#include "Brain.hpp"

class Cat : public Animal {
 public:
  Cat(void);
  Cat(const Cat& copy);
  virtual ~Cat(void);

  virtual Cat& operator=(const Animal& src);
  virtual Cat& operator=(const Cat& src);
  virtual void makeSound(void) const;
  void printIdeas(void) const;
  void setIdea(int index, std::string idea);

 private:
  Brain* brain;
};

#endif