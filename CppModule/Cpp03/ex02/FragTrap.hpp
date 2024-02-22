/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hujeong <hujeong@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/02 11:33:22 by hujeong           #+#    #+#             */
/*   Updated: 2023/09/02 14:10:39 by hujeong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRAGTRAP_HPP
#define FRAGTRAP_HPP

#include "ClapTrap.hpp"

namespace fragtrap {
enum status {
  HP = 100,
  EP = 100,
  AD = 30,
};
}

class FragTrap : public ClapTrap {
 public:
  FragTrap(void);
  FragTrap(std::string name);
  FragTrap(const FragTrap& src);
  ~FragTrap(void);
  FragTrap& operator=(const FragTrap& src);

  void highFivesGuys(void);
};

#endif