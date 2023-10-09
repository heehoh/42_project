/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hujeong <hujeong@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/04 19:57:10 by hujeong           #+#    #+#             */
/*   Updated: 2023/10/09 09:29:31 by hujeong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
#define FORM_HPP

#include <string>

class Bureaucrat;

class AForm {
 protected:
  const std::string name_;
  bool signed_;
  const int gradeToSign_;
  const int gradeToExec_;
  class GradeTooHighException : public std::exception {
   public:
    virtual const char* what() const throw();
  };
  class GradeTooLowException : public std::exception {
   public:
    virtual const char* what() const throw();
  };
  AForm();
  AForm(const AForm& other);
  AForm& operator=(const AForm& other);

 public:
  AForm(const std::string& name, int gradeToSign, int gradeToExec);
  virtual ~AForm();
  const std::string& getName() const;
  const bool& getSigned() const;
  const int& getGradeToSign() const;
  const int& getGradeToExec() const;
  void beSigned(const Bureaucrat& bureaucrat);
  virtual void execute(Bureaucrat const& executor) const = 0;
};

std::ostream& operator<<(std::ostream& os, const AForm& form);

#endif