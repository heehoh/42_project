/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hujeong <hujeong@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/11 21:12:42 by hujeong           #+#    #+#             */
/*   Updated: 2023/10/11 21:47:18 by hujeong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERN_HPP
#define INTERN_HPP

#include <string>

class AForm;

class Intern {
 private:
  AForm* makeShrubberyCreationForm(const std::string& name,
                                   const std::string& target);
  AForm* makeRobotomyRequestForm(const std::string& name,
                                 const std::string& target);
  AForm* makePresidentialPardonForm(const std::string& name,
                                    const std::string& target);
  class MakeFormException : public std::exception {
   public:
    virtual const char* what() const throw();
  };

 public:
  Intern();
  Intern(const Intern& other);
  Intern& operator=(const Intern& other);
  ~Intern();

  AForm* makeForm(const std::string& name, const std::string& target);
};

#endif