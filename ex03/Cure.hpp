/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hujeong <hujeong@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/02 20:16:21 by hujeong           #+#    #+#             */
/*   Updated: 2023/09/02 20:59:56 by hujeong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CURE_HPP
#define CURE_HPP

#include "AMateria.hpp"

class Cure : public AMateria {
 public:
  Cure(void);
  Cure(const Cure& other);
  virtual ~Cure();
  Cure& operator=(const Cure& other);

  virtual AMateria* clone() const;
  virtual void use(ICharacter& target);
};

#endif