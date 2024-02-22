/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hujeong <hujeong@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/02 20:18:38 by hujeong           #+#    #+#             */
/*   Updated: 2023/09/03 17:22:37 by hujeong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MateriaSource.hpp"

#include "AMateria.hpp"

MateriaSource::MateriaSource(void) {
  for (int i = 0; i < 4; i++) this->materias[i] = NULL;
}

MateriaSource::MateriaSource(const MateriaSource& other) {
  for (int i = 0; i < 4; i++) {
    if (other.materias[i])
      this->materias[i] = other.materias[i]->clone();
    else
      this->materias[i] = NULL;
  }
}

MateriaSource::~MateriaSource(void) {
  for (int i = 0; i < 4; i++) {
    if (this->materias[i]) delete this->materias[i];
  }
}

MateriaSource& MateriaSource::operator=(const MateriaSource& other) {
  for (int i = 0; i < 4; i++) {
    if (this->materias[i]) delete this->materias[i];
  }
  for (int i = 0; i < 4; i++) {
    if (other.materias[i])
      this->materias[i] = other.materias[i]->clone();
    else
      this->materias[i] = NULL;
  }
  return (*this);
}

void MateriaSource::learnMateria(AMateria* materia) {
  for (int i = 0; i < 4; i++) {
    if (!this->materias[i]) {
      this->materias[i] = materia;
      return;
    }
  }
}

AMateria* MateriaSource::createMateria(std::string const& type) {
  for (int i = 0; i < 4; i++) {
    if (this->materias[i] && this->materias[i]->getType() == type)
      return (this->materias[i]->clone());
  }
  return (NULL);
}