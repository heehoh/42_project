/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hujeong <hujeong@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/11 21:12:42 by hujeong           #+#    #+#             */
/*   Updated: 2023/10/14 15:41:23 by hujeong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERN_HPP
#define INTERN_HPP

#include <string>

class AForm;

class Intern {
 private:
  Intern(const Intern&);
  Intern& operator=(const Intern&);

 public:
  Intern();
  ~Intern();

  AForm* makeForm(const std::string& name, const std::string& target);
};

#endif