/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hujeong <hujeong@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/04 19:57:10 by hujeong           #+#    #+#             */
/*   Updated: 2023/10/05 11:22:54 by hujeong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
#define FORM_HPP

#include <string>

class Form {
 private:
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
  Form();
  Form(const Form& other);
  Form& operator=(const Form& other);

 public:
  Form(const std::string& name, int& gradeToSign, int& gradeToExec);
  ~Form();
  const std::string& getName() const;
  const bool& getSigned() const;
  const int& getGradeToSign() const;
  const int& getGradeToExec() const;
};

std::ostream& operator<<(std::ostream& os, const Form& form);

#endif