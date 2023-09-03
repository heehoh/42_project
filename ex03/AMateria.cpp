/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hujeong <hujeong@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/02 18:06:06 by hujeong           #+#    #+#             */
/*   Updated: 2023/09/03 17:28:21 by hujeong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AMateria.hpp"

#include "ICharacter.hpp"

AMateria::AMateria(void) {}

AMateria::AMateria(std::string const& type) : type(type) {}

AMateria::AMateria(const AMateria& other) : type(other.getType()) {}

AMateria::~AMateria(void) {}

AMateria& AMateria::operator=(const AMateria& other) {
  std::cout << "머터리어의 타입 " << this->type << "은(는) " << other.type
            << "으로 "
            << "바꿀 수 없습니다." << std::endl;
  return *this;
}

std::string const& AMateria::getType(void) const { return type; }

void AMateria::use(ICharacter& target) {
  std::cout << "* uses " << type << " at " << target.getName() << " *"
            << std::endl;
}