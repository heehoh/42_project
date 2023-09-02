/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hujeong <hujeong@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/02 12:12:05 by hujeong           #+#    #+#             */
/*   Updated: 2023/09/02 12:27:07 by hujeong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DIAMONDTRAP_HPP
#define DIAMONDTRAP_HPP

#include "FragTrap.hpp"
#include "ScavTrap.hpp"

class DiamondTrap : public FragTrap, public ScavTrap {
 public:
  DiamondTrap(void);
  DiamondTrap(std::string name);
  DiamondTrap(const DiamondTrap& src);
  DiamondTrap& operator=(const DiamondTrap& src);
  ~DiamondTrap(void);

  void whoAmI(void);

 private:
  std::string name;
};

#endif