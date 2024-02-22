/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hujeong <hujeong@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/15 00:46:15 by hujeong           #+#    #+#             */
/*   Updated: 2023/07/15 08:50:58 by hujeong          ###   ########.fr       */
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

#endif