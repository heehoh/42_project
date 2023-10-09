/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hujeong <hujeong@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/09 15:11:45 by hujeong           #+#    #+#             */
/*   Updated: 2023/10/09 20:11:17 by hujeong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <string>

class Form;

class Bureaucrat {
 private:
  const std::string name_;
  int grade_;
  class GradeTooLowException : public std::exception {
   public:
    virtual const char* what() const throw();
  };
  class GradeTooHighException : public std::exception {
   public:
    virtual const char* what() const throw();
  };
  Bureaucrat();
  Bureaucrat(const Bureaucrat& other);
  Bureaucrat& operator=(const Bureaucrat& other);

 public:
  Bureaucrat(const std::string& name, int grade);
  ~Bureaucrat();

  const std::string& getName() const;
  int getGrade() const;

  void incrementGrade();
  void decrementGrade();
  void signForm(Form& form);
  
};

std::ostream& operator<<(std::ostream& os, const Bureaucrat& bureaucrat);

#endif