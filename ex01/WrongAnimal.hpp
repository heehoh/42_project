/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hujeong <hujeong@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/02 16:36:06 by hujeong           #+#    #+#             */
/*   Updated: 2023/09/02 16:41:16 by hujeong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WRONGANIMAL_HPP
#define WRONGANIMAL_HPP

#include <iostream>

class WrongAnimal {
 public:
  WrongAnimal(void);
  WrongAnimal(const WrongAnimal& copy);
  virtual ~WrongAnimal(void);

  virtual WrongAnimal& operator=(const WrongAnimal& src);
  std::string getType(void) const;
  void makeSound(void) const;

 protected:
  std::string type;
};

#endif