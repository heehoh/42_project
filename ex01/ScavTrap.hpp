/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hujeong <hujeong@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/26 15:31:34 by hujeong           #+#    #+#             */
/*   Updated: 2023/08/26 19:32:59 by hujeong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCAVTRAP_HPP
#define SCAVTRAP_HPP

#include "ClapTrap.hpp"

enum {
  S_HP = 100,
  S_EP = 50,
  S_AD = 20,
};

class ScavTrap : public ClapTrap {
  public:
    ScavTrap(void);
    ScavTrap(std::string name);
    ScavTrap(const ScavTrap& src);
    ~ScavTrap(void);
    ScavTrap& operator=(const ScavTrap& src);

    void attack(std::string name);
    void guardGate(void);
};

#endif