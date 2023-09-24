/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hujeong <hujeong@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/26 15:31:34 by hujeong           #+#    #+#             */
/*   Updated: 2023/09/24 19:33:44 by hujeong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCAVTRAP_HPP
#define SCAVTRAP_HPP

#include "ClapTrap.hpp"

namespace scavtrap {
enum status {
  HP = 100,
  EP = 50,
  AD = 20,
};
}

class ScavTrap : virtual public ClapTrap {
 public:
  ScavTrap(void);
  ScavTrap(std::string name);
  ScavTrap(const ScavTrap& src);
  ~ScavTrap(void);
  ScavTrap& operator=(const ScavTrap& src);

  void attack(const std::string& target);
  void guardGate(void);
};

#endif