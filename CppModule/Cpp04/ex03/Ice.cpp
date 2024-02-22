/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hujeong <hujeong@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/02 20:16:10 by hujeong           #+#    #+#             */
/*   Updated: 2023/09/03 17:29:10 by hujeong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Ice.hpp"

#include "ICharacter.hpp"

Ice::Ice(void) : AMateria("ice") {}
Ice::Ice(const Ice& other) : AMateria(other) {}
Ice::~Ice() {}
Ice& Ice::operator=(const Ice& other) {
  AMateria::operator=(other);
  return *this;
}

AMateria* Ice::clone() const { return (new Ice(*this)); }

void Ice::use(ICharacter& target) {
  std::cout << "* shoots an ice bolt at " << target.getName() << " *"
            << std::endl;
}