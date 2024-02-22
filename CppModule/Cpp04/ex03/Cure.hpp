/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hujeong <hujeong@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/02 20:16:21 by hujeong           #+#    #+#             */
/*   Updated: 2023/09/03 16:34:03 by hujeong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CURE_HPP
#define CURE_HPP

#include "AMateria.hpp"

class Cure : public AMateria {
 private:
  Cure(const Cure& other);
  Cure& operator=(const Cure& other);

 public:
  Cure(void);

  virtual ~Cure();
  virtual AMateria* clone() const;
  virtual void use(ICharacter& target);
};

#endif