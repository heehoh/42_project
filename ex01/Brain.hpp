/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hujeong <hujeong@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/02 17:01:03 by hujeong           #+#    #+#             */
/*   Updated: 2023/09/02 17:06:47 by hujeong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BRAIN_HPP
#define BRAIN_HPP
#include <iostream>

class Brain {
 public:
  Brain(void);
  Brain(const Brain& copy);
  virtual ~Brain(void);

  virtual Brain& operator=(const Brain& src);
  std::string getIdea(int index) const;

 protected:
  std::string ideas[100];
};

#endif