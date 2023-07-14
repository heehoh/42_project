/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hujeong <hujeong@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/10 22:47:36 by hujeong           #+#    #+#             */
/*   Updated: 2023/07/15 00:38:23 by hujeong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>

class Zombie {
 public:
  Zombie(std::string name);
  ~Zombie(void);
  void anounce(void);

 private:
  std::string _name;
};

Zombie *newZombie(std::string name);
void randomChump(std::string name);
