/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hujeong <hujeong@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/02 14:35:33 by hujeong           #+#    #+#             */
/*   Updated: 2023/09/02 18:00:52 by hujeong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANIMAL_HPP
#define ANIMAL_HPP

#include <iostream>

class Animal {
 public:
  Animal(void);
  Animal(const Animal& copy);
  virtual ~Animal(void);

  virtual Animal& operator=(const Animal& src) = 0;
  std::string getType(void) const;
  virtual void makeSound(void) const = 0;

 protected:
  std::string type;
};

#endif