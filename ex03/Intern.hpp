/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hujeong <hujeong@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/11 21:12:42 by hujeong           #+#    #+#             */
/*   Updated: 2023/10/12 12:07:31 by hujeong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERN_HPP
#define INTERN_HPP

#include <string>

class AForm;

class Intern {
 private:
  Intern(const Intern& other);
  Intern& operator=(const Intern& other);
  class MakeFormException : public std::exception {
   public:
    virtual const char* what() const throw();
  };

 public:
  Intern();
  ~Intern();

  AForm* makeForm(const std::string& name, const std::string& target);
};

#endif