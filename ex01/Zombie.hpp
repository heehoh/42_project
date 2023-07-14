/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hujeong <hujeong@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/15 00:46:15 by hujeong           #+#    #+#             */
/*   Updated: 2023/07/15 01:21:20 by hujeong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_HPP
#define ZOMBIE_HPP

#include <string>

class Zombie {
 public:
  Zombie(void);
  Zombie(std::string name);
  ~Zombie(void);
  void anounce(void);
  void setName(std::string name);

 private:
  std::string _name;
};

Zombie *newZombie(std::string name);
void randomChump(std::string name);

#endif