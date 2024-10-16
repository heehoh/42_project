/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hujeong <hujeong@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/17 06:42:22 by hujeong           #+#    #+#             */
/*   Updated: 2023/08/12 22:10:38 by hujeong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HARL_HPP
#define HARL_HPP

#include <string>

class Harl {
 public:
  void complain(std::string level);
  Harl();

 private:
  void debug(void);
  void info(void);
  void warning(void);
  void error(void);
  void (Harl::*_func[4])(void);
};

#endif