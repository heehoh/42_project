/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hujeong <hujeong@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/26 13:25:04 by hujeong           #+#    #+#             */
/*   Updated: 2023/09/02 11:31:01 by hujeong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLAPTRAP_HPP
#define CLAPTRAP_HPP

#include <iostream>
#include <string>

namespace claptrap {
enum status {
  HP = 10,
  EP = 10,
  AD = 0,
};
}

class ClapTrap {
 public:
  ClapTrap(void);
  ClapTrap(std::string name);
  ClapTrap(const ClapTrap& src);
  ~ClapTrap(void);
  ClapTrap& operator=(const ClapTrap& src);

  void attack(const std::string& target);
  void takeDamage(unsigned int amount);
  void beRepaired(unsigned int amount);

  std::string getName(void) const;
  unsigned int getHitPoints(void) const;
  unsigned int getAttackDamage(void) const;
  unsigned int getEnergyPoints(void) const;

  void setName(std::string name);
  void setHitPoints(unsigned int hitPoints);
  void setEnergyPoints(unsigned int energyPoints);
  void setAttackDamage(unsigned int attackDamage);

  void printStatus(void) const;

 protected:
  std::string name;
  unsigned int hitPoints;
  unsigned int energyPoints;
  unsigned int attackDamage;
};

#endif