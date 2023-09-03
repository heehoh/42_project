/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hujeong <hujeong@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/02 20:16:26 by hujeong           #+#    #+#             */
/*   Updated: 2023/09/03 17:29:18 by hujeong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cure.hpp"

#include "ICharacter.hpp"

Cure::Cure(void) : AMateria("cure") {}
Cure::Cure(const Cure& other) : AMateria(other) {}
Cure::~Cure() {}

Cure& Cure::operator=(const Cure& other) {
  AMateria::operator=(other);
  return (*this);
}

AMateria* Cure::clone() const { return (new Cure(*this)); }

void Cure::use(ICharacter& target) {
  std::cout << "* heals " << target.getName() << "'s wounds *" << std::endl;
}