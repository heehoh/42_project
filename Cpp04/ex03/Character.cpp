/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hujeong <hujeong@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/02 20:13:53 by hujeong           #+#    #+#             */
/*   Updated: 2023/09/03 17:16:39 by hujeong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Character.hpp"

#include "Cure.hpp"
#include "Ice.hpp"

Character::Character(void) {
  std::cout << "기본 생성자는 호출되지 않습니다." << std::endl;
}

Character::Character(const Character& other) : name(other.name) {
  for (int i = 0; i < 4; i++) {
    if (other.inventory[i])
      this->inventory[i] = other.inventory[i]->clone();
    else
      this->inventory[i] = NULL;
    if (other.trash[i])
      this->trash[i] = other.trash[i]->clone();
    else
      this->trash[i] = NULL;
  }
}

Character& Character::operator=(const Character& other) {
  for (int i = 0; i < 4; i++) {
    if (this->inventory[i]) delete this->inventory[i];
    if (this->trash[i]) delete this->trash[i];
  }
  this->name = other.name;
  for (int i = 0; i < 4; i++) {
    if (other.inventory[i])
      this->inventory[i] = other.inventory[i]->clone();
    else
      this->inventory[i] = NULL;
    if (other.trash[i])
      this->trash[i] = other.trash[i]->clone();
    else
      this->trash[i] = NULL;
  }
  return (*this);
}

Character::Character(const std::string& name) : name(name) {
  for (int i = 0; i < 4; i++) {
    this->inventory[i] = NULL;
    this->trash[i] = NULL;
  }
}

Character::~Character(void) {
  for (int i = 0; i < 4; i++) {
    if (this->inventory[i]) delete this->inventory[i];
    if (this->trash[i]) delete this->trash[i];
  }
}

std::string const& Character::getName(void) const { return (this->name); }

void Character::equip(AMateria* m) {
  for (int i = 0; i < 4; i++) {
    if (this->trash[i]) {
      delete this->trash[i];
      this->trash[i] = NULL;
    }
  }
  if (!m) return;
  for (int i = 0; i < 4; i++) {
    if (!this->inventory[i]) {
      this->inventory[i] = m;
      return;
    }
  }
}

void Character::unequip(int idx) {
  if (idx < 0 || idx >= 4 || !this->inventory[idx]) return;
  for (int i = 0; i < 4; i++) {
    if (!this->trash[i]) {
      this->trash[i] = this->inventory[idx];
      this->inventory[idx] = NULL;
      return;
    }
  }
}

void Character::use(int idx, ICharacter& target) {
  if (idx < 0 || idx >= 4 || !this->inventory[idx]) return;
  this->inventory[idx]->use(target);
}